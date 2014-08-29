#include "forecast_io/DataPoint.hpp"

namespace forecast_io
{

DataPoint::DataPoint()
:
	DataPoint(0,
	DataOverview(),
	0.0,
	0.0,
	0.0,
	0.0,
	Precipitation(),
	0.0,
	0.0,
	math::RadialVelocity())
{
}

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
) :
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

