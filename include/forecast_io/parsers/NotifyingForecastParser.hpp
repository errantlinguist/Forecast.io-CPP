#ifndef FORECASTPARSER_HPP
#define FORECASTPARSER_HPP

#include "../../json/AbstractJsonStateMapParser.hpp" // Base class: json::AbstractJsonStateMapParser
#include "../../common/Notifier.hpp" // Base class: Notifier

#include "ForecastAttribute.hpp"

// Forward declarations
namespace json
{
template<typename P>
class JsonArrayParser;
}

namespace forecast_io
{

// Forward declarations
class Alert;
class Forecast;
namespace listeners
{
class ForecastDetailsListener;
}

namespace parsers
{

// Forward declarations
class NotifyingAlertParser;
class NotifyingSynchronicDataPointParser;

class NotifyingForecastParser: public json::AbstractJsonStateMapParser<
		ForecastAttribute>, public common::Notifier<listeners::ForecastDetailsListener>
{
public:

	NotifyingForecastParser(listeners::ForecastDetailsListener& listener,
			json::JsonArrayParser<NotifyingAlertParser>& alertsParser,
			AbstractJsonParser& flagParser,
			NotifyingSynchronicDataPointParser& synchronicDataPointParser,
			const ForecastAttributeNameMap& attributeNames =
					DEFAULT_ATTRIBUTE_NAMES);

protected:

	void parseAttribute(const ForecastAttribute& attribute,
			json_object* const & pValue);

private:

	static const ForecastAttributeNameMap DEFAULT_ATTRIBUTE_NAMES;

	json::JsonArrayParser<NotifyingAlertParser>& alertsParser;
	AbstractJsonParser& flagParser;
	NotifyingSynchronicDataPointParser& synchronicDataPointParser;

};

}
}

#endif // FORECASTPARSER_HPP
