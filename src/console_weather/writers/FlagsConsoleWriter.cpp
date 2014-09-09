#include "console_weather/writers/FlagsConsoleWriter.hpp"

#include "common/to_string.hpp"
#include "common/unordered_multimap.hpp"
#include "forecast_io/Flags.hpp"
#include "forecast_io/MeasurementSystemDefaultNameArrayHolder.hpp"

namespace console_weather
{
namespace writers
{

void FlagsConsoleWriter::write(const forecast_io::Flags& value, std::ostream& output)
{
	output << "Measurement system: ";
	static const forecast_io::MeasurementSystemNameArray& measurementNames = *forecast_io::MeasurementSystemDefaultNameArrayHolder::getInstance();
	const std::string measurementName =
			measurementNames[static_cast<size_t>(value.getUnits())];
	output << measurementName << '\n';

	output << "Dark Sky service is available: ";
	const std::string darkskyAvailableStr = common::to_string(
			!value.isDarkskyUnavailable());
	output << darkskyAvailableStr << '\n';

	output << "met.no license is present: ";
	const std::string metnoLicenseStr = common::to_string(
			value.hasMetnoLicense());
	output << metnoLicenseStr << '\n';

	const std::unordered_set<std::string>& sources = value.getSources();
	output << "Sources used: " << sources.size() << '\n';

	const std::unordered_multimap<std::string, std::string>& stations =
			value.getStations();
	output << "Stations used: " << stations.size() << '\n';

}

}
}

