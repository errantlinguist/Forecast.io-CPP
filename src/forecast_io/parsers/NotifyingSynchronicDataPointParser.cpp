#include "forecast_io/parsers/NotifyingSynchronicDataPointParser.hpp"

#include "forecast_io/listeners/SynchronicDataPointDetailsListener.hpp"

namespace forecast_io
{

namespace parsers
{

NotifyingSynchronicDataPointParser::NotifyingSynchronicDataPointParser(
		listeners::SynchronicDataPointDetailsListener* pListener,
		const DataPointAttributeNameMap& attributeNames) :
		AbstractJsonStateMapParser(attributeNames), Notifier(pListener)
{
}

// Members ----------------------------------------------------------------------

void NotifyingSynchronicDataPointParser::parseAttribute(
		const DataPointAttribute& attribute, json_object* const & pValue)
{
	switch (attribute)
	{
	case APPARENT_TEMPERATURE:
	{
		const double apparentTemperature(json_object_get_double(pValue));
		for (listeners::SynchronicDataPointDetailsListener* pListener : getListeners())
		{
			pListener->notifyApparentTemperature(apparentTemperature);
		}
		break;
	}
	case CLOUD_COVER:
	{
		const double cloudCover(json_object_get_double(pValue));
		for (listeners::SynchronicDataPointDetailsListener* pListener : getListeners())
		{
			pListener->notifyCloudCover(cloudCover);
		}
		break;
	}
	case DEW_POINT:
	{
		const double dewPoint(json_object_get_double(pValue));
		for (listeners::SynchronicDataPointDetailsListener* pListener : getListeners())
		{
			pListener->notifyDewPoint(dewPoint);
		}
		break;
	}
	case HUMIDITY:
	{
		const double humidity(json_object_get_double(pValue));
		for (listeners::SynchronicDataPointDetailsListener* pListener : getListeners())
		{
			pListener->notifyHumidity(humidity);
		}
		break;
	}
	case ICON:
	{
		const std::string iconName(json_object_get_string(pValue));
		for (listeners::SynchronicDataPointDetailsListener* pListener : getListeners())
		{
			pListener->notifyIcon(iconName);
		}
		break;
	}
	case NEAREST_STORM_BEARING:
	{
		const double bearing(json_object_get_double(pValue));
		for (listeners::SynchronicDataPointDetailsListener* pListener : getListeners())
		{
			pListener->notifyNearestStormBearing(bearing);
		}
		break;
	}
	case NEAREST_STORM_DISTANCE:
	{
		const double distance(json_object_get_double(pValue));
		for (listeners::SynchronicDataPointDetailsListener* pListener : getListeners())
		{
			pListener->notifyNearestStormDistance(distance);
		}
		break;
	}
	case OZONE:
	{
		const double ozone(json_object_get_double(pValue));
		for (listeners::SynchronicDataPointDetailsListener* pListener : getListeners())
		{
			pListener->notifyOzone(ozone);
		}
		break;
	}
	case PRECIPITATION_INTENSITY:
	{
		const double precipitationIntensity(json_object_get_double(pValue));
		for (listeners::SynchronicDataPointDetailsListener* pListener : getListeners())
		{
			pListener->notifyPrecipitationIntensity(precipitationIntensity);
		}
		break;
	}
	case PRECIPITATION_PROBABILITY:
	{
		const double precipitationProbability(json_object_get_double(pValue));
		for (listeners::SynchronicDataPointDetailsListener* pListener : getListeners())
		{
			pListener->notifyPrecipitationProbability(precipitationProbability);
		}
		break;
	}
	case PRECIPITATION_TYPE:
	{
		const std::string precipitationType(json_object_get_string(pValue));
		for (listeners::SynchronicDataPointDetailsListener* pListener : getListeners())
		{
			pListener->notifyPrecipitationType(precipitationType);
		}
		break;
	}
	case PRESSURE:
	{
		const double pressure(json_object_get_double(pValue));
		for (listeners::SynchronicDataPointDetailsListener* pListener : getListeners())
		{
			pListener->notifyPressure(pressure);
		}
		break;
	}
	case SUMMARY:
	{
		const std::string summary(json_object_get_string(pValue));
		for (listeners::SynchronicDataPointDetailsListener* pListener : getListeners())
		{
			pListener->notifySummary(summary);
		}
		break;
	}
	case DataPointAttribute::TEMPERATURE:
	{
		const double temperature(json_object_get_double(pValue));
		for (listeners::SynchronicDataPointDetailsListener* pListener : getListeners())
		{
			pListener->notifyTemperature(temperature);
		}
		break;
	}
	case TIME:
	{
		const time_t time(static_cast<time_t>(json_object_get_int64(pValue)));
		for (listeners::SynchronicDataPointDetailsListener* pListener : getListeners())
		{
			pListener->notifyTime(time);
		}
		break;
	}
	case VISIBILITY:
	{
		const double visibility(json_object_get_double(pValue));
		for (listeners::SynchronicDataPointDetailsListener* pListener : getListeners())
		{
			pListener->notifyVisibility(visibility);
		}
		break;
	}
	case WIND_BEARING:
	{
		const double windBearing(json_object_get_double(pValue));
		for (listeners::SynchronicDataPointDetailsListener* pListener : getListeners())
		{
			pListener->notifyWindBearing(windBearing);
		}
		break;
	}
	case WIND_SPEED:
	{
		const double windSpeed(json_object_get_double(pValue));
		for (listeners::SynchronicDataPointDetailsListener* pListener : getListeners())
		{
			pListener->notifyWindSpeed(windSpeed);
		}
		break;
	}
	default:
	{
		throw std::logic_error(
				createUndefinedAttributeErrorMessage(DataPointAttribute_NAME,
						attribute));
	}
	}

}

}

}

