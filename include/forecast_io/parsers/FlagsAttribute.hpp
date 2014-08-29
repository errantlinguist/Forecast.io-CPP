#ifndef FLAGSATTRIBUTE_HPP
#define FLAGSATTRIBUTE_HPP

#include <string>

namespace forecast_io
{
namespace parsers
{

const std::string FlagsAttribute_NAME = "FlagsAttribute";

enum FlagsAttribute
{
	DARKSKY_UNAVAILABLE,
	METNO_LICENSE,
	SOURCES,
	UNITS,
	FlagsAttribute_MAX = UNITS,
	FlagsAttribute_COUNT = FlagsAttribute_MAX + 1
};

// Typedefs
typedef std::unordered_map<std::string, FlagsAttribute> FlagsAttributeNameMap;

}

}

#endif // FLAGSATTRIBUTE_HPP
