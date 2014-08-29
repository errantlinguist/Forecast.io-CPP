#ifndef MEASUREMENTSYSTEMDEFAULTATTRIBUTEVALUEMAPHOLDER_HPP
#define MEASUREMENTSYSTEMDEFAULTATTRIBUTEVALUEMAPHOLDER_HPP

#include <memory>
#include <string>
#include <unordered_map>


// Forward declarations
namespace math
{
enum class MeasurementSystem : size_t;
}

namespace forecast_io
{

// Typedefs
typedef std::unordered_map<std::string, math::MeasurementSystem> MeasurementSystemAttributeValueMap;


class MeasurementSystemDefaultAttributeValueMapHolder
{
public:

	static std::unique_ptr<MeasurementSystemAttributeValueMap>& getInstance()
	{
		return loadInstanceLazily();
	}

	static const math::MeasurementSystem* findMeasurementSystem(MeasurementSystemAttributeValueMap::key_type attributeValue);

	static void releaseInstance()
	{
		pInstance.reset();
	}

private:

	MeasurementSystemDefaultAttributeValueMapHolder() {}

	static std::unique_ptr<MeasurementSystemAttributeValueMap> pInstance;

	static std::unique_ptr<MeasurementSystemAttributeValueMap> createInstance();

	static std::unique_ptr<MeasurementSystemAttributeValueMap>& loadInstanceLazily()
	{
		if (!pInstance)
		{
			pInstance = createInstance();
		}
		return pInstance;
	}


};

}

#endif // MEASUREMENTSYSTEMDEFAULTATTRIBUTEVALUEMAPHOLDER_HPP
