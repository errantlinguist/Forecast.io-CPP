/*
 * LazyInstanceHolder.hpp
 *
 *  Created on: 30.01.2014
 *      Author: tsh
 */

#ifndef LAZYINSTANCEHOLDER_HPP
#define LAZYINSTANCENHOLDER_HPP

#include <memory>

#include "AbstractInstanceHolder.hpp"

namespace common
{

template<typename T>
class LazyInstanceHolder: AbstractInstanceHolder<std::unique_ptr<T>>
{

public:

	typedef std::unique_ptr<T> (InstanceFactoryFunction)();

	const std::unique_ptr<T>& getInstance() const
	{
		return loadInstanceLazily();
	}

	std::unique_ptr<T>& getInstance()
	{
		return loadInstanceLazily();
	}

	void releaseInstance()
	{
		pInstance.reset();
	}

	LazyInstanceHolder(InstanceFactoryFunction* pInstanceFactoryFunc) : pInstanceFactoryFunc(pInstanceFactoryFunc)
	{

	}


private:

	InstanceFactoryFunction* pInstanceFactoryFunc;

	mutable std::unique_ptr<T> pInstance;

	std::unique_ptr<T>& loadInstanceLazily() const
	{
		if (!pInstance)
		{
			pInstance = pInstanceFactoryFunc();
		}
		return pInstance;
	}

};

} /* namespace common */

#endif /* LAZYINSTANCEHOLDER_HPP */
