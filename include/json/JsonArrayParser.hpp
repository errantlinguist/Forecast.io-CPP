#ifndef JSONARRAYPARSER_HPP
#define JSONARRAYPARSER_HPP

#include "AbstractJsonParser.hpp" // Base class: json::AbstractJsonParser

namespace json
{

template<typename P>
class JsonArrayParser: public AbstractJsonParser
{
public:

	JsonArrayParser(P& elementParser) :
		elementParser(elementParser) {}

	virtual void parse(json_object* const& pJsonObj)
	{
		const int arrayLength = json_object_array_length(pJsonObj);
		for(int i = 0; i < arrayLength; ++i)
		{
			json_object* const& arrayElement = json_object_array_get_idx(
												   pJsonObj, i);
			handleArrayElement(arrayElement);
		}

		finishParse();
	}

	const P& getElementParser() const
	{
		return elementParser;
	}
	P& getElementParser()
	{
		return elementParser;
	}

protected:

	virtual void finishParse()
	{
		// By default do nothing
	}

	virtual void handleArrayElement(json_object* const& arrayElement)
	{
		elementParser.parse(arrayElement);
	}

private:

	P& elementParser;

};

}

#endif // JSONARRAYPARSER_HPP
