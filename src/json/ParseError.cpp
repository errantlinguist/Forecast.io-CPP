#include "json/ParseError.hpp"

namespace json
{


ParseError::ParseError(const std::string& what_arg) :
		runtime_error(what_arg)
{
}

ParseError::ParseError(const char* what_arg) :
		runtime_error(what_arg)
{
}

}
