#include "forecast_io/AggregateDataPoint.hpp"

namespace forecast_io
{

AggregateDataPoint::AggregateDataPoint(DataPoint baseDataPoint,
	double precipitationAccumulation,
		common::TimestampedValue<double> precipitationIntensityMax,
		math::Range<time_t> dayLength,
		math::Range<common::TimestampedValue<double>> temperature,
		math::Range<common::TimestampedValue<double>> apparentTemperature) noexcept :
		baseDataPoint(baseDataPoint),
		dayLength(dayLength),
		precipitationAccumulation(precipitationAccumulation),
		precipitationIntensityMax(precipitationIntensityMax),
		temperature(temperature),
		apparentTemperature(apparentTemperature)
{

}

}

