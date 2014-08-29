#include "forecast_io/DataOverview.hpp"

#include <sstream>

#include "common/to_string.hpp"

namespace forecast_io
{

DataOverview::DataOverview() : DataOverview("", "")
{
}


DataOverview::DataOverview(std::string summary, std::string iconName) : summary(summary), iconName(iconName)
{
}

DataOverview::DataOverview(const DataOverview& copyee) : DataOverview(copyee.getSummary(), copyee.getIconName())
{
}

DataOverview::~DataOverview()
{
}

DataOverview& DataOverview::operator= (const DataOverview& other)
{
	if (this != &other) // protect against invalid self-assignment
	{
		this->summary = other.getSummary();
		this->iconName = other.getIconName();
	}
	// by convention, always return *this
	return *this;
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

