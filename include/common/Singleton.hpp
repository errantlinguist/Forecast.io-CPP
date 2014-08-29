/*
 * Singleton.hpp
 *
 *  Created on: 30.01.2014
 *      Author: tsh
 */

#ifndef SINGLETON_HPP
#define SINGLETON_HPP

#include <memory>

namespace common
{

template<typename DerivedHolderType, typename InstanceType>
InstanceType createSingletonInstance();

template<typename DerivedHolderType, typename InstanceType>
class Singleton
{

public:

	static std::unique_ptr<InstanceType>& getInstance()
	{
		return loadInstanceLazily();
	}

	static void releaseInstance()
	{
		pInstance.reset();
	}


private:

	static std::unique_ptr<InstanceType> pInstance;

	static std::unique_ptr<InstanceType>& loadInstanceLazily()
	{
		if (!pInstance)
		{
//			pInstance = createSingletonInstance<DerivedHolderType, InstanceType>();
		}
		return pInstance;
	}

};

} /* namespace common */

#endif /* SINGLETON_HPP */
