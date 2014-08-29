#include "forecast_io/listeners/ForecastDetailsListener.hpp"

namespace forecast_io
{
namespace listeners
{

ForecastDetailsListener::~ForecastDetailsListener() {}

void ForecastDetailsListener::notifyLatitude(double latitude) {}
void ForecastDetailsListener::notifyLongitude(double longitude) {}
void ForecastDetailsListener::notifyTimezone(const std::string& timezone) {}
void ForecastDetailsListener::notifyOffset(signed char offset) {}

}
}

