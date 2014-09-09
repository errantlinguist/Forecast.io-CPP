#ifndef TIMEWRITER_HPP
#define TIMEWRITER_HPP

#include <ctime>
#include <ostream>

namespace common
{

class TimeWriter
{
public:
	TimeWriter(const char* format, size_t maxLength);
	TimeWriter(const TimeWriter& copyee) = default;
	virtual ~TimeWriter() = default;

	virtual TimeWriter& operator= (const TimeWriter& other) = default;

	virtual void write(const time_t& value, std::ostream& output);

	virtual void write(const struct tm* value, std::ostream& output);

private:

	const char* format;
	size_t maxLength;
};

}

#endif // TIMEWRITER_HPP
