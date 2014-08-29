#include "forecast_io/factories/DataPointFactory.hpp"

namespace forecast_io
{

namespace factories
{

DataPoint DataPointFactory::create()
{
	return result;
}

void DataPointFactory::notifyCloudCover(double cloudCover)
{
	result.setCloudCover(cloudCover);
}

void DataPointFactory::notifyDewPoint(double dewPoint)
{
	result.setDewPoint(dewPoint);
}

void DataPointFactory::notifyHumidity(double humidity)
{
	result.setHumidity(humidity);
}

void DataPointFactory::notifyIcon(const std::string& name)
{
	result.getOverview().setIconName(name);
}

void DataPointFactory::notifyOzone(double ozone)
{
	result.setOzone(ozone);
}

void DataPointFactory::notifyPrecipitationIntensity(double intensity)
{
	result.getPrecipitation().setIntensity(intensity);
}

void DataPointFactory::notifyPrecipitationProbability(double probability)
{
	result.getPrecipitation().setProbability(probability);
}

void DataPointFactory::notifyPrecipitationType(const std::string& type)
{
	result.getPrecipitation().setType(type);
}

void DataPointFactory::notifyPressure(double pressure)
{
	result.setPressure(pressure);
}

void DataPointFactory::notifySummary(const std::string& summary)
{
	result.getOverview().setSummary(summary);
}

void DataPointFactory::notifyTime(time_t time)
{
	result.setTime(time);
}

void DataPointFactory::notifyVisibility(double visibility)
{
	result.setVisibility(visibility);
}

void DataPointFactory::notifyWindBearing(double bearing)
{
	result.getWind().setDirection(bearing);
}

void DataPointFactory::notifyWindSpeed(double speed)
{
	result.getWind().setMagnitude(speed);
}

}
}

