#include "forecast_io/DataPoint.hpp"

namespace forecast_io
{

DataPoint::DataPoint(
	time_t time,
	DataOverview overview,
	double cloudCover,
	double dewPoint,
	double humidity,
	double ozone,
	Precipitation precipitation,
	double pressure,
	double visibility,
	math::RadialVelocity wind
) noexcept :
	cloudCover(cloudCover),
	dewPoint(dewPoint),
	humidity(humidity),
	overview(overview),
	ozone(ozone),
	precipitation(precipitation),
	pressure(pressure),
	time(time),
	visibility(visibility),
	wind(wind)

{

}

}

