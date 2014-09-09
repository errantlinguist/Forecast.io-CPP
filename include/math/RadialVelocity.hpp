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
	virtual ~RadialVelocity() = default;

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

#endif // RADIALVELOCITY_HPP
