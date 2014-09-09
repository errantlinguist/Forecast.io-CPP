#include "forecast_io/listeners/DataPointDetailsListener.hpp"

namespace forecast_io
{
namespace listeners
{

void DataPointDetailsListener::notifyCloudCover(double cloudCover) { (void)cloudCover; /*Avoid "unused parameter" warning*/ }
void DataPointDetailsListener::notifyDewPoint(double dewPoint) { (void)dewPoint; /*Avoid "unused parameter" warning*/ }
void DataPointDetailsListener::notifyHumidity(double humidity) { (void)humidity; /*Avoid "unused parameter" warning*/ }
void DataPointDetailsListener::notifyIcon(const std::string& name) { (void)name; /*Avoid "unused parameter" warning*/ }
void DataPointDetailsListener::notifyOzone(double ozone) { (void)ozone; /*Avoid "unused parameter" warning*/ }
void DataPointDetailsListener::notifyPrecipitationIntensity(double intensity) { (void)intensity; /*Avoid "unused parameter" warning*/ }
void DataPointDetailsListener::notifyPrecipitationProbability(double probability) { (void)probability; /*Avoid "unused parameter" warning*/ }
void DataPointDetailsListener::notifyPrecipitationType(const std::string& type) { (void)type; /*Avoid "unused parameter" warning*/ }
void DataPointDetailsListener::notifyPressure(double pressure) { (void)pressure; /*Avoid "unused parameter" warning*/ }
void DataPointDetailsListener::notifySummary(const std::string& summary) { (void)summary; /*Avoid "unused parameter" warning*/ }
void DataPointDetailsListener::notifyTime(time_t time) { (void)time; /*Avoid "unused parameter" warning*/ }
void DataPointDetailsListener::notifyVisibility(double visibility) { (void)visibility; /*Avoid "unused parameter" warning*/ }
void DataPointDetailsListener::notifyWindBearing(double bearing) { (void)bearing; /*Avoid "unused parameter" warning*/ }
void DataPointDetailsListener::notifyWindSpeed(double speed) { (void)speed; /*Avoid "unused parameter" warning*/ }

}
}
