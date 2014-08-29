#include "forecast_io/writers/ForecastConsoleWriter.hpp"

#include <iomanip>
#include <vector>

#include "forecast_io/Alert.hpp"
#include "forecast_io/Forecast.hpp"
#include "forecast_io/writers/console_writing.hpp"
#include "math/Coordinate.hpp"

namespace forecast_io
{

namespace writers
{

ForecastConsoleWriter::ForecastConsoleWriter(int consoleWidth) :
	alertWriter(consoleWidth),
	synchronicDataPointWriter(consoleWidth),
	alertsSectionHeader(createPaddedHeader("ALERTS ", MAIN_SECTION_HEADER_PADDING, consoleWidth)),
	currentWeatherSectionHeader(createPaddedHeader("CURRENT WEATHER ", MAIN_SECTION_HEADER_PADDING, consoleWidth)),
	flagsSectionHeader(createPaddedHeader("FLAGS ", MAIN_SECTION_HEADER_PADDING, consoleWidth)),
	headerRowSeparator(createHeaderSeparator(SUBSECTION_HEADER_PADDING, consoleWidth))
{

}

ForecastConsoleWriter::~ForecastConsoleWriter()
{

}

// Members ----------------------------------------------------------------------

void ForecastConsoleWriter::write(const Forecast& value, std::ostream& output)
{
	output << "Forecast for location at coordinates ";
	// FIXME: The coordinate values are always zero here
	const math::Coordinate location = value.getLocation();
	output << location << '\n';

	output << headerRowSeparator << '\n';

	// Timezone and offset
	const std::string timezone = value.getTimezone();
	output << "Timezone: \"" << timezone << "\" (Offset: ";
	const short offsetNumericValue = static_cast<const short>(value.getOffset());
	output << offsetNumericValue;
	output << " hrs.)\n";

	// Alerts
	const std::vector<Alert>& alerts = value.getAlerts();
	if (!alerts.empty())
	{
		output << alertsSectionHeader << '\n';
		write(alerts, output);
	}

	// Current forecast data
	output << currentWeatherSectionHeader << '\n';
	const SynchronicDataPoint& currentWeather = value.getCurrentWeather();
	synchronicDataPointWriter.write(currentWeather, output);
	output << '\n';

	// Flags
	output << flagsSectionHeader << '\n';
	flagsWriter.write(value.getFlags(), output);

}

template<typename C>
void ForecastConsoleWriter::write(const C& alerts, std::ostream& output)
{
	for (const Alert& alert : alerts)
	{
		alertWriter.write(alert, output);
		output << '\n';
	}
}

}

}

