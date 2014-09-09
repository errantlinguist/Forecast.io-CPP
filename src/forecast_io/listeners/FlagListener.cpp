#include "forecast_io/listeners/FlagListener.hpp"


namespace forecast_io
{
namespace listeners
{

void FlagListener::notifyDarkskyUnavailable(bool darkskyUnavailable) {}
void FlagListener::notifySources(std::unordered_set<std::string>& sources) {}
void FlagListener::notifyStations(
	std::unordered_multimap<std::string, std::string>& stations) {}
void FlagListener::notifyMetnoLicense(bool metnoLicense) {}
void FlagListener::notifyUnits(math::MeasurementSystem units) {}

}
}
