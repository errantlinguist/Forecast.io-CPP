#ifndef SYNCHRONICDATAPOINTCONSOLEWRITER_HPP
#define SYNCHRONICDATAPOINTCONSOLEWRITER_HPP

#include "../../common/AbstractStreamWriter.hpp" // Base class: AbstractStreamWriter

#include <string>

#include "../../common/TimeWriter.hpp"

namespace forecast_io
{

// Forward declarations
class DataPoint;
class SingleDataPoint;
class SynchronicDataPoint;

namespace writers
{

static const common::TimeWriter DEFAULT_TIME_WRITER("%c", 48);

class SynchronicDataPointConsoleWriter: public common::AbstractStreamWriter<SynchronicDataPoint>
{
public:
	SynchronicDataPointConsoleWriter(int consoleWidth, common::TimeWriter timeWriter = DEFAULT_TIME_WRITER);

	void write(const SynchronicDataPoint& value, std::ostream& output);

private:

	void write(const DataPoint& value, std::ostream& output);
	void write(const SingleDataPoint& value, std::ostream& output);
	void write(const time_t value, std::ostream& output);

	common::TimeWriter timeWriter;
	std::string headerRowSeparator;
	std::string nearestStormSectionHeader;
	std::string precipitationSectionHeader;
	std::string windSectionHeader;

};

}

}

#endif // SYNCHRONICDATAPOINTCONSOLEWRITER_HPP
