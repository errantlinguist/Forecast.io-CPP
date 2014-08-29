#ifndef TO_STRING_EXTENSION_HPP
#define TO_STRING_EXTENSION_HPP

#include <sstream>
#include <string>
#include <utility>
#include <unordered_map>
#include <vector>

// Include bug workaround for MinGW on Windows
#ifdef __MINGW32__
#include "to_string_mingw.hpp"
#endif

namespace common
{

static constexpr char CHAR_VALUE_DELIMITER = '\'';

static constexpr std::pair<char, char> COLLECTION_DELIMITERS('[', ']');

static constexpr std::pair<char, char> TUPLE_DELIMITERS('(', ')');

static const std::string SEQUENCE_ELEMENT_SEPARATOR = ", ";

static constexpr char STRING_VALUE_DELIMITER = '"';

template<typename T>
std::string to_string(const T& value)
{
	const std::string result = std::to_string(value);
	return result;
}

template<typename T>
std::string to_quoted_string(const T& value)
{
	return to_string(value);
}

template<size_t Size>
std::string to_quoted_string(const char (&value)[Size])
{
	std::stringstream ss(std::stringstream::out);

	ss << STRING_VALUE_DELIMITER;
	ss << value;
	ss << STRING_VALUE_DELIMITER;

	return ss.str();
}

template<typename L, typename R, typename LD, typename RD>
std::string to_string(const std::pair<L, R>& value,
		const std::pair<LD, RD>& delimiters)
{
	std::stringstream ss(std::stringstream::out);

	ss << delimiters.first << to_quoted_string(value.first)
			<< SEQUENCE_ELEMENT_SEPARATOR << to_quoted_string(value.second)
			<< delimiters.second;

	return ss.str();
}

template<typename L, typename R>
std::string to_string(const std::pair<L, R>& value)
{
	return to_string(value, TUPLE_DELIMITERS);
}

template<typename L, typename R, typename LD, typename RD>
std::string to_quoted_string(const std::pair<L, R>& value,
		const std::pair<LD, RD>& delimiters)
{
	return to_string(value, delimiters);
}

template<typename L, typename R>
std::string to_quoted_string(const std::pair<L, R>& value)
{
	return to_string(value);
}

template<typename C, typename LD, typename RD>
std::string to_collection_string(const C& value,
		const std::pair<LD, RD>& delimiters)
{
	std::stringstream ss(std::stringstream::out);
	ss << delimiters.first;

	auto iter = value.cbegin();
	if (iter != value.cend())
	{
		const std::string firstElementStr(to_quoted_string(*iter));
		ss << firstElementStr;	// Print the first element
		++iter;					// Increment to next element
	}
	for (; iter != value.cend(); ++iter)
	{
		const std::string nextElementStr(to_quoted_string(*iter));
		ss << nextElementStr;					// Print the next element
		ss << SEQUENCE_ELEMENT_SEPARATOR;	// Print separator
	}

	ss << delimiters.second;
	return ss.str();
}

template<typename C>
std::string to_collection_string(const C& value)
{
	return to_collection_string(value, COLLECTION_DELIMITERS);
}

// Template specializations -----------------------------------------------------
// STL Types
template<>
std::string to_quoted_string(const char& value);

template<>
std::string to_quoted_string(const std::string& value);

template<>
std::string to_string(const bool& value);

}

#endif // TO_STRING_EXTENSION_HPP
