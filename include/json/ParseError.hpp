#ifndef PARSEERROR_HPP
#define PARSEERROR_HPP

#include <stdexcept> // Base class: std::runtime_error

#include <string>

namespace json
{

/*
FIXME: Compiler warning "'ParseError' has no out-of-line virtual method definitions; its vtable will be emitted in every translation unit [-Wweak-vtables]|"
*/
class ParseError: public std::runtime_error
{
public:

	ParseError(const std::string& what_arg);
	ParseError(const char* what_arg);

};

}

#endif // PARSEERROR_HPP
