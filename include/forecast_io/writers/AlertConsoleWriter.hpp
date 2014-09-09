#ifndef ALERTCONSOLEWRITER_HPP
#define ALERTCONSOLEWRITER_HPP

#include "../../common/AbstractStreamWriter.hpp" // Base class: AbstractStreamWriter

#include <string>

namespace forecast_io
{

// Forward declarations
class Alert;

namespace writers
{

class AlertConsoleWriter: public common::AbstractStreamWriter<Alert>
{
public:

	AlertConsoleWriter(int consoleWidth);

	void write(const Alert& value, std::ostream& output);

private:

	std::string headerSeparator;

};

}

}

#endif // ALERTCONSOLEWRITER_HPP
