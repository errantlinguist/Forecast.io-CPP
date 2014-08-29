#include "json/AbstractJsonParser.hpp"

namespace json
{

AbstractJsonParser::AbstractJsonParser()
{
}

AbstractJsonParser::AbstractJsonParser(const AbstractJsonParser& copyee) : AbstractJsonParser()
{
}

AbstractJsonParser::~AbstractJsonParser() {}

AbstractJsonParser& AbstractJsonParser::operator= (const AbstractJsonParser& other)
{
    // by convention, always return *this
    return *this;
}

}
