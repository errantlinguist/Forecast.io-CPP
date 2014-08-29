#include "forecast_io/listeners/AlertDetailsListener.hpp"

namespace forecast_io
{
namespace listeners
{

AlertDetailsListener::~AlertDetailsListener() {}

void AlertDetailsListener::notifyTitle(const std::string& title) {}
void AlertDetailsListener::notifyExpiryTime(time_t expiryTime) {}
void AlertDetailsListener::notifyDescription(const std::string& description) {}
void AlertDetailsListener::notifyUri(const std::string& uri) {}

}
}
