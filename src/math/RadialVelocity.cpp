#include "math/RadialVelocity.hpp"

#include <sstream>

#include "common/to_string.hpp"

namespace math
{

RadialVelocity::RadialVelocity(double magnitude, double direction) noexcept :
		magnitude(magnitude), direction(direction)
{
}

std::ostream& RadialVelocity::dump(std::ostream& o) const
{
	o << "RadialVelocity[getMagnitude()=";
	o << common::to_quoted_string(getMagnitude());
	o << ", getDirection()=";
	o << common::to_quoted_string(getDirection());
	o << ']';

	return o;
}

std::string RadialVelocity::str() const
{
	std::stringstream ss(std::stringstream::out);
	dump(ss);
	return ss.str();

}

}

