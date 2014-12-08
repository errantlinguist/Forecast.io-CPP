#ifndef DAILYDATAPOINT_HPP
#define DAILYDATAPOINT_HPP

#include "AggregateDataPoint.hpp"

namespace forecast_io
{

class DailyDataPoint
{
public:
	DailyDataPoint() noexcept;
	DailyDataPoint(AggregateDataPoint baseDataPoint, double moonPhase) noexcept;

	// Constant getters ---------------------------------------------------------
	const AggregateDataPoint& getBaseDataPoint() const
	{
		return baseDataPoint;
	}

	double getMoonPhase() const
	{
		return moonPhase;
	}

	// Non-constant getters -----------------------------------------------------
	AggregateDataPoint& getBaseDataPoint()
	{
		return baseDataPoint;
	}

	// Setters ------------------------------------------------------------------
	void setBaseDataPoint(AggregateDataPoint baseDataPoint)
	{
		this->baseDataPoint = baseDataPoint;
	}

	void setMoonPhase(double moonPhase)
	{
		this->moonPhase = moonPhase;
	}

private:

	AggregateDataPoint baseDataPoint;

	double moonPhase;

};

}

#endif // DAILYDATAPOINT_HPP
