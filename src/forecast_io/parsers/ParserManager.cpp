#include "forecast_io/parsers/ParserManager.hpp"

#include "forecast_io/factories/ForecastFactory.hpp"

namespace forecast_io
{
namespace parsers
{

// Con-/destructors -------------------------------------------------------------

ParserManager::ParserManager(factories::ForecastFactory* pListener, factories::FlagsFactory* pFlagsFactory) :
	ParserManager(pListener, pFlagsFactory, &alertFactory)
{
}

ParserManager::ParserManager(factories::ForecastFactory* pListener, factories::FlagsFactory* pFlagsFactory, factories::AlertFactory* pAlertFactory) :
    Notifier(pListener),
    alertParser(pAlertFactory),
    alertsParser(pListener, alertParser, pAlertFactory),
    flagsParser(pListener, pFlagsFactory),
    synchronicDataPointParser(&pListener->getCurrentWeatherDetailsSetter()),
    forecastParser(pListener, alertsParser, flagsParser, synchronicDataPointParser)
{
}

// Constant getters -----------------------------------------------------
const NotifyingAlertParser& ParserManager::getNotifyingAlertParser() const
{
	return alertParser;
}

const AlertsFactoryParser& ParserManager::getAlertsParser() const
{
	return alertsParser;
}

const NotifyingSynchronicDataPointParser& ParserManager::getSynchronicDataPointParser() const
{
	return synchronicDataPointParser;
}

const NotifyingForecastParser& ParserManager::getForecastParser() const
{
	return forecastParser;
}

// Non-constant getters -----------------------------------------------------
NotifyingAlertParser& ParserManager::getNotifyingAlertParser()
{
	return alertParser;
}

AlertsFactoryParser& ParserManager::getAlertsParser()
{
	return alertsParser;
}

NotifyingSynchronicDataPointParser& ParserManager::getSynchronicDataPointParser()
{
	return synchronicDataPointParser;
}

NotifyingForecastParser& ParserManager::getForecastParser()
{
	return forecastParser;
}

}
}
