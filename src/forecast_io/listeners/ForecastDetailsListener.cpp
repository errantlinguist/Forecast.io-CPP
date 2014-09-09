#include "forecast_io/listeners/ForecastDetailsListener.hpp"

namespace forecast_io
{
namespace listeners
{

void ForecastDetailsListener::notifyLatitude(double latitude) { (void)latitude; /*Avoid "unused parameter" warning*/ }
void ForecastDetailsListener::notifyLongitude(double longitude) { (void)longitude; /*Avoid "unused parameter" warning*/ }
void ForecastDetailsListener::notifyTimezone(const std::string& timezone) { (void)timezone; /*Avoid "unused parameter" warning*/ }
void ForecastDetailsListener::notifyOffset(signed char offset) { (void)offset; /*Avoid "unused parameter" warning*/}

}
}

