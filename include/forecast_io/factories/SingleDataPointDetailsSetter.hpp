#ifndef SINGLEDATAPOINTDETAILSSETTER_HPP
#define SINGLEDATAPOINTDETAILSSETTER_HPP

#include "../listeners/SingleDataPointDetailsListener.hpp" // Base class: forecast_io::listeners::SingleDataPointDetailsListener
#include "../../common/InstanceReferenceHolder.hpp" // Base class: common::InstanceReferenceHolder

#include "DataPointDetailsSetter.hpp"
#include "../SingleDataPoint.hpp"

namespace forecast_io
{

namespace factories
{

class SingleDataPointDetailsSetter :
	public listeners::SingleDataPointDetailsListener,
	public common::InstanceReferenceHolder<SingleDataPoint>
{
public:
	SingleDataPointDetailsSetter(SingleDataPoint& instance);

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

	DataPointDetailsSetter dataPointDetailsSetter;

};

}

}

#endif // SINGLEDATAPOINTDETAILSSETTER_HPP
