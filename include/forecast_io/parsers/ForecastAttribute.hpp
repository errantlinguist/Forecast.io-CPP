#ifndef FORECASTATTRIBUTE_HPP
#define FORECASTATTRIBUTE_HPP

#include <string>

namespace forecast_io
{
namespace parsers
{

const std::string ForecastAttribute_NAME = "ForecastAttribute";

enum ForecastAttribute
{
	ALERTS,
	CURRENTLY,
	DAILY,
	FLAGS,
	HOURLY,
	LATITUDE,
	LONGITUDE,
	MINUTELY,
	OFFSET,
	TIMEZONE,

	ForecastAttribute_MAX = TIMEZONE,
	ForecastAttribute_COUNT = ForecastAttribute_MAX + 1
};

// Typedefs
typedef std::unordered_map<std::string, ForecastAttribute> ForecastAttributeNameMap;

}
}

#endif // FORECASTATTRIBUTE_HPP
