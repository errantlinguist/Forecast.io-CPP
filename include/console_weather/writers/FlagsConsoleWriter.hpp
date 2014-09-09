#ifndef FLAGSCONSOLEWRITER_HPP
#define FLAGSCONSOLEWRITER_HPP

#include <ostream>

// Forward declarations
namespace forecast_io
{
class Flags;
}

namespace console_weather
{
namespace writers
{

class FlagsConsoleWriter
{

public:

	virtual void write(const forecast_io::Flags& value, std::ostream& output);
};

}
}

#endif // FLAGSCONSOLEWRITER_HPP
