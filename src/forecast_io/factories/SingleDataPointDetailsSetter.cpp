#include "forecast_io/factories/SingleDataPointDetailsSetter.hpp"

namespace forecast_io
{

namespace factories
{

SingleDataPointDetailsSetter::SingleDataPointDetailsSetter(SingleDataPoint& instance) :
	common::InstanceReferenceHolder<SingleDataPoint>(instance),
	dataPointDetailsSetter(instance.getBaseDataPoint())
{
}

SingleDataPointDetailsSetter::~SingleDataPointDetailsSetter()
{
}

void SingleDataPointDetailsSetter::notifyApparentTemperature(double temperature)
{
	getInstance().setApparentTemperature(temperature);
}

void SingleDataPointDetailsSetter::notifyCloudCover(double cloudCover)
{
	dataPointDetailsSetter.notifyCloudCover(cloudCover);
}

void SingleDataPointDetailsSetter::notifyDewPoint(double dewPoint)
{
	dataPointDetailsSetter.notifyDewPoint(dewPoint);
}

void SingleDataPointDetailsSetter::notifyHumidity(double humidity)
{
	dataPointDetailsSetter.notifyHumidity(humidity);
}

void SingleDataPointDetailsSetter::notifyIcon(const std::string& name)
{
	dataPointDetailsSetter.notifyIcon(name);
}

void SingleDataPointDetailsSetter::notifyOzone(double ozone)
{
	dataPointDetailsSetter.notifyOzone(ozone);
}

void SingleDataPointDetailsSetter::notifyPrecipitationIntensity(double intensity)
{
	dataPointDetailsSetter.notifyPrecipitationIntensity(intensity);
}

void SingleDataPointDetailsSetter::notifyPrecipitationProbability(
		double probability)
{
	dataPointDetailsSetter.notifyPrecipitationProbability(probability);
}

void SingleDataPointDetailsSetter::notifyPrecipitationType(const std::string& type)
{
	dataPointDetailsSetter.notifyPrecipitationType(type);
}

void SingleDataPointDetailsSetter::notifyPressure(double pressure)
{
	dataPointDetailsSetter.notifyPressure(pressure);
}

void SingleDataPointDetailsSetter::notifySummary(const std::string& summary)
{
	dataPointDetailsSetter.notifySummary(summary);
}

void SingleDataPointDetailsSetter::notifyTemperature(double temperature)
{
	getInstance().setTemperature(temperature);
}

void SingleDataPointDetailsSetter::notifyTime(time_t time)
{
	dataPointDetailsSetter.notifyTime(time);
}

void SingleDataPointDetailsSetter::notifyVisibility(double visibility)
{
	dataPointDetailsSetter.notifyVisibility(visibility);
}

void SingleDataPointDetailsSetter::notifyWindBearing(double bearing)
{
	dataPointDetailsSetter.notifyWindBearing(bearing);
}

void SingleDataPointDetailsSetter::notifyWindSpeed(double speed)
{
	dataPointDetailsSetter.notifyWindSpeed(speed);
}


}

}

