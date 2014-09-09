#ifndef ALERTSLISTENER_HPP
#define ALERTSLISTENER_HPP

namespace forecast_io
{

// Forward declarations
class Alert;

namespace listeners
{

class AlertsListener
{
public:

	virtual ~AlertsListener() = default;

	virtual void notifyAlert(Alert& alert);

};

}
}

#endif // ALERTSLISTENER_HPP
