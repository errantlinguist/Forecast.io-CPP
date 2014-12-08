#ifndef SYNCHRONICDATAPOINTCONSOLEWRITER_HPP
#define SYNCHRONICDATAPOINTCONSOLEWRITER_HPP

#include <string>

#include "../../common/TimeWriter.hpp"

// Forward declarations
namespace forecast_io
{
class DataPoint;
class SingleDataPoint;
class SynchronicDataPoint;
}

namespace console_weather
{
namespace writers
{

static const common::TimeWriter DEFAULT_TIME_WRITER("%c", 48);

class SynchronicDataPointConsoleWriter
{
public:
	SynchronicDataPointConsoleWriter(int consoleWidth, common::TimeWriter timeWriter = DEFAULT_TIME_WRITER) noexcept;

	void write(const forecast_io::SynchronicDataPoint& value, std::ostream& output);

private:

	void write(const forecast_io::DataPoint& value, std::ostream& output);
	void write(const forecast_io::SingleDataPoint& value, std::ostream& output);

	common::TimeWriter timeWriter;
	std::string headerRowSeparator;
	std::string nearestStormSectionHeader;
	std::string precipitationSectionHeader;
	std::string windSectionHeader;

};

}
}

#endif // SYNCHRONICDATAPOINTCONSOLEWRITER_HPP
