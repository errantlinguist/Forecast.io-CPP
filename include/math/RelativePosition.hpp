#ifndef RELATIVEPOSITION_HPP
#define RELATIVEPOSITION_HPP

namespace math
{

template<typename B, typename D>
class RelativePosition
{
public:
	RelativePosition() = default;

	RelativePosition(B bearing, D distance) :
		bearing(bearing), distance(distance)
	{
	}

	// Constant getters ---------------------------------------------------------
	B getBearing() const
	{
		return bearing;
	}

	D getDistance() const
	{
		return distance;
	}

	// Setters ------------------------------------------------------------------
	void setBearing(B bearing)
	{
		this->bearing = bearing;
	}

	void setDistance(D distance)
	{
		this->distance = distance;
	}

private:

	B bearing;
	D distance;

};

}

#endif // RELATIVEPOSITION_HPP
