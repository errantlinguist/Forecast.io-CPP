#include "console_weather/writers/SynchronicDataPointConsoleWriter.hpp"

#include <ctime>

#include "console_weather/writers/console_writing.hpp"
#include "forecast_io/SynchronicDataPoint.hpp"

namespace console_weather
{
namespace writers
{

static constexpr const char* const AREA_DENSITY_UNITS = "DU";
static constexpr const char* const DEGREE_SYMBOL = "\u00B0";
static constexpr const char* const DISTANCE_UNITS = "mi";
static constexpr const char* const PRESSURE_UNITS = "mb";
static constexpr const char* const WINDSPEED_UNITS = "mph";
static constexpr char TEMPERATURE_UNITS = 'F';

template <typename B, typename D>
static void write(const math::RelativePosition<B, D>& value, std::ostream& output)
{
	output << "Bearing: " << value.getBearing() << DEGREE_SYMBOL << '\n';
	output << "Distance: " << value.getDistance() << ' ' << DISTANCE_UNITS << '\n';
}

static void write(const forecast_io::Precipitation& value, std::ostream& output)
{
	output << "Intensity: " << value.getIntensity() << '\n';
	output << "Probability: " << value.getProbability() << '\n';
	output << "Type: ";
	const std::string type = value.getType();
	if (type.empty())
	{
		output << "(none)";
	} else
	{
		output << type;
	}
	output << '\n';
}

static void write(const math::RadialVelocity& value, std::ostream& output)
{
	output << "Bearing: " << value.getDirection() << DEGREE_SYMBOL << '\n';
	output << "Speed: " << value.getMagnitude() << ' ' << WINDSPEED_UNITS << '\n';
}

SynchronicDataPointConsoleWriter::SynchronicDataPointConsoleWriter(int consoleWidth, common::TimeWriter timeWriter) :
	timeWriter(timeWriter),
	headerRowSeparator(createHeaderSeparator(SUBSECTION_HEADER_PADDING, consoleWidth)),
	nearestStormSectionHeader(createPaddedHeader("Nearest storm ", SUBSECTION_HEADER_PADDING, consoleWidth)),
	precipitationSectionHeader(createPaddedHeader("Precipitation ", SUBSECTION_HEADER_PADDING, consoleWidth)),
	windSectionHeader(createPaddedHeader("Wind ", SUBSECTION_HEADER_PADDING, consoleWidth))
{
}

// Members ----------------------------------------------------------------------

void SynchronicDataPointConsoleWriter::write(const forecast_io::SynchronicDataPoint& value, std::ostream& output)
{
	const forecast_io::SingleDataPoint& baseDataPoint = value.getBaseDataPoint();
	write(baseDataPoint, output);
	const math::RelativePosition<double, double>& nearestStorm = value.getNearestStorm();
	output << nearestStormSectionHeader << '\n';
	writers::write(nearestStorm, output);
	output << headerRowSeparator << '\n';
}

void SynchronicDataPointConsoleWriter::write(const forecast_io::DataPoint& value, std::ostream& output)
{
	output << "Time: ";
	const time_t time = value.getTime();
	timeWriter.write(time, output);
	output << '\n';

	const forecast_io::DataOverview& overview = value.getOverview();
	output << "Summary: " << overview.getSummary() << '\n';
	output << headerRowSeparator << '\n';
	// TODO: Finish console writer for DataPoint
	output << "Cloud cover: " << value.getCloudCover() << '\n';
	output << "Dew point: " << value.getDewPoint() << DEGREE_SYMBOL << ' ' << TEMPERATURE_UNITS << '\n';
	output << "Humidity: " << value.getHumidity() << '\n';
	output << "Ozone: " << value.getOzone() << ' ' << AREA_DENSITY_UNITS << '\n';

	const forecast_io::Precipitation& precipitation = value.getPrecipitation();
	output << precipitationSectionHeader << '\n';
	writers::write(precipitation, output);
	output << headerRowSeparator << '\n';

	output << "Pressure: " << value.getPressure() << ' ' << PRESSURE_UNITS << '\n';
	output << "Visibility: " << value.getVisibility() << ' ' << DISTANCE_UNITS << '\n';

	output << windSectionHeader << '\n';
	const math::RadialVelocity& wind = value.getWind();
	writers::write(wind,output);
	output << headerRowSeparator << '\n';
}

void SynchronicDataPointConsoleWriter::write(const forecast_io::SingleDataPoint& value, std::ostream& output)
{
	const forecast_io::DataPoint& baseDataPoint = value.getBaseDataPoint();
	write(baseDataPoint, output);
	output << "Temperature: " << value.getTemperature() << DEGREE_SYMBOL << ' ' << TEMPERATURE_UNITS << '\n';
	output << "Apparent temperature: " << value.getApparentTemperature() << DEGREE_SYMBOL << ' ' << TEMPERATURE_UNITS << '\n';
}

void SynchronicDataPointConsoleWriter::write(const time_t value, std::ostream& output)
{
	// TODO: Finish this?
}


}
}

