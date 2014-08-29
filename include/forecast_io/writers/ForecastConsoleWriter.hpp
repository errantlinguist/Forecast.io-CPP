#ifndef FORECASTCONSOLEWRITER_HPP
#define FORECASTCONSOLEWRITER_HPP

#include "../../common/AbstractStreamWriter.hpp" // Base class: AbstractStreamWriter

#include <string>

#include "AlertConsoleWriter.hpp"
#include "FlagsConsoleWriter.hpp"
#include "SynchronicDataPointConsoleWriter.hpp"

namespace forecast_io
{

// Forward declarations
class Forecast;

namespace writers
{

class ForecastConsoleWriter: public common::AbstractStreamWriter<Forecast>
{
public:

	ForecastConsoleWriter(int consoleWidth);
	virtual ~ForecastConsoleWriter();

	void write(const Forecast& value, std::ostream& output);

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
