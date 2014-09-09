#include "forecast_io/writers/FlagsConsoleWriter.hpp"

#include "common/to_string.hpp"
#include "common/unordered_multimap.hpp"
#include "forecast_io/Flags.hpp"
#include "forecast_io/MeasurementSystemDefaultNameArrayHolder.hpp"

#include <array>
#include <unordered_set>

namespace forecast_io
{

namespace writers
{

void FlagsConsoleWriter::write(const Flags& value, std::ostream& output)
{
	output << "Measurement system: ";
	static const MeasurementSystemNameArray& measurementNames = *MeasurementSystemDefaultNameArrayHolder::getInstance();
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

