#include "forecast_io/DailyDataPoint.hpp"

namespace forecast_io
{

DailyDataPoint::DailyDataPoint(AggregateDataPoint baseDataPoint,
		double moonPhase) noexcept :
		baseDataPoint(baseDataPoint),
		moonPhase(moonPhase)
{
}

}

