#include "forecast_io/Precipitation.hpp"

#include <sstream>

#include "common/to_string.hpp"

namespace forecast_io
{

Precipitation::Precipitation(
	double intensity,
	double probability,
	std::string type) noexcept
:
	intensity(intensity), probability(probability), type(type)
{
	// ctor
}

}
