#include "forecast_io/SynchronicDataPoint.hpp"

namespace forecast_io
{

SynchronicDataPoint::SynchronicDataPoint(
	SingleDataPoint baseDataPoint,
	math::RelativePosition<double, double> nearestStorm
) noexcept :
	baseDataPoint(baseDataPoint),
	nearestStorm(nearestStorm)
{
}

}

