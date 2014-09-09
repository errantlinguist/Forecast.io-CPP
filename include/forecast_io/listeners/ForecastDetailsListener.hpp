#ifndef FORECASTDETAILSLISTENER_HPP
#define FORECASTDETAILSLISTENER_HPP

#include <string>

namespace forecast_io
{
namespace listeners
{

class ForecastDetailsListener
{
public:

	virtual ~ForecastDetailsListener() = default;

	virtual void notifyLatitude(double latitude);
	virtual void notifyLongitude(double longitude);
	virtual void notifyTimezone(const std::string& timezone);
	virtual void notifyOffset(signed char offset);

};

}
}

#endif // FORECASTDETAILSLISTENER_HPP
