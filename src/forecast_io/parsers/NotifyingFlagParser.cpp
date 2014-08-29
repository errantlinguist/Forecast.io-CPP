#include "forecast_io/parsers/NotifyingFlagParser.hpp"

#include <functional>
#include <sstream>
#include <stdexcept>
#include <string>

#include "common/to_string.hpp"
#include "forecast_io/listeners/FlagListener.hpp"
#include "json/json_maps.hpp"
#include "json/ParseError.hpp"
#include "math/MeasurementSystem.hpp"

namespace forecast_io
{

namespace parsers
{

// Free functions ---------------------------------------------------------------

static std::string createUnknownMeasurementSystemAttributeValueErrorMessage(const std::string& attributeValue)
{
	std::stringstream ss(std::stringstream::out);
	ss << "Unknown " << math::MeasurementSystem_NAME << " for attribute value "
			<< common::to_quoted_string(attributeValue) << ".";
	return ss.str();
}

static json::ParseError createUnknownMeasurementSystemAttributeValueError(const std::string& attributeValue)
{
	const std::string errorMessage = createUnknownMeasurementSystemAttributeValueErrorMessage(attributeValue);
	return json::ParseError(errorMessage);
}

// Con-/destructors -------------------------------------------------------------

NotifyingFlagParser::NotifyingFlagParser(listeners::FlagListener& listener,
		const FlagsAttributeNameMap& attributeNames,
		const MeasurementSystemAttributeValueMap& measurementSystemAttributeValues,
		std::string sourceStationAttributeSuffix) :
		AbstractJsonStateMapParser(attributeNames), Notifier(listener), measurementSystemAttributeValues(
				measurementSystemAttributeValues), sourceStationAttributeSuffix(
				sourceStationAttributeSuffix)
{
}

// Members ----------------------------------------------------------------------
const std::string NotifyingFlagParser::DEFAULT_SOURCE_STATION_ATTRIBUTE_SUFFIX =
		"stations";

void NotifyingFlagParser::finishParse()
{
	if (!sources.empty())
	{
		getListener()->notifySources(sources);
	}
	if (!stations.empty())
	{
		getListener()->notifyStations(stations);
	}
}

void NotifyingFlagParser::handleUnmappedAttribute(const std::string& key, json_object* const & pValue)
{
	const size_t foundIdx = key.find_last_of(sourceStationAttributeSuffix);
	if (foundIdx == std::string::npos)
	{
		json::AbstractJsonStateMapParser<FlagsAttribute>::handleUnmappedAttribute(key, pValue);
	}
	else
	{
		const std::string sourceName = key.substr(0, foundIdx);
		// Parse all values in the JSON array and add them to the set of station IDs for the given source
		json::insertJsonStringArrayValues(stations, sourceName, pValue);
	}
}

void NotifyingFlagParser::parseAttribute(const FlagsAttribute& attribute,
		json_object* const & pValue)
{
	switch (attribute)
	{
	case FlagsAttribute::DARKSKY_UNAVAILABLE:
	{
		const json_bool darkskyUnavailable = json_object_get_boolean(pValue);
		getListener()->notifyDarkskyUnavailable(bool(darkskyUnavailable));
		break;
	}
	case FlagsAttribute::METNO_LICENSE:
	{
		const json_bool metnoLicense = json_object_get_boolean(pValue);
		getListener()->notifyMetnoLicense(bool(metnoLicense));
		break;
	}
	case FlagsAttribute::SOURCES:
	{
		json::insertJsonStringArrayValues(sources, pValue);
		break;
	}
	case FlagsAttribute::UNITS:
	{
		const std::string unitsStr(json_object_get_string(pValue));
		const math::MeasurementSystem& measurementSystem =
				parseMeasurementSystem(unitsStr);
		getListener()->notifyUnits(measurementSystem);
		break;
	}
	default:
		throw std::logic_error(
				createUndefinedAttributeErrorMessage(FlagsAttribute_NAME,
						attribute));
		break;
	}
}

const math::MeasurementSystem& NotifyingFlagParser::parseMeasurementSystem(const MeasurementSystemAttributeValueMap::key_type& attributeValue) const
{
	auto iter = measurementSystemAttributeValues.find(attributeValue);
	if (iter == measurementSystemAttributeValues.end())
	{
		const json::ParseError error = createUnknownMeasurementSystemAttributeValueError(attributeValue);
		throw error;
	}
	else
	{
		const math::MeasurementSystem& measurementSystem = iter->second;
		return measurementSystem;
	}
}

}
}

