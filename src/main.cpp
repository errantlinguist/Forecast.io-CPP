#include <cstdio>
#include <fstream>
#include <iostream>
#include <memory>
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

static std::string createUsageMessage(const char* const& executable)
{
	std::stringstream ss(std::stringstream::out);
	ss << "Usage: " << executable << " [INFILE_PATH|URL]" << std::endl;
	return ss.str();
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
	std::unique_ptr<forecast_io::Forecast> pForecast = forecastReader.read(input);
	if (pForecast == nullptr)
	{
		std::cerr << "An error occurred while reading the input stream." << std::endl;
		result = common::getSysExitCode(common::SysExit::IO_DEVICE_ERROR);
	} else
	{
		print(*pForecast);
		result = EXIT_SUCCESS;
	}

	return EXIT_SUCCESS;
}

static int readUrl(const char* url)
{
	int result(EXIT_FAILURE);

	// Initialise cURL
	curl_global_init(CURL_GLOBAL_DEFAULT);

	try {
		curl::CallbackClient curlClient;
		console_weather::ForecastServiceClient forecastClient(curlClient, DEFAULT_MEASUREMENT_UNITS);
		std::unique_ptr<forecast_io::Forecast> pForecast = forecastClient.get(url);
		if (pForecast == nullptr)
		{
			std::cerr << "An error occurred while getting the given URL." << std::endl;
			result = common::getSysExitCode(common::SysExit::HOST_UNAVAILABLE);
		} else
		{
			print(*pForecast);
			result = EXIT_SUCCESS;
		}
	} catch (const CURLcode& code)
	{
		std::cerr << "An error occurred while initialising the cURL library. Error code: " << code << std::endl;
		result = common::getSysExitCode(common::SysExit::INTERNAL_ERROR);
	}

	// De-initialise cURL
	curl_global_cleanup();

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
