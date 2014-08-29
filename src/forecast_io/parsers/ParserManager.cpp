#include "forecast_io/parsers/ParserManager.hpp"

#include "forecast_io/factories/ForecastFactory.hpp"

namespace forecast_io
{
namespace parsers
{

// Con-/destructors -------------------------------------------------------------

ParserManager::ParserManager(factories::ForecastFactory& listener, factories::FlagsFactory& flagsFactory) :
    Notifier(listener),
    alertParser(alertFactory),
    alertsParser(listener, alertParser, alertFactory),
    flagsParser(listener, flagsFactory),
    synchronicDataPointParser(listener.getCurrentWeatherDetailsSetter()),
    forecastParser(listener, alertsParser, flagsParser, synchronicDataPointParser)
{
}

ParserManager::~ParserManager()
{

}

}
}
