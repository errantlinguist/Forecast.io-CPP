#ifndef SYNCHRONICDATAPOINTFACTORY_HPP
#define SYNCHRONICDATAPOINTFACTORY_HPP

#include "../../common/AbstractFactory.hpp" // Base class: AbstractFactory
#include "../listeners/SynchronicDataPointDetailsListener.hpp" // Base class: forecast_io::listeners::SynchronicDataPointDetailsListener

#include "SingleDataPointFactory.hpp"
#include "../SynchronicDataPoint.hpp"

namespace forecast_io
{

namespace factories
{

class SynchronicDataPointFactory: public common::AbstractFactory<SynchronicDataPoint>,
		public listeners::SynchronicDataPointDetailsListener
{
public:

	virtual ~SynchronicDataPointFactory();

	SynchronicDataPoint create();

	const SingleDataPointFactory& getSingleDataPointFactory() const
	{
		return singleDataPointFactory;
	}

	SingleDataPointFactory& getSingleDataPointFactory()
	{
		return singleDataPointFactory;
	}

	virtual void notifyApparentTemperature(double temperature);
	virtual void notifyCloudCover(double cloudCover);
	virtual void notifyDewPoint(double dewPoint);
	virtual void notifyHumidity(double humidity);
	virtual void notifyIcon(const std::string& name);
	virtual void notifyNearestStormBearing(double bearing);
	virtual void notifyNearestStormDistance(double distance);
	virtual void notifyOzone(double ozone);
	virtual void notifyPrecipitationIntensity(double intensity);
	virtual void notifyPrecipitationProbability(double probability);
	virtual void notifyPrecipitationType(const std::string& type);
	virtual void notifyPressure(double pressure);
	virtual void notifySummary(const std::string& summary);
	virtual void notifyTemperature(double temperature);
	virtual void notifyTime(time_t time);
	virtual void notifyVisibility(double visibility);
	virtual void notifyWindBearing(double bearing);
	virtual void notifyWindSpeed(double speed);

private:

	SingleDataPointFactory singleDataPointFactory;

	SynchronicDataPoint result;

};

}

}

#endif // SYNCHRONICDATAPOINTFACTORY_HPP
