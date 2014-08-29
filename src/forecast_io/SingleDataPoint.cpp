#include "forecast_io/SingleDataPoint.hpp"

namespace forecast_io
{

SingleDataPoint::SingleDataPoint() :
	SingleDataPoint(DataPoint(), 0, 0)
{

}

SingleDataPoint::SingleDataPoint(
	DataPoint baseDataPoint,
	double temperature,
	double apparentTemperature
) :
	baseDataPoint(baseDataPoint),
	temperature(temperature),
	apparentTemperature(apparentTemperature)
{
}

}

