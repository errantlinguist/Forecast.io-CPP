#include "forecast_io/parsers/AlertsFactoryParser.hpp"

#include "forecast_io/Alert.hpp"
#include "forecast_io/factories/AlertFactory.hpp"
#include "forecast_io/listeners/AlertsListener.hpp"
#include "forecast_io/parsers/NotifyingAlertParser.hpp"

namespace forecast_io
{

namespace parsers
{

AlertsFactoryParser::AlertsFactoryParser(listeners::AlertsListener* pListener,
        NotifyingAlertParser& alertParser,
        factories::AlertFactory* pFactory) :
    JsonArrayParser(alertParser), Notifier(pListener), factory(
        *pFactory)
{
    getElementParser().getListeners().insert(pFactory);
}

void AlertsFactoryParser::handleArrayElement(json_object* const & arrayElement)
{
    json::JsonArrayParser<NotifyingAlertParser>::handleArrayElement(arrayElement);
    Alert alert = factory.create();
    for (listeners::AlertsListener* const & pListener : getListeners())
    {
        pListener->notifyAlert(alert);
    }
}

}

}

