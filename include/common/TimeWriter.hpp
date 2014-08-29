#ifndef TIMEWRITER_HPP
#define TIMEWRITER_HPP

#include <ctime>

#include "AbstractStreamWriter.hpp" // Base class: common::AbstractStreamWriter

namespace common
{

class TimeWriter : public common::AbstractStreamWriter<time_t>
{
public:
	TimeWriter(const char* format, size_t maxLength);
	TimeWriter(const TimeWriter& copyee);
	virtual ~TimeWriter();

	virtual TimeWriter& operator= (const TimeWriter& other);

	virtual void write(const time_t& value, std::ostream& output);

	virtual void write(const struct tm* value, std::ostream& output);

private:

	const char* format;
	size_t maxLength;
};

}

#endif // TIMEWRITER_HPP
