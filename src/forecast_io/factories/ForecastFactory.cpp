#include "forecast_io/factories/ForecastFactory.hpp"

#include "forecast_io/Alert.hpp"
#include "forecast_io/Flags.hpp"
#include "forecast_io/Forecast.hpp"

namespace forecast_io
{
namespace factories
{

ForecastFactory::ForecastFactory(math::MeasurementSystem defaultUnits) : ForecastFactory(defaultUnits, std::unique_ptr<Forecast>(new Forecast(defaultUnits)))
{

}

ForecastFactory::ForecastFactory(math::MeasurementSystem defaultUnits, std::unique_ptr<Forecast> instance) :
	currentWeatherDetailsSetter(instance->getCurrentWeather()),
	defaultUnits(defaultUnits),
	result(std::move(instance))
{

}

void ForecastFactory::clear()
{
	result.reset(new Forecast(defaultUnits));
}

std::unique_ptr<Forecast> ForecastFactory::create()
{
	return std::move(result);
}

// AlertsListener ---------------------------------------------------------------

void ForecastFactory::notifyAlert(Alert& alert)
{
//	result->setAlerts(alerts);
	std::vector<Alert>& alerts = result->getAlerts();
	alerts.push_back(alert);
}

// CurrentWeatherListener -------------------------------------------------------

void ForecastFactory::notifyCurrentWeather(SynchronicDataPoint& dataPoint)
{
	// TODO: set current weather in forecast object
}

// FlagsListener ----------------------------------------------------------------

void ForecastFactory::notifyFlags(Flags& flags)
{
	result->setFlags(flags);
}

// ForecastDetailsListener ------------------------------------------------------

void ForecastFactory::notifyLatitude(double latitude)
{
	math::Coordinate& location = result->getLocation();
	location.setLatitude(latitude);
}

void ForecastFactory::notifyLongitude(double longitude)
{
	math::Coordinate& location = result->getLocation();
	location.setLongitude(longitude);
}

void ForecastFactory::notifyOffset(signed char offset)
{
	result->setOffset(offset);
}

void ForecastFactory::notifyTimezone(const std::string& timezone)
{
	result->setTimezone(timezone);
}

}
}

