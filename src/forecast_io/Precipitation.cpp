#include "forecast_io/Precipitation.hpp"

#include <sstream>

#include "common/to_string.hpp"

namespace forecast_io
{

Precipitation::Precipitation() :
	Precipitation(0.0, 0.0, "")
{

}

Precipitation::Precipitation(
	double intensity,
	double probability,
	std::string type)
:
	intensity(intensity), probability(probability), type(type)
{
}

/*std::ostream& Precipitation::dump(std::ostream& o) const
 {
 o << "Precipitation[getIntensity()=";
 o << common::to_quoted_string(getIntensity());
 o << ", getProbability()=";
 o << common::to_quoted_string(getProbability());
 o << ']';

 return o;
 }

 std::string Precipitation::str() const
 {
 std::stringstream ss(std::stringstream::out);
 dump(ss);
 return ss.str();

 }*/

}

/*namespace std
 {

 string to_string(const forecast_io::Precipitation& value)
 {
 return value.str();
 }

 }

 std::ostream& operator<<(std::ostream& o, const forecast_io::Precipitation& value)
 {
 return value.dump(o);
 }*/

