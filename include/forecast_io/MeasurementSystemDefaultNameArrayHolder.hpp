#ifndef MEASUREMENTSYSTEMDEFAULTNAMEARRAYHOLDER_HPP
#define MEASUREMENTSYSTEMDEFAULTNAMEARRAYHOLDER_HPP

#include <array>
#include <memory>
#include <string>

#include "../math/MeasurementSystem.hpp"


namespace forecast_io
{

// Typedefs
typedef std::array<std::string, math::MeasurementSystem_COUNT> MeasurementSystemNameArray;


class MeasurementSystemDefaultNameArrayHolder
{
public:

	static std::unique_ptr<MeasurementSystemNameArray>& getInstance()
	{
		return loadInstanceLazily();
	}
	
	static const std::string& getName(const math::MeasurementSystem measurementSystem);

	static void releaseInstance()
	{
		pInstance.reset();
	}

private:

	MeasurementSystemDefaultNameArrayHolder() {}

	static std::unique_ptr<MeasurementSystemNameArray> pInstance;

	static std::unique_ptr<MeasurementSystemNameArray> createInstance();

	static std::unique_ptr<MeasurementSystemNameArray>& loadInstanceLazily()
	{
		if (!pInstance)
		{
			pInstance = createInstance();
		}
		return pInstance;
	}

};

}

#endif // MEASUREMENTSYSTEMDEFAULTNAMEARRAYHOLDER_HPP
