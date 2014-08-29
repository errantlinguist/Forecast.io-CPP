#include "forecast_io/parsers/FlagsAttributeDefaultNameMapHolder.hpp"

namespace forecast_io
{
namespace parsers
{

static void insertDefaultAttributeNames(FlagsAttributeNameMap& attributeNames)
{
	attributeNames["darksky-unavailable"] = FlagsAttribute::DARKSKY_UNAVAILABLE;
	attributeNames["metno-license"] = FlagsAttribute::METNO_LICENSE;
	attributeNames["sources"] = FlagsAttribute::SOURCES;
	attributeNames["units"] = FlagsAttribute::UNITS;
}

std::unique_ptr<FlagsAttributeNameMap> FlagsAttributeDefaultNameMapHolder::pInstance = nullptr;

std::unique_ptr<FlagsAttributeNameMap> FlagsAttributeDefaultNameMapHolder::createInstance()
{
	std::unique_ptr<FlagsAttributeNameMap> result(
			new FlagsAttributeNameMap(
					FlagsAttribute::FlagsAttribute_COUNT));
	insertDefaultAttributeNames(*result);
	return result;
}

}
}
