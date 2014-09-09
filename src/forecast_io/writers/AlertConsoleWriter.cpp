#include "forecast_io/writers/AlertConsoleWriter.hpp"

#include <sstream>

#include "forecast_io/Alert.hpp"
#include "forecast_io/writers/console_writing.hpp"

namespace forecast_io
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

void AlertConsoleWriter::write(const Alert& value, std::ostream& output)
{
	output << value.getTitle() << '\n';
	output << headerSeparator << '\n';
	output << value.getDescription();
	output << "\nFor more information see " << value.getUri() << '\n';
}

}

}

