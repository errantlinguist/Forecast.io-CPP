#ifndef DATAPOINTDETAILSSETTER_HPP
#define DATAPOINTDETAILSSETTER_HPP

#include "../listeners/DataPointDetailsListener.hpp" // Base class: forecast_io::listeners::DataPointDetailsListener
#include "../../common/InstanceReferenceHolder.hpp" // Base class: common::InstanceReferenceHolder

#include "../DataPoint.hpp"

namespace forecast_io
{

namespace factories
{

class DataPointDetailsSetter :
	public listeners::DataPointDetailsListener,
	public common::InstanceReferenceHolder<DataPoint>
{
public:
	DataPointDetailsSetter(DataPoint& instance) noexcept;

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
	virtual void notifyTime(time_t time);
	virtual void notifyVisibility(double visibility);
	virtual void notifyWindBearing(double bearing);
	virtual void notifyWindSpeed(double speed);

private:

};

}

}

#endif // DATAPOINTDETAILSSETTER_HPP
