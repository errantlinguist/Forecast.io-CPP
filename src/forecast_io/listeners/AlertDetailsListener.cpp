#include "forecast_io/listeners/AlertDetailsListener.hpp"

namespace forecast_io
{
namespace listeners
{

void AlertDetailsListener::notifyTitle(const std::string& title) { (void)title; /*Avoid "unused parameter" warning*/ }
void AlertDetailsListener::notifyExpiryTime(time_t expiryTime) { (void)expiryTime; /*Avoid "unused parameter" warning*/ }
void AlertDetailsListener::notifyDescription(const std::string& description) { (void)description; /*Avoid "unused parameter" warning*/ }
void AlertDetailsListener::notifyUri(const std::string& uri) { (void)uri; /*Avoid "unused parameter" warning*/ }

}
}
