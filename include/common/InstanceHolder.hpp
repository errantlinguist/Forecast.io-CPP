/*
 * InstanceHolder.hpp
 *
 *  Created on: 30.01.2014
 *      Author: tsh
 */

#ifndef INSTANCEHOLDER_HPP
#define INSTANCEHOLDER_HPP

#include "AbstractInstanceHolder.hpp"

namespace common
{

template<typename T>
class InstanceHolder: AbstractInstanceHolder<T>
{
public:
	InstanceHolder(T instance) : instance(instance)
	{

	}

	const T& getInstance() const
	{
		return instance;
	}

	T& getInstance()
	{
		return instance;
	}


private:

	T instance;

};

} /* namespace common */

#endif /* INSTANCEHOLDER_HPP */
