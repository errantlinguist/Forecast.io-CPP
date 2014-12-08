#include "console_weather/ForecastServiceClient.hpp"

#include <limits>

#include "curl/CallbackClient.hpp"
#include "forecast_io/Forecast.hpp"
#include "forecast_io/factories/FlagsFactory.hpp"
#include "forecast_io/factories/ForecastFactory.hpp"
#include "forecast_io/parsers/ParserManager.hpp"
#include "json/TokenerParser.hpp"

namespace console_weather
{

static constexpr size_t MAX_PARSER_INPUT_SIZE = static_cast<size_t>(std::numeric_limits<int>::max());

/**
 * Callback function for <a href="http://curl.haxx.se/libcurl/c/CURLOPT_WRITEFUNCTION.html">CURLOPT_WRITEFUNCTION</a> which incrementally parses the data with LibJSON.
 *
 * @param[in] readBuffer The buffer to read from. NOTE: Is not null-terminated.
 * @param[in] size The byte size of each element in the buffer.
 * @param[in] nmemb The number of elements in the buffer.
 * @param[out] pUserData A pointer to an output data structure.
 *
 * @return The amount of bytes processed.
 * @throw json::ParseException If there was an error while parsing the input as JSON.
 * @throw std::out_of_range If the amount of bytes to read (i.e. size * nmemb) overflows the parameter type for the JSON parser input.
 **/
static size_t parseJson(char* readBuffer, size_t size, size_t nmemb,
                        void* pUserData)
{
    size_t result(0);
    if(pUserData)
    {
        json::TokenerParser* const pTokenerParser =
            static_cast<json::TokenerParser*>(pUserData);
        // Calculate the amount of bytes to be parsed
        result = size * nmemb;
        // Check that the size does not overflow as an int type
        if(result <= MAX_PARSER_INPUT_SIZE)
        {
			const int inputSize = static_cast<int>(result);
            pTokenerParser->parse(readBuffer, inputSize);
        }
        else
        {
            throw std::out_of_range("Amount of bytes to read cannot be stored as an int.");
        }

    }

    return result;
}

ForecastServiceClient::ForecastServiceClient(curl::CallbackClient& curlClient, math::MeasurementSystem measurementUnits)  noexcept : curlClient(curlClient), measurementUnits(measurementUnits)
{
    //ctor
}

std::unique_ptr<forecast_io::Forecast> ForecastServiceClient::get(const char* url)
{
    // Create parsers
    std::unique_ptr<forecast_io::factories::ForecastFactory> pForecastFactory(
        new forecast_io::factories::ForecastFactory(measurementUnits));
    std::unique_ptr<forecast_io::factories::FlagsFactory> pFlagsFactory(
        new forecast_io::factories::FlagsFactory(measurementUnits));
    std::unique_ptr<forecast_io::parsers::ParserManager> pParserManager(
        new forecast_io::parsers::ParserManager(pForecastFactory.get(), pFlagsFactory.get()));

    forecast_io::parsers::NotifyingForecastParser& forecastParser =
        pParserManager->getForecastParser();
    json::TokenerParser tokenerParser(forecastParser);
    const CURLcode responseCode =
        curlClient.read(
            url,
            parseJson, &tokenerParser);

    std::unique_ptr<forecast_io::Forecast> result = nullptr;
    if (CURLE_OK == responseCode)
    {
        result = pForecastFactory->create();
    }
    else
    {
		throw responseCode;
    }
    return result;
}

}
