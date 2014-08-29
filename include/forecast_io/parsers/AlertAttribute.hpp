#ifndef ALERTATTRIBUTE_HPP
#define ALERTATTRIBUTE_HPP

#include <string>

namespace forecast_io
{
namespace parsers
{

const std::string AlertAttribute_NAME = "AlertAttribute";

enum AlertAttribute
{
	DESCRIPTION,
	EXPIRY_TIME,
	TITLE,
	URI,

	AlertAttribute_MAX = URI,
	AlertAttribute_COUNT = AlertAttribute_MAX + 1
};

// Typedefs
typedef std::unordered_map<std::string, AlertAttribute> AlertAttributeNameMap;

}
}

#endif // ALERTATTRIBUTE_HPP
