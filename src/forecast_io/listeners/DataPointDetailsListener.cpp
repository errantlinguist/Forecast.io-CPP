#include "forecast_io/listeners/DataPointDetailsListener.hpp"

namespace forecast_io
{
namespace listeners
{

DataPointDetailsListener::~DataPointDetailsListener() {}

void DataPointDetailsListener::notifyCloudCover(double cloudCover) {}
void DataPointDetailsListener::notifyDewPoint(double dewPoint) {}
void DataPointDetailsListener::notifyHumidity(double humidity) {}
void DataPointDetailsListener::notifyIcon(const std::string& name) {}
void DataPointDetailsListener::notifyOzone(double ozone) {}
void DataPointDetailsListener::notifyPrecipitationIntensity(double intensity) {}
void DataPointDetailsListener::notifyPrecipitationProbability(double probability) {}
void DataPointDetailsListener::notifyPrecipitationType(const std::string& type) {}
void DataPointDetailsListener::notifyPressure(double pressure) {}
void DataPointDetailsListener::notifySummary(const std::string& summary) {}
void DataPointDetailsListener::notifyTime(time_t time) {}
void DataPointDetailsListener::notifyVisibility(double visibility) {}
void DataPointDetailsListener::notifyWindBearing(double bearing) {}
void DataPointDetailsListener::notifyWindSpeed(double speed) {}

}
}
