#ifndef FORECAST_HPP
#define FORECAST_HPP

#include <ostream>
#include <string>
#include <utility>
#include <vector>

#include "../math/Coordinate.hpp"
#include "Alert.hpp"
#include "DataBlock.hpp"
#include "Flags.hpp"
#include "SynchronicDataPoint.hpp"

namespace forecast_io
{


class Forecast
{
public:

	// Typedefs
	typedef signed char time_offset_t;

	Forecast(Flags flags) noexcept;
	Forecast(Flags flags, std::vector<Alert> alerts, math::Coordinate location, time_offset_t offset, std::string timezone, SynchronicDataPoint currentWeather, DataBlock minutelyWeather, DataBlock hourlyWeather) noexcept;

	// Constant getters ---------------------------------------------------------
	const std::vector<Alert>& getAlerts() const
	{
		return alerts;
	}

	const SynchronicDataPoint& getCurrentWeather() const
	{
		return currentWeather;
	}

	const DataBlock& getMinutelyWeather() const
	{
		return minutelyWeather;
	}

	const DataBlock& getHourlyWeather() const
	{
		return hourlyWeather;
	}

	const Flags& getFlags() const
	{
		return flags;
	}

	const math::Coordinate& getLocation() const
	{
		return location;
	}

	time_offset_t getOffset() const
	{
		return offset;
	}

	std::string getTimezone() const
	{
		return timezone;
	}

	// Non-constant getters -----------------------------------------------------
	std::vector<Alert>& getAlerts()
	{
		return alerts;
	}

	SynchronicDataPoint& getCurrentWeather()
	{
		return currentWeather;
	}

	DataBlock& getMinutelyWeather()
	{
		return minutelyWeather;
	}

	DataBlock& getHourlyWeather()
	{
		return hourlyWeather;
	}

	Flags& getFlags()
	{
		return flags;
	}

	math::Coordinate& getLocation()
	{
		return location;
	}

	// Setters ------------------------------------------------------------------

	void setAlerts(std::vector<Alert> alerts)
	{
		this->alerts = alerts;
	}

	void setCurrentWeather(SynchronicDataPoint currentWeather)
	{
		this->currentWeather = currentWeather;
	}

	void setMinutelyWeather(DataBlock weather)
	{
		this->minutelyWeather = weather;
	}

	void setHourlyWeather(DataBlock weather)
	{
		this->hourlyWeather = weather;
	}

	void setFlags(Flags flags)
	{
		this->flags = flags;
	}

	void setLocation(math::Coordinate location)
	{
		this->location = location;
	}

	void setOffset(time_offset_t offset)
	{
		this->offset = offset;
	}

	void setTimezone(std::string timezone)
	{
		this->timezone = timezone;
	}

private:


	std::vector<Alert> alerts;
	Flags flags;
	math::Coordinate location;
	time_offset_t offset;
	std::string timezone;

	SynchronicDataPoint currentWeather;
	DataBlock minutelyWeather;
	DataBlock hourlyWeather;

};

}

namespace std
{

string to_string(const forecast_io::Forecast& value);

}

std::ostream& operator<<(std::ostream& o, const forecast_io::Forecast& value);

#endif // FORECAST_HPP
