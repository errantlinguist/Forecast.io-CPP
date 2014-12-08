#ifndef FORECASTCONSOLEWRITER_HPP
#define FORECASTCONSOLEWRITER_HPP

#include <string>

#include "AlertConsoleWriter.hpp"
#include "FlagsConsoleWriter.hpp"
#include "SynchronicDataPointConsoleWriter.hpp"

// Forward declarations
namespace forecast_io
{

class Forecast;
}

namespace console_weather
{
namespace writers
{

class ForecastConsoleWriter
{
public:

	ForecastConsoleWriter(int consoleWidth) noexcept;

	void write(const forecast_io::Forecast& value, std::ostream& output);

private:

	AlertConsoleWriter alertWriter;
	FlagsConsoleWriter flagsWriter;
	SynchronicDataPointConsoleWriter synchronicDataPointWriter;

	std::string alertsSectionHeader;
	std::string currentWeatherSectionHeader;
	std::string flagsSectionHeader;
	std::string headerRowSeparator;

	template<typename C>
	void write(const C& alerts, std::ostream& output);

};

}
}

#endif // FORECASTCONSOLEWRITER_HPP
