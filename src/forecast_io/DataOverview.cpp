#include "forecast_io/DataOverview.hpp"

#include <sstream>

#include "common/to_string.hpp"

namespace forecast_io
{

DataOverview::DataOverview(std::string summary, std::string iconName) noexcept : summary(summary), iconName(iconName)
{
}

std::ostream& DataOverview::dump(std::ostream& o) const
{
	o << "DataOverview[getSummary()=";
	o << common::to_quoted_string(getSummary());
	o << ", getIconName()=";
	o << common::to_quoted_string(getIconName());
	o << ']';

	return o;
}

std::string DataOverview::str() const
{
	std::stringstream ss(std::stringstream::out);
	dump(ss);
	return ss.str();

}

}

namespace std
{

string to_string(const forecast_io::DataOverview& value)
{
	return value.str();
}

}

std::ostream& operator<<(std::ostream& o,
		const forecast_io::DataOverview& value)
{
	return value.dump(o);
}

