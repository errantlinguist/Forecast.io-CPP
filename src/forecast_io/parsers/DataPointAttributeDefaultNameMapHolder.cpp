#include "forecast_io/parsers/DataPointAttributeDefaultNameMapHolder.hpp"

namespace forecast_io
{
namespace parsers
{

static void insertDefaultAttributeNames(
		DataPointAttributeNameMap& attributeNames)
{
	attributeNames["apparentTemperature"] =
			DataPointAttribute::APPARENT_TEMPERATURE;
	attributeNames["apparentTemperatureMax"] =
			DataPointAttribute::APPARENT_TEMPERATURE_MAX;
	attributeNames["apparentTemperatureMaxTime"] =
			DataPointAttribute::APPARENT_TEMPERATURE_MAX_TIME;
	attributeNames["apparentTemperatureMin"] =
			DataPointAttribute::APPARENT_TEMPERATURE_MIN;
	attributeNames["apparentTemperatureMinTime"] =
			DataPointAttribute::APPARENT_TEMPERATURE_MIN_TIME;
	attributeNames["cloudCover"] = DataPointAttribute::CLOUD_COVER;
	attributeNames["dewPoint"] = DataPointAttribute::DEW_POINT;
	attributeNames["humidity"] = DataPointAttribute::HUMIDITY;
	attributeNames["icon"] = DataPointAttribute::ICON;
	attributeNames["moonPhase"] = DataPointAttribute::MOON_PHASE;
	attributeNames["nearestStormBearing"] =
			DataPointAttribute::NEAREST_STORM_BEARING;
	attributeNames["nearestStormDistance"] =
			DataPointAttribute::NEAREST_STORM_DISTANCE;
	attributeNames["ozone"] = DataPointAttribute::OZONE;
	attributeNames["pressure"] = DataPointAttribute::PRESSURE;
	attributeNames["precipAccumulation"] =
			DataPointAttribute::PRECIPITATION_ACCUMULATION;
	attributeNames["precipIntensity"] =
			DataPointAttribute::PRECIPITATION_INTENSITY;
	attributeNames["precipIntensityMax"] =
			DataPointAttribute::PRECIPITATION_INTENSITY_MAX;
	attributeNames["precipIntensityMaxTime"] =
			DataPointAttribute::PRECIPITATION_INTENSITY_MAX_TIME;
	attributeNames["precipProbability"] =
			DataPointAttribute::PRECIPITATION_PROBABILITY;
	attributeNames["precipType"] = DataPointAttribute::PRECIPITATION_TYPE;
	attributeNames["summary"] = DataPointAttribute::SUMMARY;
	attributeNames["sunriseTime"] = DataPointAttribute::SUNRISE_TIME;
	attributeNames["sunsetTime"] = DataPointAttribute::SUNSET_TIME;
	attributeNames["temperature"] = DataPointAttribute::TEMPERATURE;
	attributeNames["temperatureMax"] = DataPointAttribute::TEMPERATURE_MAX;
	attributeNames["temperatureMaxTime"] =
			DataPointAttribute::TEMPERATURE_MAX_TIME;
	attributeNames["temperatureMin"] = DataPointAttribute::TEMPERATURE_MIN;
	attributeNames["temperatureMinTime"] =
			DataPointAttribute::TEMPERATURE_MIN_TIME;
	attributeNames["time"] = DataPointAttribute::TIME;
	attributeNames["visibility"] = DataPointAttribute::VISIBILITY;
	attributeNames["windSpeed"] = DataPointAttribute::WIND_SPEED;
	attributeNames["windBearing"] = DataPointAttribute::WIND_BEARING;
}

std::unique_ptr<DataPointAttributeNameMap> DataPointAttributeDefaultNameMapHolder::pInstance = nullptr;

std::unique_ptr<DataPointAttributeNameMap> DataPointAttributeDefaultNameMapHolder::createInstance()
{
	std::unique_ptr<DataPointAttributeNameMap> result(
			new DataPointAttributeNameMap(
					DataPointAttribute::DataPointAttribute_COUNT));
	insertDefaultAttributeNames(*result);
	return result;
}

}
}
