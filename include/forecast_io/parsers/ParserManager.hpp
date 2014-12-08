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
    ParserManager(factories::ForecastFactory* pListener, factories::FlagsFactory* pFlagsFactory) noexcept;

    // Constant getters -----------------------------------------------------
    virtual const NotifyingAlertParser& getNotifyingAlertParser() const;

    virtual const AlertsFactoryParser& getAlertsParser() const;

    virtual const NotifyingSynchronicDataPointParser& getSynchronicDataPointParser() const;

    virtual const NotifyingForecastParser& getForecastParser() const;

    // Non-constant getters -----------------------------------------------------
    virtual NotifyingAlertParser& getNotifyingAlertParser();

    virtual AlertsFactoryParser& getAlertsParser();

    virtual NotifyingSynchronicDataPointParser& getSynchronicDataPointParser();

    virtual NotifyingForecastParser& getForecastParser();

private:

	ParserManager(factories::ForecastFactory* pListener, factories::FlagsFactory* pFlagsFactory, factories::AlertFactory* pAlertFactory);

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
