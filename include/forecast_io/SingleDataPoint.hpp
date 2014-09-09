#ifndef SINGLEDATAPOINT_HPP
#define SINGLEDATAPOINT_HPP

#include "DataPoint.hpp"

namespace forecast_io
{

class SingleDataPoint
{
public:
	SingleDataPoint();
	SingleDataPoint(DataPoint baseDataPoint, double temperature,
			double apparentTemperature);

	// Constant getters ---------------------------------------------------------
	const DataPoint& getBaseDataPoint() const
	{
		return baseDataPoint;
	}

	double getTemperature() const
	{
		return temperature;
	}

	double getApparentTemperature() const
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

	void setTemperature(double temperature)
	{
		this->temperature = temperature;
	}

	void setApparentTemperature(double apparentTemperature)
	{
		this->apparentTemperature = apparentTemperature;
	}

private:

	DataPoint baseDataPoint;

	double temperature;
	double apparentTemperature;
};

}

#endif // SINGLEDATAPOINT_HPP
