#include "console_weather/ForecastStreamReader.hpp"

#include "forecast_io/Forecast.hpp"
#include "forecast_io/factories/FlagsFactory.hpp"
#include "forecast_io/factories/ForecastFactory.hpp"
#include "forecast_io/parsers/ParserManager.hpp"
#include "json/TokenerParser.hpp"

namespace console_weather
{

ForecastStreamReader::ForecastStreamReader(math::MeasurementSystem measurementUnits, size_t readBufferSize) :
    measurementUnits(measurementUnits),
    pBuffer(new char[readBufferSize]),
    readBufferSize(readBufferSize)
{
    //ctor
}

std::unique_ptr<forecast_io::Forecast> ForecastStreamReader::read(std::istream& input)
{
    // Create parsers
    std::unique_ptr<forecast_io::factories::ForecastFactory> pForecastFactory(
        new forecast_io::factories::ForecastFactory(measurementUnits));
    std::unique_ptr<forecast_io::factories::FlagsFactory> pFlagsFactory(
        new forecast_io::factories::FlagsFactory(measurementUnits));
    std::unique_ptr<forecast_io::parsers::ParserManager> pParserManager(
        new forecast_io::parsers::ParserManager(*pForecastFactory, *pFlagsFactory));

    forecast_io::parsers::NotifyingForecastParser& forecastParser =
        pParserManager->getForecastParser();
    json::TokenerParser tokenerParser(forecastParser);
    const std::streamsize bytesRead = tokenerParser.parse(input, pBuffer.get(),
                                      readBufferSize);
	std::unique_ptr<forecast_io::Forecast> result = nullptr;
	if (input.eof() && bytesRead > 0)
	{
		result = pForecastFactory->create();
	}

	return result;
}

}
