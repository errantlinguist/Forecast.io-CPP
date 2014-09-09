#include "console_weather/writers/console_writing.hpp"

#include <cassert>
#include <iomanip>
#include <limits>

namespace console_weather
{
namespace writers
{

static constexpr size_t MAX_PREFIX_LENGTH = static_cast<size_t>(std::numeric_limits<int>::max());

static int getPaddingLength(const std::string& prefix, int resultLength)
{
	const size_t prefixLength = prefix.size();
	assert(prefixLength <= MAX_PREFIX_LENGTH);
	const int castPrefixLength = static_cast<int>(prefixLength);
	assert(castPrefixLength <= resultLength);
	return resultLength - castPrefixLength;
}

std::string createPaddedHeader(const std::string& prefix,
		const std::stringstream::char_type paddingSymbol, int resultLength)
{
	const int paddingLength = getPaddingLength(prefix, resultLength);

	std::stringstream ss(std::stringstream::out);
	ss << prefix;
	ss << std::setfill(paddingSymbol) << std::setw(paddingLength) << "";
	return ss.str();
}

std::string createHeaderSeparator(const std::stringstream::char_type symbol, int times)
{
	std::stringstream ss(std::stringstream::out);
	ss << std::setfill(symbol) << std::setw(times) << "";
	return ss.str();
}

}
}
