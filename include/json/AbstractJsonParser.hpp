#ifndef ABSTRACTJSONPARSER_HPP
#define ABSTRACTJSONPARSER_HPP

// json-c library: https://github.com/json-c/json-c/
#include <json-c/json.h>

namespace json
{

class AbstractJsonParser
{
public:

    virtual ~AbstractJsonParser() = default;

    virtual void parse(json_object* const & pJsonObj) = 0;

};

}

#endif // ABSTRACTJSONPARSER_HPP
