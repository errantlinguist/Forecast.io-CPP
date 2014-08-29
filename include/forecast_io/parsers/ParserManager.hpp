#ifndef PARSERMANAGER_HPP
#define PARSERMANAGER_HPP

#include "../../common/Notifier.hpp" // Base class: Notifier

#include "../factories/AlertFactory.hpp"
#include "../factories/FlagsFactory.hpp"
#include "../factories/SynchronicDataPointDetailsSetter.hpp"
#include "AlertsFactoryParser.hpp"
#include "FlagsFactoryParser.hpp"
#include "NotifyingAlertParser.hpp"
#include "NotifyingForecastParser.hpp"
#include "NotifyingSynchronicDataPointParser.hpp"

namespace forecast_io
{

// Forward declarations
namespace factories
{
class ForecastFactory;
}

namespace parsers
{

class ParserManager: public common::Notifier<listeners::ForecastDetailsListener>
{
public:
    ParserManager(factories::ForecastFactory& listener, factories::FlagsFactory& flagsFactory);
    virtual ~ParserManager();

    // Constant getters -----------------------------------------------------
    const NotifyingAlertParser& getNotifyingAlertParser() const
    {
        return alertParser;
    }

    const AlertsFactoryParser& getAlertsParser() const
    {
        return alertsParser;
    }

    const NotifyingSynchronicDataPointParser& getSynchronicDataPointParser() const
    {
        return synchronicDataPointParser;
    }

    const NotifyingForecastParser& getForecastParser() const
    {
        return forecastParser;
    }

    // Non-constant getters -----------------------------------------------------
    NotifyingAlertParser& getNotifyingAlertParser()
    {
        return alertParser;
    }

    AlertsFactoryParser& getAlertsParser()
    {
        return alertsParser;
    }

    NotifyingSynchronicDataPointParser& getSynchronicDataPointParser()
    {
        return synchronicDataPointParser;
    }

    NotifyingForecastParser& getForecastParser()
    {
        return forecastParser;
    }

private:

    factories::AlertFactory alertFactory;
    NotifyingAlertParser alertParser;
    AlertsFactoryParser alertsParser;
    FlagsFactoryParser flagsParser;
    NotifyingSynchronicDataPointParser synchronicDataPointParser;
    NotifyingForecastParser forecastParser;

};

}
}

#endif // PARSERMANAGER_HPP
