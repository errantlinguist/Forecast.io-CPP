#include "forecast_io/listeners/SynchronicDataPointDetailsListener.hpp"

namespace forecast_io
{

namespace listeners
{

void SynchronicDataPointDetailsListener::notifyNearestStormBearing(double bearing) { (void)bearing; /*Avoid "unused parameter" warning*/ }
void SynchronicDataPointDetailsListener::notifyNearestStormDistance(double distance) { (void)distance; /*Avoid "unused parameter" warning*/ }

}

}
