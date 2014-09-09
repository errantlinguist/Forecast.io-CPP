#ifndef ABSTRACTSTREAMWRITER_HPP
#define ABSTRACTSTREAMWRITER_HPP

#include <ostream>

namespace common
{

template<typename T>
class AbstractStreamWriter
{
public:

	virtual ~AbstractStreamWriter() = default;

	virtual void write(const T& value, std::ostream& output) = 0;

};

}

#endif // ABSTRACTSTREAMWRITER_HPP
