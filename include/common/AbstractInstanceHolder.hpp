/*
 * AbstractInstanceHolder.hpp
 *
 *  Created on: 30.01.2014
 *      Author: tsh
 */

#ifndef ABSTRACTINSTANCEHOLDER_HPP
#define ABSTRACTINSTANCEHOLDER_HPP

namespace common
{

template<typename T>
class AbstractInstanceHolder
{
public:

	virtual ~AbstractInstanceHolder() {}

	virtual const T& getInstance() const = 0;

	virtual T& getInstance() = 0;
};

} /* namespace common */

#endif /* ABSTRACTINSTANCEHOLDER_HP */
