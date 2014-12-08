#include "forecast_io/parsers/NotifyingForecastParser.hpp"

#include <stdexcept>

#include "forecast_io/Forecast.hpp"
#include "forecast_io/listeners/ForecastDetailsListener.hpp"
#include "forecast_io/parsers/NotifyingAlertParser.hpp"
#include "forecast_io/parsers/NotifyingFlagParser.hpp"
#include "forecast_io/parsers/NotifyingSynchronicDataPointParser.hpp"
#include "json/JsonArrayParser.hpp"

namespace forecast_io
{
namespace parsers
{

// Free functions ---------------------------------------------------------------
static ForecastAttributeNameMap createDefaultAttributeNameMap()
{
	ForecastAttributeNameMap result(
			ForecastAttribute::ForecastAttribute_COUNT);

	result["alerts"] = ForecastAttribute::ALERTS;
	result["currently"] = ForecastAttribute::CURRENTLY;
	result["daily"] = ForecastAttribute::DAILY;
	result["flags"] = ForecastAttribute::FLAGS;
	result["hourly"] = ForecastAttribute::HOURLY;
	result["latitude"] = ForecastAttribute::LATITUDE;
	result["longitude"] = ForecastAttribute::LONGITUDE;
	result["minutely"] = ForecastAttribute::MINUTELY;
	result["offset"] = ForecastAttribute::OFFSET;
	result["timezone"] = ForecastAttribute::TIMEZONE;

	return result;
}

// Con-/destructors -------------------------------------------------------------

NotifyingForecastParser::NotifyingForecastParser(
		listeners::ForecastDetailsListener* pListener,
		json::JsonArrayParser<NotifyingAlertParser>& alertsParser,
		AbstractJsonParser& flagParser,
		NotifyingSynchronicDataPointParser& synchronicDataPointParser,
		const ForecastAttributeNameMap& attributeNames) noexcept :
		AbstractJsonStateMapParser(attributeNames), Notifier(pListener), alertsParser(
				alertsParser), flagParser(flagParser), synchronicDataPointParser(
				synchronicDataPointParser)
{
}

// Members ----------------------------------------------------------------------
const ForecastAttributeNameMap NotifyingForecastParser::DEFAULT_ATTRIBUTE_NAMES =
		createDefaultAttributeNameMap();

void NotifyingForecastParser::parseAttribute(const ForecastAttribute& attribute,
		json_object* const & pValue)
{
	switch (attribute)
	{
	case ForecastAttribute::ALERTS:
	{
		alertsParser.parse(pValue);
		break;
	}
	case ForecastAttribute::CURRENTLY:
	{
		synchronicDataPointParser.parse(pValue);
		break;
	}
	case ForecastAttribute::DAILY:
	{
		// TODO: Implement parsing of "daily" data points
		break;
	}
	case ForecastAttribute::FLAGS:
	{
		flagParser.parse(pValue);
		break;
	}
	case ForecastAttribute::HOURLY:
	{
		// TODO: Implement parsing of "hourly" data points
		break;
	}
	case ForecastAttribute::LATITUDE:
	{
		const double latitude(json_object_get_double(pValue));
		for (listeners::ForecastDetailsListener* const & pListener : getListeners())
		{
			pListener->notifyLatitude(latitude);
		}
		break;
	}
	case ForecastAttribute::LONGITUDE:
	{
		const double longitude(json_object_get_double(pValue));
		for (listeners::ForecastDetailsListener* const & pListener : getListeners())
		{
			pListener->notifyLongitude(longitude);
		}
		break;
	}
	case ForecastAttribute::MINUTELY:
	{
		// TODO: Implement parsing of "minutely" data points
		break;
	}
	case ForecastAttribute::OFFSET:
	{
		const signed char offset(
				static_cast<signed char>(json_object_get_int64(pValue)));
		for (listeners::ForecastDetailsListener* const & pListener : getListeners())
		{
			pListener->notifyOffset(offset);
		}
		break;
	}
	case ForecastAttribute::TIMEZONE:
	{
		const std::string timezone(json_object_get_string(pValue));
		for (listeners::ForecastDetailsListener* const & pListener : getListeners())
		{
			pListener->notifyTimezone(timezone);
		}
		break;
	}
	default:
	{
		throw std::logic_error(
				createUndefinedAttributeErrorMessage(ForecastAttribute_NAME,
						attribute));
		break;
	}
	}
}

}
}
