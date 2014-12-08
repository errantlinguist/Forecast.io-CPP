#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <memory>
#include <regex>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>

#include "common/SysExit.hpp"
#include "console/dimensions.hpp"
#include "console_weather/ForecastServiceClient.hpp"
#include "console_weather/ForecastStreamReader.hpp"
#include "console_weather/writers/ForecastConsoleWriter.hpp"
#include "curl/CallbackClient.hpp"
#include "forecast_io/Flags.hpp"
#include "forecast_io/Forecast.hpp"
#include "forecast_io/factories/ForecastFactory.hpp"
#include "forecast_io/parsers/NotifyingAlertParser.hpp"
#include "forecast_io/parsers/NotifyingFlagParser.hpp"
#include "forecast_io/parsers/NotifyingForecastParser.hpp"
#include "forecast_io/parsers/ParserManager.hpp"
#include "json/TokenerParser.hpp"
#include "json/ParseError.hpp"

static constexpr math::MeasurementSystem DEFAULT_MEASUREMENT_UNITS = math::MeasurementSystem::SI;
static constexpr int DEFAULT_READ_BUFFER_SIZE = 64 * 1024;
static constexpr const char* const & DEFAULT_URL_GETTER_ERROR_MESSAGE = "An error occurred while getting the given URL.";
static const std::regex VALID_CONTENT_TYPE_REGEX(".+?/json", std::regex_constants::icase | std::regex_constants::optimize);

static void printCurlErrorMessage(const char* const& pCurlErrorMessage)
{
	if (std::strcmp(pCurlErrorMessage, "") == 0)
	{
		std::cerr << DEFAULT_URL_GETTER_ERROR_MESSAGE << std::endl;
	} else
	{
		std::cerr << "An error occurred while getting the given URL: " << pCurlErrorMessage << std::endl;
	}
}

static std::string createJsonParseErrorMessage(const std::exception& e)
{
	std::stringstream errorMessage(std::stringstream::out);
	errorMessage << "There was an error parsing the server response as JSON: ";
	errorMessage << e.what() << std::endl;
	return errorMessage.str();
}

static std::string createUsageMessage(const char* const& pExecutableName)
{
	std::stringstream ss(std::stringstream::out);
	ss << "Usage: " << pExecutableName << " [INFILE_PATH|URL]" << std::endl;
	return ss.str();
}

static bool isLastResponseContentInvalid(const curl::CallbackClient& curlClient, char* const& pInfoBuffer)
{
	bool result(false);

	CURLcode infoGetterCode = curlClient.getInfo(CURLINFO_CONTENT_TYPE, pInfoBuffer);
	if (CURLE_OK == infoGetterCode && pInfoBuffer != NULL)
	{
		const std::string infoType(pInfoBuffer);
		std::smatch jsonMatch;
		result = (!std::regex_match(infoType, jsonMatch, VALID_CONTENT_TYPE_REGEX));
	}

	return result;
}

static void print(forecast_io::Forecast& forecast)
{
	const console::Dimensions consoleDimensions = console::getDimensions();
	console_weather::writers::ForecastConsoleWriter forecastWriter(consoleDimensions.width);
	forecastWriter.write(forecast, std::cout);
}

static int readJsonStream(std::istream& input)
{
	int result(EXIT_FAILURE);

	console_weather::ForecastStreamReader forecastReader(DEFAULT_MEASUREMENT_UNITS, DEFAULT_READ_BUFFER_SIZE);
	try {
		std::unique_ptr<forecast_io::Forecast> pForecast = forecastReader.read(input);
		if (pForecast == nullptr)
		{
			std::cerr << DEFAULT_URL_GETTER_ERROR_MESSAGE << std::endl;
			result = common::getSysExitCode(common::SysExit::IO_DEVICE_ERROR);
		} else
		{
			print(*pForecast);
			result = EXIT_SUCCESS;
		}
	} catch(const json::ParseError& e)
	{
		std::cerr << createJsonParseErrorMessage(e) << std::endl;
	}

	return EXIT_SUCCESS;
}

static int readUrl(const char* pUrl)
{
	int result(EXIT_FAILURE);

	// Initialise cURL
	CURLcode initCode(curl_global_init(CURL_GLOBAL_DEFAULT));
	if (CURLE_OK == initCode)
	{
		try {
			std::unique_ptr<char[]> pErrorBuffer(new char[CURL_ERROR_SIZE]); // The buffer to which cURL handle error messages are written
			curl::CallbackClient curlClient(pErrorBuffer.get());
			curlClient.addHeader("Accept: application/json, text/json");
			try {
				console_weather::ForecastServiceClient forecastClient(curlClient, DEFAULT_MEASUREMENT_UNITS);
				std::unique_ptr<forecast_io::Forecast> pForecast = forecastClient.get(pUrl);
				if (pForecast == nullptr)
				{
					printCurlErrorMessage(pErrorBuffer.get());
					result = common::getSysExitCode(common::SysExit::HOST_UNAVAILABLE);
				} else
				{
					print(*pForecast);
					result = EXIT_SUCCESS;
				}
			} catch (const CURLcode& getterCode)
			{
				const char* pCurlErrorMessage = pErrorBuffer.get();
				if (std::strcmp(pCurlErrorMessage, "") == 0)
				{
					pCurlErrorMessage = curl_easy_strerror(getterCode);
				}
				printCurlErrorMessage(pCurlErrorMessage);
				result = common::getSysExitCode(common::SysExit::INTERNAL_ERROR);
			} catch (const json::ParseError& e)
			{
				std::cerr << createJsonParseErrorMessage(e) << std::endl;

				// Check if an invalid content type was returned by the server
				char* pInfoBuffer = NULL;
				if (isLastResponseContentInvalid(curlClient, pInfoBuffer))
				{
					std::cerr << "The response content type was expected to be JSON but was \"" << pInfoBuffer << "\" instead." << std::endl;
				}
			}
		} catch (const CURLcode& handleInitCode)
		{
			printCurlErrorMessage(curl_easy_strerror(handleInitCode));
			result = common::getSysExitCode(common::SysExit::INTERNAL_ERROR);
		}

		// De-initialise cURL
		curl_global_cleanup();
	} else
	{
		const char* pCurlErrorMessage = curl_easy_strerror(initCode);
		std::cerr << "An error occurred while initialising the cURL library: " << pCurlErrorMessage << std::endl;
		result = common::getSysExitCode(common::SysExit::INTERNAL_ERROR);
	}

	return result;
}

int main(int argc, char** argv)
{
	int result(EXIT_FAILURE);

	if(argc > 2)
	{
		std::cerr << createUsageMessage(argv[0]);
		result = common::getSysExitCode(common::SysExit::INVALID_COMMAND_LINE);
	}
	else if(argc > 1)
	{
		const char* const& input = argv[1];
		std::ifstream infile(input);
		if(infile)
		{
			std::cerr << "Reading from file path \"" << input
					  << "\"..." << std::endl;
			result = readJsonStream(infile);
		}
		else
		{
			std::cerr << "Reading from URL \"" << input
					  << "\"..." << std::endl;
			result = readUrl(input);
		}
		infile.close();
	}
	else
	{
		std::cerr << createUsageMessage(argv[0]);
		result = common::getSysExitCode(common::SysExit::INVALID_COMMAND_LINE);
	}

	return result;
}

//int main(int argc, char **argv)
//{
//	// If the input is coming from a terminal rather than from a pipe,
//	if(isatty(STDIN_FILENO))
//	{
//		return main_curl(argc, argv);
//	} else {
//		std::cerr << "Reading from standard input..." << std::endl;
//		return main_parseJsonStream(std::cin);
////		return main_instream(argc, argv);
//	}
//}
