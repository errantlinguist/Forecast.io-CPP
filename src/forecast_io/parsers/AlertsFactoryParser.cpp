#include "forecast_io/parsers/AlertsFactoryParser.hpp"

#include "forecast_io/Alert.hpp"
#include "forecast_io/factories/AlertFactory.hpp"
#include "forecast_io/listeners/AlertsListener.hpp"
#include "forecast_io/parsers/NotifyingAlertParser.hpp"

namespace forecast_io
{

namespace parsers
{

AlertsFactoryParser::AlertsFactoryParser(listeners::AlertsListener& listener,
		NotifyingAlertParser& alertParser,
		factories::AlertFactory& factory) :
		JsonArrayParser(alertParser), Notifier(listener), factory(
				factory)
{
	getElementParser().setListener(factory);
}

void AlertsFactoryParser::handleArrayElement(json_object* const & arrayElement)
{
	json::JsonArrayParser<NotifyingAlertParser>::handleArrayElement(arrayElement);
	Alert alert = factory.create();
	getListener()->notifyAlert(alert);
}

}

}

