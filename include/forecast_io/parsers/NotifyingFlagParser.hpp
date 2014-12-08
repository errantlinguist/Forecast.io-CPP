#ifndef NOTIFYINGFLAGPARSER_HPP
#define NOTIFYINGFLAGPARSER_HPP

#include <cstddef>
#include <unordered_set>

#include "../../json/AbstractJsonStateMapParser.hpp" // Base class: json::AbstractJsonStateMapParser
#include "../../common/Notifier.hpp" // Base class: Notifier

#include "FlagsAttribute.hpp"
#include "FlagsAttributeDefaultNameMapHolder.hpp"
#include "../MeasurementSystemDefaultAttributeValueMapHolder.hpp"

// Forward declarations
namespace math
{
enum class MeasurementSystem: size_t;
}

namespace forecast_io
{

// Forward declaration
namespace listeners
{
class FlagListener;
}

namespace parsers
{

class NotifyingFlagParser: public json::AbstractJsonStateMapParser<
		FlagsAttribute>, public common::Notifier<listeners::FlagListener>
{
public:
	NotifyingFlagParser(listeners::FlagListener* pListener,
			const FlagsAttributeNameMap& attributeNames =
					*FlagsAttributeDefaultNameMapHolder::getInstance(),
			const MeasurementSystemAttributeValueMap& measurementSystemAttributeValues =
					*MeasurementSystemDefaultAttributeValueMapHolder::getInstance(),
			std::string sourceStationAttributeSuffix =
					DEFAULT_SOURCE_STATION_ATTRIBUTE_SUFFIX) noexcept;

protected:

	virtual void finishParse();

	virtual void handleUnmappedAttribute(const std::string& key,
			json_object* const & pValue);
	virtual void parseAttribute(const FlagsAttribute& attribute,
			json_object* const & pValue);

private:

	static const std::string DEFAULT_SOURCE_STATION_ATTRIBUTE_SUFFIX;

	const MeasurementSystemAttributeValueMap& measurementSystemAttributeValues;
	std::string sourceStationAttributeSuffix;

	std::unordered_set<std::string> sources;
	std::unordered_multimap<std::string, std::string> stations;

	const math::MeasurementSystem& parseMeasurementSystem(const MeasurementSystemAttributeValueMap::key_type& attributeValue) const;

};

}

}

#endif // NOTIFYINGFLAGPARSER_HPP
