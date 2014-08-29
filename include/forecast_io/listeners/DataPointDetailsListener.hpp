#ifndef DATAPOINTDETAILSLISTENER_HPP
#define DATAPOINTDETAILSLISTENER_HPP

#include <ctime>
#include <string>

namespace forecast_io
{
namespace listeners
{

class DataPointDetailsListener
{
public:

	virtual ~DataPointDetailsListener();

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

};

}
}

#endif // DATAPOINTDETAILSLISTENER_HPP
