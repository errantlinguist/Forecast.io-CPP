#ifndef DATAPOINTATTRIBUTEDEFAULTNAMEMAPHOLDER_HPP
#define DATAPOINTATTRIBUTEDEFAULTNAMEMAPHOLDER_HPP

#include <memory>
#include <string>
#include <unordered_map>

#include "DataPointAttribute.hpp"

namespace forecast_io
{
namespace parsers
{

class DataPointAttributeDefaultNameMapHolder
{
public:

	static std::unique_ptr<DataPointAttributeNameMap>& getInstance()
	{
		return loadInstanceLazily();
	}

	static void releaseInstance()
	{
		pInstance.reset();
	}

private:

	static std::unique_ptr<DataPointAttributeNameMap> pInstance;

	static std::unique_ptr<DataPointAttributeNameMap> createInstance();

	static std::unique_ptr<DataPointAttributeNameMap>& loadInstanceLazily()
	{
		if (!pInstance)
		{
			pInstance = createInstance();
		}
		return pInstance;
	}

};

}
}

#endif // DATAPOINTATTRIBUTEDEFAULTNAMEMAPHOLDER_HPP
