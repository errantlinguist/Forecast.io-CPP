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

}
