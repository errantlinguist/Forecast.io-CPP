#include "forecast_io/SynchronicDataPoint.hpp"

namespace forecast_io
{

SynchronicDataPoint::SynchronicDataPoint() : SynchronicDataPoint(SingleDataPoint(), math::RelativePosition<double, double>())
{

}

SynchronicDataPoint::SynchronicDataPoint(
	SingleDataPoint baseDataPoint,
	math::RelativePosition<double, double> nearestStorm
) :
	baseDataPoint(baseDataPoint),
	nearestStorm(nearestStorm)
{
}

}

