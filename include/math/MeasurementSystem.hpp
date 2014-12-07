#ifndef MEASUREMENTSYSTEM_HPP
#define MEASUREMENTSYSTEM_HPP

#include <cstddef>
#include <sstream>
#include <string>

namespace math
{

const std::string MeasurementSystem_NAME = "MeasurementSystem";

enum class MeasurementSystem
	: size_t
{
	CA,
	SI,
	UK,
	US,

	_MAX = US
};

constexpr size_t MeasurementSystem_COUNT = static_cast<size_t>(MeasurementSystem::_MAX) + 1U;

}


#endif // MEASUREMENTSYSTEM_HPP
