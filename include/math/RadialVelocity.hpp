#ifndef RADIALVELOCITY_HPP
#define RADIALVELOCITY_HPP

#include <ostream>
#include <string>

namespace math
{

class RadialVelocity
{
public:
	RadialVelocity() = default;
	RadialVelocity(double magnitude, double direction) noexcept;
	RadialVelocity(const RadialVelocity& copyee) = default;
	virtual ~RadialVelocity() = default;

	virtual RadialVelocity& operator= (const RadialVelocity& other) = default;

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
