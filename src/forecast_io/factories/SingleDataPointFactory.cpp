#include "forecast_io/factories/SingleDataPointFactory.hpp"

namespace forecast_io
{

namespace factories
{


SingleDataPointFactory::~SingleDataPointFactory()
{

}

SingleDataPoint SingleDataPointFactory::create()
{
	result.setBaseDataPoint(dataPointFactory.create());
	return result;
}

void SingleDataPointFactory::notifyApparentTemperature(double temperature)
{
	result.setApparentTemperature(temperature);
}

void SingleDataPointFactory::notifyCloudCover(double cloudCover)
{
	dataPointFactory.notifyCloudCover(cloudCover);
}

void SingleDataPointFactory::notifyDewPoint(double dewPoint)
{
	dataPointFactory.notifyDewPoint(dewPoint);
}

void SingleDataPointFactory::notifyHumidity(double humidity)
{
	dataPointFactory.notifyHumidity(humidity);
}

void SingleDataPointFactory::notifyIcon(const std::string& name)
{
	dataPointFactory.notifyIcon(name);
}

void SingleDataPointFactory::notifyOzone(double ozone)
{
	dataPointFactory.notifyOzone(ozone);
}

void SingleDataPointFactory::notifyPrecipitationIntensity(double intensity)
{
	dataPointFactory.notifyPrecipitationIntensity(intensity);
}

void SingleDataPointFactory::notifyPrecipitationProbability(
		double probability)
{
	dataPointFactory.notifyPrecipitationProbability(probability);
}

void SingleDataPointFactory::notifyPrecipitationType(const std::string& type)
{
	dataPointFactory.notifyPrecipitationType(type);
}

void SingleDataPointFactory::notifyPressure(double pressure)
{
	dataPointFactory.notifyPressure(pressure);
}

void SingleDataPointFactory::notifySummary(const std::string& summary)
{
	dataPointFactory.notifySummary(summary);
}

void SingleDataPointFactory::notifyTemperature(double temperature)
{
	result.setTemperature(temperature);
}

void SingleDataPointFactory::notifyTime(time_t time)
{
	dataPointFactory.notifyTime(time);
}

void SingleDataPointFactory::notifyVisibility(double visibility)
{
	dataPointFactory.notifyVisibility(visibility);
}

void SingleDataPointFactory::notifyWindBearing(double bearing)
{
	dataPointFactory.notifyWindBearing(bearing);
}

void SingleDataPointFactory::notifyWindSpeed(double speed)
{
	dataPointFactory.notifyWindSpeed(speed);
}

}

}

