#ifndef FLAGSCONSOLEWRITER_HPP
#define FLAGSCONSOLEWRITER_HPP

#include "../../common/AbstractStreamWriter.hpp" // Base class: AbstractStreamWriter

namespace forecast_io
{

// Forward declarations
class Flags;

namespace writers
{

class FlagsConsoleWriter: public common::AbstractStreamWriter<Flags>
{

public:

	virtual ~FlagsConsoleWriter();

	virtual void write(const Flags& value, std::ostream& output);
};

}

}

#endif // FLAGSCONSOLEWRITER_HPP
