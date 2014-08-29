#include "forecast_io/MeasurementSystemDefaultNameArrayHolder.hpp"

#include "common/enumeration.hpp"

namespace forecast_io
{

// Free functions --------------------------------------------------------------
static void insertDefaultMeasurementSystemNames(MeasurementSystemNameArray& result)
{
	result[common::getEnumIndex(math::MeasurementSystem::CA)] = "Canadian Imperial";
	result[common::getEnumIndex(math::MeasurementSystem::SI)] = "SI";
	result[common::getEnumIndex(math::MeasurementSystem::UK)] = "UK Imperial";
	result[common::getEnumIndex(math::MeasurementSystem::US)] = "US Imperial";
}

// Class members --------------------------------------------------------------
std::unique_ptr<MeasurementSystemNameArray> MeasurementSystemDefaultNameArrayHolder::pInstance = nullptr;

const std::string& MeasurementSystemDefaultNameArrayHolder::getName(const math::MeasurementSystem measurementSystem)
{
	const MeasurementSystemNameArray& defaultMeasurementSystemNames = *getInstance();
	const size_t measurementSystemNameIndex = common::getEnumIndex(measurementSystem);
	return (defaultMeasurementSystemNames)[measurementSystemNameIndex];
}

std::unique_ptr<MeasurementSystemNameArray> MeasurementSystemDefaultNameArrayHolder::createInstance()
{
	std::unique_ptr<MeasurementSystemNameArray> result(
			new MeasurementSystemNameArray());
	insertDefaultMeasurementSystemNames(*result);
	return result;
}

} /* namespace forecast_io */
