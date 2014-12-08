#ifndef AGGREGATEDATAPOINT_HPP
#define AGGREGATEDATAPOINT_HPP

#include "DataPoint.hpp"
#include "../math/Range.hpp"
#include "../common/TimestampedValue.hpp"

namespace forecast_io
{

class AggregateDataPoint
{
public:
	AggregateDataPoint() = default;
	AggregateDataPoint(DataPoint baseDataPoint,
	double precipitationAccumulation,
		common::TimestampedValue<double> precipitationIntensityMax,
		math::Range<time_t> dayLength,
		math::Range<common::TimestampedValue<double>> temperature,
		math::Range<common::TimestampedValue<double>> apparentTemperature) noexcept;

	// Constant getters ---------------------------------------------------------
	const DataPoint& getBaseDataPoint() const
	{
		return baseDataPoint;
	}

	common::TimestampedValue<double> getPrecipitationIntensityMax() const
	{
		return precipitationIntensityMax;
	}

	double getPrecipitationAccumulation() const
	{
		return precipitationAccumulation;
	}

	math::Range<time_t> getDayLength() const
	{
		return dayLength;
	}

	math::Range<common::TimestampedValue<double>> getTemperature() const
	{
		return temperature;
	}
	math::Range<common::TimestampedValue<double>> getApparentTemperature() const
	{
		return apparentTemperature;
	}

	// Non-constant getters -----------------------------------------------------
	DataPoint& getBaseDataPoint()
	{
		return baseDataPoint;
	}

	// Setters ------------------------------------------------------------------
	void setBaseDataPoint(DataPoint baseDataPoint)
	{
		this->baseDataPoint = baseDataPoint;
	}

	void setPrecipitationIntensityMax(
			common::TimestampedValue<double> precipitationIntensityMax)
	{
		this->precipitationIntensityMax = precipitationIntensityMax;
	}

	void setPrecipitationAccumulation(double precipitationAccumulation)
	{
		this->precipitationAccumulation = precipitationAccumulation;
	}

	void setDayLength(math::Range<time_t> dayLength)
	{
		this->dayLength = dayLength;
	}

	void setTemperature(
			math::Range<common::TimestampedValue<double>> temperature)
	{
		this->temperature = temperature;
	}

	void setApparentTemperature(
			math::Range<common::TimestampedValue<double>> apparentTemperature)
	{
		this->apparentTemperature = apparentTemperature;
	}

private:

	DataPoint baseDataPoint;
	/**
	 * A range from sunrise to sunset.
	 */
	math::Range<time_t> dayLength;
	double precipitationAccumulation;
	common::TimestampedValue<double> precipitationIntensityMax;

	math::Range<common::TimestampedValue<double>> temperature;
	math::Range<common::TimestampedValue<double>> apparentTemperature;

};

}

#endif // AGGREGATEDATAPOINT_HPP
