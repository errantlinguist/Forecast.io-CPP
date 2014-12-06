#include "console_weather/ForecastServiceClient.hpp"

#include "../curl/CallbackClient.hpp"
#include "../forecast_io/Forecast.hpp"
#include "../forecast_io/factories/FlagsFactory.hpp"
#include "../forecast_io/factories/ForecastFactory.hpp"
#include "../forecast_io/parsers/ParserManager.hpp"
#include "../json/TokenerParser.hpp"

namespace console_weather
{

/**
 * Callback function for CURLOPT_WRITEFUNCTION which incrementally parses the data with LibJSON.
 *
 * @param[in] readBuffer The buffer to read from. NOTE: Is not null-terminated.
 * @param[in] size The byte size of each element in the buffer.
 * @param[in] nmemb The number of elements in the buffer.
 * @param[out] pUserdata A pointer to an output data structure.
 *
 * @return The amount of bytes processed.
 **/
static size_t parseJson(char* readBuffer, size_t size, size_t nmemb,
                        void* pUserdata)
{
    size_t result(0);
    if(pUserdata)
    {
        json::TokenerParser* const pTokenerParser =
            static_cast<json::TokenerParser*>(pUserdata);
        // Calculate the amount of bytes to be parsed
        result = size * nmemb;
        const int inputSize = static_cast<int>(result);
        const size_t recastResult = static_cast<size_t>(inputSize);
        if(recastResult == result)
        {
            pTokenerParser->parse(readBuffer, inputSize);
        }
        else
        {
            throw std::out_of_range("Amount of bytes to read cannot be stored as an int.");
        }

    }

    return result;
}

ForecastServiceClient::ForecastServiceClient(curl::CallbackClient& curlClient, math::MeasurementSystem measurementUnits) : curlClient(curlClient), measurementUnits(measurementUnits)
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
    curl::CallbackClient::WriteFunction* const writeFunction = parseJson;
    const CURLcode responseCode =
        curlClient.read(
            url,
            writeFunction, &tokenerParser);

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
