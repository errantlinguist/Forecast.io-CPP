#include "forecast_io/factories/SynchronicDataPointDetailsSetter.hpp"

namespace forecast_io
{
namespace factories
{

SynchronicDataPointDetailsSetter::SynchronicDataPointDetailsSetter(SynchronicDataPoint& instance) noexcept :
	common::InstanceReferenceHolder<SynchronicDataPoint>(instance),
	singleDataPointDetailsSetter(instance.getBaseDataPoint())
{
}

void SynchronicDataPointDetailsSetter::notifyApparentTemperature(double temperature)
{
	singleDataPointDetailsSetter.notifyApparentTemperature(temperature);
}

void SynchronicDataPointDetailsSetter::notifyCloudCover(double cloudCover)
{
	singleDataPointDetailsSetter.notifyCloudCover(cloudCover);
}

void SynchronicDataPointDetailsSetter::notifyDewPoint(double dewPoint)
{
	singleDataPointDetailsSetter.notifyDewPoint(dewPoint);
}

void SynchronicDataPointDetailsSetter::notifyHumidity(double humidity)
{
	singleDataPointDetailsSetter.notifyHumidity(humidity);
}

void SynchronicDataPointDetailsSetter::notifyIcon(const std::string& name)
{
	singleDataPointDetailsSetter.notifyIcon(name);
}

void SynchronicDataPointDetailsSetter::notifyNearestStormBearing(double bearing)
{
	getInstance().getNearestStorm().setBearing(bearing);
}

void SynchronicDataPointDetailsSetter::notifyNearestStormDistance(double distance)
{
	getInstance().getNearestStorm().setDistance(distance);
}

void SynchronicDataPointDetailsSetter::notifyOzone(double ozone)
{
	singleDataPointDetailsSetter.notifyOzone(ozone);
}

void SynchronicDataPointDetailsSetter::notifyPrecipitationIntensity(double intensity)
{
	singleDataPointDetailsSetter.notifyPrecipitationIntensity(intensity);
}

void SynchronicDataPointDetailsSetter::notifyPrecipitationProbability(
		double probability)
{
	singleDataPointDetailsSetter.notifyPrecipitationProbability(probability);
}

void SynchronicDataPointDetailsSetter::notifyPrecipitationType(const std::string& type)
{
	singleDataPointDetailsSetter.notifyPrecipitationType(type);
}

void SynchronicDataPointDetailsSetter::notifyPressure(double pressure)
{
	singleDataPointDetailsSetter.notifyPressure(pressure);
}

void SynchronicDataPointDetailsSetter::notifySummary(const std::string& summary)
{
	singleDataPointDetailsSetter.notifySummary(summary);
}

void SynchronicDataPointDetailsSetter::notifyTemperature(double temperature)
{
	singleDataPointDetailsSetter.notifyTemperature(temperature);
}

void SynchronicDataPointDetailsSetter::notifyTime(time_t time)
{
	singleDataPointDetailsSetter.notifyTime(time);
}

void SynchronicDataPointDetailsSetter::notifyVisibility(double visibility)
{
	singleDataPointDetailsSetter.notifyVisibility(visibility);
}

void SynchronicDataPointDetailsSetter::notifyWindBearing(double bearing)
{
	singleDataPointDetailsSetter.notifyWindBearing(bearing);
}

void SynchronicDataPointDetailsSetter::notifyWindSpeed(double speed)
{
	singleDataPointDetailsSetter.notifyWindSpeed(speed);
}


}
}

