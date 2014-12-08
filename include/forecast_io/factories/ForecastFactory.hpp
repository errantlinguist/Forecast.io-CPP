#ifndef FORECASTFACTORY_HPP
#define FORECASTFACTORY_HPP

#include "../../common/AbstractFactory.hpp" // Base class: AbstractFactory
#include "../listeners/AlertsListener.hpp" // Base class: forecast_io::listeners::AlertsListener
#include "../listeners/FlagsListener.hpp" // Base class: forecast_io::listeners::FlagsListener
#include "../listeners/ForecastDetailsListener.hpp" // Base class: forecast_io::listeners::ForecastDetailsListener
//#include "../listeners/CurrentWeatherListener.hpp" // Base class: forecast_io::listeners::CurrentWeatherListener

#include <memory>
#include <string>

#include "SynchronicDataPointDetailsSetter.hpp"
#include "../../math/MeasurementSystem.hpp"


namespace forecast_io
{

// Forward declarations
class Alert;
class Flags;
class Forecast;

namespace factories
{

class ForecastFactory: public common::AbstractFactory<std::unique_ptr<Forecast>>,
		public forecast_io::listeners::AlertsListener,
		public forecast_io::listeners::ForecastDetailsListener,
		public forecast_io::listeners::FlagsListener
{

public:

	ForecastFactory(math::MeasurementSystem defaultUnits) noexcept;

	virtual void notifyAlert(Alert& alert);
	virtual void notifyCurrentWeather(SynchronicDataPoint& dataPoint);
	virtual void notifyFlags(Flags& flags);
	virtual void notifyLatitude(double latitude);
	virtual void notifyLongitude(double longitude);
	virtual void notifyOffset(signed char offset);
	virtual void notifyTimezone(const std::string& timezone);

	void clear();

	std::unique_ptr<Forecast> create();

	math::MeasurementSystem getDefaultUnits() const
	{
		return defaultUnits;
	}

	void setDefaultUnits(math::MeasurementSystem defaultUnits)
	{
		this->defaultUnits = defaultUnits;
	}

	SynchronicDataPointDetailsSetter& getCurrentWeatherDetailsSetter()
	{
		return currentWeatherDetailsSetter;
	}

	const SynchronicDataPointDetailsSetter& getCurrentWeatherDetailsSetter() const
	{
		return currentWeatherDetailsSetter;
	}

private:

	ForecastFactory(math::MeasurementSystem defaultUnits, std::unique_ptr<Forecast> instance) noexcept;

	SynchronicDataPointDetailsSetter currentWeatherDetailsSetter;
	math::MeasurementSystem defaultUnits;
	std::unique_ptr<Forecast> result;

};

}
}

#endif // FORECASTFACTORY_HPP
