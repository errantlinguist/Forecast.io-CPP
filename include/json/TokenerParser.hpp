#ifndef TOKENERPARSER_HPP
#define TOKENERPARSER_HPP

#include <cstddef>
#include <istream>

#include "AbstractJsonParser.hpp"

// Forward declarations
struct json_tokener;

namespace json
{

class TokenerParser
{
public:
	TokenerParser(AbstractJsonParser& parser);
	virtual ~TokenerParser();

	/**
	* Parses a given character array as input.
	*
	* @param[in] input The character array to parse.
	* @param[in] inputLength The input array length.
	* @throw ParseException If there was an error while parsing the input as JSON.
	*/
	void parse(const char* const & input, int inputLength);

	/**
	 * Parses data from a given input stream using a given character array as a buffer.
	 *
	 * @param[in] input The stream to parse.
	 * @param[in] pBuffer The array to use as a buffer for the stream input.
	 * @param[in] bufferSize The size of the given buffer.
	 * @return The amount of bytes processed.
	 * @throw ParseException If there was an error while parsing the input as JSON.
	 */
	std::streamsize parse(std::istream& input, char* pBuffer,
			int bufferSize);

	AbstractJsonParser& getParser()
	{
		return parser;
	}

	const AbstractJsonParser& getParser() const
	{
		return parser;
	}

	void setParser(AbstractJsonParser& parser)
	{
		this->parser = parser;
	}

private:

	json_tokener* const pTokener;
	AbstractJsonParser& parser;

};

}

#endif // TOKENERPARSER_HPP
