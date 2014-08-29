#include "common/to_string.hpp"

namespace common
{

template<>
std::string to_quoted_string(const char& value)
{
	std::stringstream ss(std::stringstream::out);

	ss << CHAR_VALUE_DELIMITER;
	ss << value;
	ss << CHAR_VALUE_DELIMITER;

	return ss.str();
}

template<>
std::string to_quoted_string(const std::string& value)
{
	std::stringstream ss(std::stringstream::out);

	ss << STRING_VALUE_DELIMITER;
	ss << value;
	ss << STRING_VALUE_DELIMITER;

	return ss.str();
}

template<>
std::string to_string(const bool& value)
{
	return (value ? "true" : "false");
}

}
