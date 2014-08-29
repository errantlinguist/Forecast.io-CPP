#ifndef JSONMAPS_HPP
#define JSONMAPS_HPP

#include <string>

// json-c library: https://github.com/json-c/json-c/
#include <json-c/json.h>

namespace json
{

template<typename M, typename K>
void insertJsonStringArrayValues(
		M& multimap, const K& key,
		json_object* const & pArray)
{
	const int arrayLength = json_object_array_length(pArray);
	for (int i = 0; i < arrayLength; ++i)
	{
		json_object* const & arrayElement = json_object_array_get_idx(pArray,
				i);
		const std::string& value = json_object_get_string(arrayElement);
		const typename M::value_type newPair(key, value);
		multimap.insert(newPair);
	}

}

template<typename C>
void insertJsonStringArrayValues(C& collection, json_object* const & pArray)
{
	const int arrayLength = json_object_array_length(pArray);
	for (int i = 0; i < arrayLength; ++i)
	{
		json_object* const & arrayElement = json_object_array_get_idx(pArray,
				i);
		const std::string& element = json_object_get_string(arrayElement);
		collection.insert(element);
	}

}

}

#endif // JSONMAPS_HPP
