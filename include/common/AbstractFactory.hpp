#ifndef FACTORY_HPP
#define FACTORY_HPP

namespace common
{

template<typename T>
class AbstractFactory
{
public:

	virtual ~AbstractFactory() = default;

	virtual T create() = 0;

};

}

#endif // FACTORY_HPP
