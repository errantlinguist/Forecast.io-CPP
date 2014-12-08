#include "forecast_io/Forecast.hpp"

#include <sstream>

#include "common/to_string.hpp"

namespace forecast_io
{

Forecast::Forecast(Flags flags) noexcept : Forecast(flags, std::vector<Alert>(), math::Coordinate(), time_offset_t(0), "", SynchronicDataPoint(), DataBlock(), DataBlock())
{
}

Forecast::Forecast(Flags flags, std::vector<Alert> alerts, math::Coordinate location, time_offset_t offset, std::string timezone, SynchronicDataPoint currentWeather, DataBlock minutelyWeather, DataBlock hourlyWeather) noexcept :
		alerts(alerts), flags(flags), location(location), offset(offset), timezone(timezone), currentWeather(currentWeather), minutelyWeather(minutelyWeather), hourlyWeather(hourlyWeather)
{
}

}
