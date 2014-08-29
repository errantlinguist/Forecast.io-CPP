#include "forecast_io/listeners/AlertsListener.hpp"

namespace forecast_io
{

// Forward declarations
class Alert;

namespace listeners
{

AlertsListener::~AlertsListener() {}

void AlertsListener::notifyAlert(Alert& alert) {}

}
}
