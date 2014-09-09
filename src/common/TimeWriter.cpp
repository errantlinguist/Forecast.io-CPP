#include "common/TimeWriter.hpp"

#include <memory>

namespace common
{

TimeWriter::TimeWriter(const char* format, size_t maxLength): format(format), maxLength(maxLength)
{

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
