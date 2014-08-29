#include "common/TimeWriter.hpp"

#include <memory>

namespace common
{

TimeWriter::TimeWriter(const char* format, size_t maxLength): format(format), maxLength(maxLength)
{

}

TimeWriter::TimeWriter(const TimeWriter& copyee) : TimeWriter(copyee.format, copyee.maxLength)
{
}

TimeWriter::~TimeWriter()
{

}

TimeWriter& TimeWriter::operator= (const TimeWriter& other)
{
	if (this != &other) // protect against invalid self-assignment
	{
		this->format = other.format;
		this->maxLength = other.maxLength;
	}
	// by convention, always return *this
	return *this;
}

void TimeWriter::write(const time_t& value, std::ostream& output)
{
	const struct tm* pTime = std::localtime(&value);
	write(pTime, output);

}

void TimeWriter::write(const struct tm* value, std::ostream& output)
{
	std::unique_ptr<char[]> pBuffer(new char[maxLength]);
	char* const rawpBuffer = pBuffer.get();
	std::strftime(rawpBuffer, maxLength, format, value);
	output << rawpBuffer;
}

}
