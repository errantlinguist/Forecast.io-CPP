#include "json/TokenerParser.hpp"

#include <sstream>

// json-c library: https://github.com/json-c/json-c/
#include <json-c/json.h>

#include "json/ParseError.hpp"

namespace json
{

TokenerParser::TokenerParser(AbstractJsonParser& parser) :
		pTokener(json_tokener_new()), parser(parser)
{

}

TokenerParser::~TokenerParser()
{
	json_tokener_free(pTokener);
}

void TokenerParser::parse(const char* const & input, int inputLength)
{
	json_object* const pJsonObj = json_tokener_parse_ex(pTokener, input, inputLength);
	const json_tokener_error parseErrorCode = json_tokener_get_error(pTokener);
	if (json_tokener_continue != parseErrorCode)
	{
		if (json_tokener_success == parseErrorCode)
		{
			parser.parse(pJsonObj);
		}
		else
		{
			std::stringstream errorMessage(std::stringstream::out);
			errorMessage << "Error code" << parseErrorCode
					<< " while parsing JSON.";
			throw json::ParseError(errorMessage.str());
		}
	}
}

std::streamsize TokenerParser::parse(std::istream& input, char* pBuffer,
		int bufferSize)
{
	std::streamsize result(0);

	while (input.read(pBuffer, bufferSize))
	{
		result += input.gcount();
		parse(pBuffer, bufferSize);
	}
	// Add the number of bytes read for the final read attempt
	result += input.gcount();
	// Parse any remaining tokens
	parse(pBuffer, bufferSize);

	return result;
}

}
