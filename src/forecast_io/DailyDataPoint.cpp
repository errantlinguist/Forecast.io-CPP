#include "forecast_io/DailyDataPoint.hpp"

namespace forecast_io
{

DailyDataPoint::DailyDataPoint() : DailyDataPoint(AggregateDataPoint(), 0.0)
{
}

DailyDataPoint::DailyDataPoint(AggregateDataPoint baseDataPoint,
		double moonPhase) :
		baseDataPoint(baseDataPoint),
		moonPhase(moonPhase)
{
}

}

