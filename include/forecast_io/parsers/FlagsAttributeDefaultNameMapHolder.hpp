#ifndef FLAGSATTRIBUTEDEFAULTNAMEMAPHOLDER_HPP
#define FLAGSATTRIBUTEDEFAULTNAMEMAPHOLDER_HPP

#include <memory>
#include <string>
#include <unordered_map>

#include "FlagsAttribute.hpp"

namespace forecast_io
{
namespace parsers
{

class FlagsAttributeDefaultNameMapHolder
{
public:

	static std::unique_ptr<FlagsAttributeNameMap>& getInstance()
	{
		return loadInstanceLazily();
	}

	static void releaseInstance()
	{
		pInstance.reset();
	}

private:

	static std::unique_ptr<FlagsAttributeNameMap> pInstance;

	static std::unique_ptr<FlagsAttributeNameMap> createInstance();

	static std::unique_ptr<FlagsAttributeNameMap>& loadInstanceLazily()
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

#endif // FLAGATTRIBUTEDEFAULTNAMEMAPHOLDER
