#include "console_weather/ForecastStreamReader.hpp"

#include <cassert>

#include "forecast_io/Forecast.hpp"
#include "forecast_io/factories/FlagsFactory.hpp"
#include "forecast_io/factories/ForecastFactory.hpp"
#include "forecast_io/parsers/ParserManager.hpp"
#include "json/TokenerParser.hpp"

namespace console_weather
{

ForecastStreamReader::ForecastStreamReader(math::MeasurementSystem measurementUnits, int readBufferSize)  noexcept :
    measurementUnits(measurementUnits),
    pBuffer(new char[static_cast<size_t>(readBufferSize)]),
    readBufferSize(readBufferSize)
{
    //ctor
    assert (readBufferSize > -1 && "Read buffer size cannot be negative.");
}

std::unique_ptr<forecast_io::Forecast> ForecastStreamReader::read(std::istream& input)
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
