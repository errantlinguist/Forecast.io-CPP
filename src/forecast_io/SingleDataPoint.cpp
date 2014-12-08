#include "forecast_io/SingleDataPoint.hpp"

namespace forecast_io
{

SingleDataPoint::SingleDataPoint(
	DataPoint baseDataPoint,
	double temperature,
	double apparentTemperature
) noexcept :
	baseDataPoint(baseDataPoint),
	temperature(temperature),
	apparentTemperature(apparentTemperature)
{
}

}

