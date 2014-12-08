#ifndef SYNCHRONICDATAPOINT_HPP
#define SYNCHRONICDATAPOINT_HPP

#include "../math/RelativePosition.hpp"
#include "SingleDataPoint.hpp"

namespace forecast_io
{

class SynchronicDataPoint
{
public:
	SynchronicDataPoint() noexcept;
	SynchronicDataPoint(SingleDataPoint baseDataPoint,
			math::RelativePosition<double, double> nearestStorm) noexcept;

	// Constant getters ---------------------------------------------------------
	const SingleDataPoint& getBaseDataPoint() const
	{
		return baseDataPoint;
	}

	math::RelativePosition<double, double> getNearestStorm() const
	{
		return nearestStorm;
	}

	// Non-constant getters -----------------------------------------------------
	SingleDataPoint& getBaseDataPoint()
	{
		return baseDataPoint;
	}

	math::RelativePosition<double, double>& getNearestStorm()
	{
		return nearestStorm;
	}

	// Setters ------------------------------------------------------------------
	void setBaseDataPoint(SingleDataPoint baseDataPoint)
	{
		this->baseDataPoint = baseDataPoint;
	}

	void setNearestStorm(math::RelativePosition<double, double> nearestStorm)
	{
		this->nearestStorm = nearestStorm;
	}

private:

	SingleDataPoint baseDataPoint;

	math::RelativePosition<double, double> nearestStorm;

};

}

#endif // SYNCHRONICDATAPOINT_HPP
