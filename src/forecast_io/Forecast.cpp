#include "forecast_io/Forecast.hpp"

#include <sstream>

#include "common/to_string.hpp"

namespace forecast_io
{

Forecast::Forecast(Flags flags) : Forecast(flags, std::vector<Alert>(), math::Coordinate(), time_offset_t(0), "")
{
}

Forecast::Forecast(Flags flags, std::vector<Alert> alerts, math::Coordinate location, time_offset_t offset, std::string timezone) :
		alerts(alerts), flags(flags), location(location), offset(offset), timezone(timezone)
{
}

Forecast::Forecast(const Forecast& copyee) :
Forecast(
	copyee.getFlags(),
	copyee.getAlerts(),
	copyee.getLocation(),
	copyee.getOffset(),
	copyee.getTimezone())
{
}

Forecast::~Forecast()
{

}

Forecast& Forecast::operator= (const Forecast& other)
{
	if (this != &other) // protect against invalid self-assignment
	{
		this->flags = other.getFlags();
		this->alerts = other.getAlerts();
		this->location = other.getLocation();
		this->offset = other.getOffset();
		this->timezone = other.getTimezone();
	}
	// by convention, always return *this
	return *this;
}

std::ostream& Forecast::dump(std::ostream& o) const
{
	o << "Forecast[getLocation()=";
	const math::Coordinate location(getLocation());
	const std::string locationStr = std::to_string(location);
	o << locationStr;
	o << ", getTimezone()=";
	o << common::to_quoted_string(getTimezone());
	o << ", getOffset()=";
	const short offsetNumericValue = static_cast<const short>(getOffset());
	o << common::to_quoted_string(offsetNumericValue);
	o << ", getAlerts()=";
	const std::string alertsStr = common::to_collection_string(
			getAlerts());
	o << alertsStr;
	o << ", getFlags()=";
	const std::string flagsStr = common::to_quoted_string(getFlags());
	o << flagsStr;
	o << ']';

	return o;
}

std::string Forecast::str() const
{
	std::stringstream ss(std::stringstream::out);
	dump(ss);
	return ss.str();

}

}

namespace std
{

string to_string(const forecast_io::Forecast& value)
{
	return value.str();
}

}

std::ostream& operator<<(std::ostream& o, const forecast_io::Forecast& value)
{
	return value.dump(o);
}

