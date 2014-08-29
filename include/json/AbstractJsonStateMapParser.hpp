#ifndef ABSTRACTJSONSTATEMAPPARSER_HPP
#define ABSTRACTJSONSTATEMAPPARSER_HPP

#include "AbstractJsonParser.hpp" // Base class: json::AbstractJsonParser

#include <sstream>
#include <string>
#include <unordered_map>

#include "ParseError.hpp"
#include "../common/to_string.hpp"

namespace json
{

template<typename A>
class AbstractJsonStateMapParser: public AbstractJsonParser
{
public:

	AbstractJsonStateMapParser(
			const std::unordered_map<std::string, A>& attributeNames) :
			attributeNames(attributeNames)
	{
	}

	void parse(json_object* const & pJsonObj)
	{
		// Parse JSON data values
		json_object_object_foreach(pJsonObj, key, value)
		{
			parseAttribute(key, value);
		}

		finishParse();
	}

protected:

	static std::string createUndefinedAttributeErrorMessage(
			const std::string& attributeType, const A& attribute)
	{
		std::stringstream errorMessage(std::stringstream::out);
		errorMessage << "No parsing logic for " << attributeType << " value "
				<< common::to_quoted_string(attribute) << " is defined.";
		return errorMessage.str();
	}

	static std::string createUnknownAttributeErrorMessage(
			const std::string& key)
	{
		std::stringstream errorMessage(std::stringstream::out);
		errorMessage << "Unknown JSON attribute name encountered: " << key;
		return errorMessage.str();
	}

	virtual void finishParse()
	{
		// By default do nothing
	}

	virtual void handleUnmappedAttribute(const std::string& key, json_object* const & pValue)
	{
		(void)pValue;
		throw json::ParseError(createUnknownAttributeErrorMessage(key));
	}

	virtual void parseAttribute(const A& attribute, json_object* const & pValue) = 0;

private:

	const std::unordered_map<std::string, A>& attributeNames;

	void parseAttribute(const std::string& key, json_object* const & pValue)
	{
		auto iter = attributeNames.find(key);
		if (iter == attributeNames.end())
		{
			handleUnmappedAttribute(key, pValue);
		}
		else
		{
			const A& attribute = iter->second;
			parseAttribute(attribute, pValue);
		}
	}

};

}

#endif // ABSTRACTJSONSTATEMAPPARSER_HPP
