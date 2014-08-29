#include "forecast_io/MeasurementSystemDefaultAttributeValueMapHolder.hpp"

#include "common/enumeration.hpp"
#include "math/MeasurementSystem.hpp"

namespace forecast_io
{

// Free functions --------------------------------------------------------------
static void insertDefaultMeasurementSystems(MeasurementSystemAttributeValueMap& result)
{
	result["ca"] = math::MeasurementSystem::CA;
	result["si"] = math::MeasurementSystem::SI;
	result["uk"] = math::MeasurementSystem::UK;
	result["us"] = math::MeasurementSystem::US;
}

// Class members --------------------------------------------------------------
std::unique_ptr<MeasurementSystemAttributeValueMap> MeasurementSystemDefaultAttributeValueMapHolder::pInstance = nullptr;

const math::MeasurementSystem* MeasurementSystemDefaultAttributeValueMapHolder::findMeasurementSystem(MeasurementSystemAttributeValueMap::key_type attributeValue)
{
	const math::MeasurementSystem* result(nullptr);

	const MeasurementSystemAttributeValueMap& measurementSystemAttributeValues = *getInstance();
	auto iter = measurementSystemAttributeValues.find(attributeValue);
	if (iter != measurementSystemAttributeValues.end())
	{
		const math::MeasurementSystem& measurementSystem = iter->second;
		result = &measurementSystem;
	}
	return result;
}

std::unique_ptr<MeasurementSystemAttributeValueMap> MeasurementSystemDefaultAttributeValueMapHolder::createInstance()
{
	std::unique_ptr<MeasurementSystemAttributeValueMap> result(
			new MeasurementSystemAttributeValueMap(
					math::MeasurementSystem_COUNT));
	insertDefaultMeasurementSystems(*result);
	return result;
}


} /* namespace forecast_io */
