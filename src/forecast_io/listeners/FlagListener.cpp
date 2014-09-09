#include "forecast_io/listeners/FlagListener.hpp"


namespace forecast_io
{
namespace listeners
{

void FlagListener::notifyDarkskyUnavailable(bool darkskyUnavailable) { (void)darkskyUnavailable; /*Avoid "unused parameter" warning*/ }
void FlagListener::notifySources(std::unordered_set<std::string>& sources) { (void)sources; /*Avoid "unused parameter" warning*/ }
void FlagListener::notifyStations(
	std::unordered_multimap<std::string, std::string>& stations) { (void)stations; /*Avoid "unused parameter" warning*/ }
void FlagListener::notifyMetnoLicense(bool metnoLicense) { (void)metnoLicense; /*Avoid "unused parameter" warning*/ }
void FlagListener::notifyUnits(math::MeasurementSystem units) { (void)units; /*Avoid "unused parameter" warning*/ }

}
}
