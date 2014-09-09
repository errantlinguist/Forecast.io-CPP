#ifndef ABSTRACTJSONPARSER_HPP
#define ABSTRACTJSONPARSER_HPP

// json-c library: https://github.com/json-c/json-c/
#include <json-c/json.h>

namespace json
{

class AbstractJsonParser
{
public:

	AbstractJsonParser() = default;
	AbstractJsonParser(const AbstractJsonParser& copyee) = default;
    virtual ~AbstractJsonParser() = default;

    virtual AbstractJsonParser& operator= (const AbstractJsonParser& other) = default;

    virtual void parse(json_object* const & pJsonObj) = 0;

};

}

#endif // ABSTRACTJSONPARSER_HPP
