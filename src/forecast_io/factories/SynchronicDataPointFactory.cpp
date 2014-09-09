#include "forecast_io/factories/SynchronicDataPointFactory.hpp"

namespace forecast_io
{

namespace factories
{

SynchronicDataPoint SynchronicDataPointFactory::create()
{
	result.setBaseDataPoint(singleDataPointFactory.create());
	return result;
}

void SynchronicDataPointFactory::notifyApparentTemperature(double temperature)
{
	singleDataPointFactory.notifyApparentTemperature(temperature);
}

void SynchronicDataPointFactory::notifyCloudCover(double cloudCover)
{
	singleDataPointFactory.notifyCloudCover(cloudCover);
}

void SynchronicDataPointFactory::notifyDewPoint(double dewPoint)
{
	singleDataPointFactory.notifyDewPoint(dewPoint);
}

void SynchronicDataPointFactory::notifyHumidity(double humidity)
{
	singleDataPointFactory.notifyHumidity(humidity);
}

void SynchronicDataPointFactory::notifyIcon(const std::string& name)
{
	singleDataPointFactory.notifyIcon(name);
}

void SynchronicDataPointFactory::notifyNearestStormBearing(double bearing)
{
	result.getNearestStorm().setBearing(bearing);
}

void SynchronicDataPointFactory::notifyNearestStormDistance(double distance)
{
	result.getNearestStorm().setDistance(distance);
}

void SynchronicDataPointFactory::notifyOzone(double ozone)
{
	singleDataPointFactory.notifyOzone(ozone);
}

void SynchronicDataPointFactory::notifyPrecipitationIntensity(double intensity)
{
	singleDataPointFactory.notifyPrecipitationIntensity(intensity);
}

void SynchronicDataPointFactory::notifyPrecipitationProbability(
		double probability)
{
	singleDataPointFactory.notifyPrecipitationProbability(probability);
}

void SynchronicDataPointFactory::notifyPrecipitationType(const std::string& type)
{
	singleDataPointFactory.notifyPrecipitationType(type);
}

void SynchronicDataPointFactory::notifyPressure(double pressure)
{
	singleDataPointFactory.notifyPressure(pressure);
}

void SynchronicDataPointFactory::notifySummary(const std::string& summary)
{
	singleDataPointFactory.notifySummary(summary);
}

void SynchronicDataPointFactory::notifyTemperature(double temperature)
{
	singleDataPointFactory.notifyTemperature(temperature);
}

void SynchronicDataPointFactory::notifyTime(time_t time)
{
	singleDataPointFactory.notifyTime(time);
}

void SynchronicDataPointFactory::notifyVisibility(double visibility)
{
	singleDataPointFactory.notifyVisibility(visibility);
}

void SynchronicDataPointFactory::notifyWindBearing(double bearing)
{
	singleDataPointFactory.notifyWindBearing(bearing);
}

void SynchronicDataPointFactory::notifyWindSpeed(double speed)
{
	singleDataPointFactory.notifyWindSpeed(speed);
}

}
}

