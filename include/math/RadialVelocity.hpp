#ifndef RADIALVELOCITY_HPP
#define RADIALVELOCITY_HPP

#include <ostream>
#include <string>

namespace math
{

class RadialVelocity
{
public:
	RadialVelocity() : RadialVelocity(0, 0) {}
	RadialVelocity(double magnitude, double direction);
	RadialVelocity(const RadialVelocity& copyee) : RadialVelocity(copyee.magnitude, copyee.direction) { }
	virtual ~RadialVelocity() {}

	virtual RadialVelocity& operator= (const RadialVelocity& other)
	{
		if (this != &other) // protect against invalid self-assignment
		{
			this->magnitude = other.getMagnitude();
			this->direction = other.getDirection();
		}
		// by convention, always return *this
		return *this;
	}

	virtual std::ostream& dump(std::ostream& o) const;
	virtual std::string str() const;

	// Constant getters ---------------------------------------------------------
	double getMagnitude() const
	{
		return magnitude;
	}

	double getDirection() const
	{
		return direction;
	}

	// Setters ------------------------------------------------------------------
	void setMagnitude(double magnitude)
	{
		this->magnitude = magnitude;
	}

	void setDirection(double direction)
	{
		this->direction = direction;
	}

private:

	double magnitude;
	double direction;

};

}

/*namespace std
{

string to_string(const math::RadialVelocity& value);

}

std::ostream& operator<<(std::ostream& o, const math::RadialVelocity& value);

*/

#endif // RADIALVELOCITY_HPP
