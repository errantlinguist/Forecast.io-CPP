#ifndef SINGLEDATAPOINTFACTORY_HPP
#define SINGLEDATAPOINTFACTORY_HPP

#include "../../common/AbstractFactory.hpp" // Base class: AbstractFactory
#include "../listeners/SingleDataPointDetailsListener.hpp" // Base class: forecast_io::listeners::SingleDataPointDetailsListener

#include "DataPointFactory.hpp"
#include "../SingleDataPoint.hpp"

namespace forecast_io
{

namespace factories
{

class SingleDataPointFactory: public common::AbstractFactory<SingleDataPoint>,
		public listeners::SingleDataPointDetailsListener
{
public:

	SingleDataPoint create();

	const DataPointFactory& getDataPointFactory() const
	{
		return dataPointFactory;
	}

	DataPointFactory& getDataPointFactory()
	{
		return dataPointFactory;
	}

	virtual void notifyApparentTemperature(double temperature);
	virtual void notifyCloudCover(double cloudCover);
	virtual void notifyDewPoint(double dewPoint);
	virtual void notifyHumidity(double humidity);
	virtual void notifyIcon(const std::string& name);
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

	DataPointFactory dataPointFactory;

	SingleDataPoint result;

};

}

}

#endif // SINGLEDATAPOINTFACTORY_HPP
