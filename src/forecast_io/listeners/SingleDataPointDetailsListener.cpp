#include "forecast_io/listeners/SingleDataPointDetailsListener.hpp"


namespace forecast_io
{
namespace listeners
{

void SingleDataPointDetailsListener::notifyApparentTemperature(double temperature) { (void)temperature; /*Avoid "unused parameter" warning*/ }
void SingleDataPointDetailsListener::notifyTemperature(double temperature) { (void)temperature; /*Avoid "unused parameter" warning*/ }

}
}
