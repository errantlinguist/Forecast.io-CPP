#ifndef INSTANCEREFERENCEHOLDER_HPP
#define INSTANCEREFERENCEHOLDER_HPP

#include "AbstractInstanceHolder.hpp"

namespace common
{

template<typename T>
class InstanceReferenceHolder: AbstractInstanceHolder<T>
{
public:
	InstanceReferenceHolder(T& instance) : pInstance(&instance)
	{

	}

	virtual ~InstanceReferenceHolder()
	{

	}

	const T& getInstance() const
	{
		return *pInstance;
	}

	T& getInstance()
	{
		return *pInstance;
	}


private:

	T* pInstance;

};

}

#endif // INSTANCEREFERENCEHOLDER_HPP
