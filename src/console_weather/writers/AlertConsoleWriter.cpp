#include "console_weather/writers/AlertConsoleWriter.hpp"

#include <sstream>

#include "console_weather/writers/console_writing.hpp"
#include "forecast_io/Alert.hpp"

namespace console_weather
{
namespace writers
{

AlertConsoleWriter::AlertConsoleWriter(int consoleWidth) :
	headerSeparator(createHeaderSeparator('-',
		consoleWidth / 2))
{
	// ctor
}

// Members ----------------------------------------------------------------------

void AlertConsoleWriter::write(const forecast_io::Alert& value, std::ostream& output)
{
	output << value.getTitle() << '\n';
	output << headerSeparator << '\n';
	output << value.getDescription();
	output << "\nFor more information see " << value.getUri() << '\n';
}

}
}

