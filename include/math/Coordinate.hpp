#ifndef COORDINATE_HPP
#define COORDINATE_HPP

#include <string>
#include <utility>

namespace math
{

class Coordinate
{
public:

	static std::string createLatitudeString(double latitude);
	static std::string createLongitudeString(double longitude);

	Coordinate();
	virtual ~Coordinate();
	Coordinate(const Coordinate& copyee);

	virtual Coordinate& operator= (const Coordinate& other);

	virtual std::ostream& dump(std::ostream& o) const;
	virtual std::string str() const;

	// Constant getters ---------------------------------------------------------
	double getLatitude() const
	{
		return coordinatePoint.first;
	}

	std::string createLatitudeString() const;

	double getLongitude() const
	{
		return coordinatePoint.second;
	}

	std::string createLongitudeString() const;

	// Setters ------------------------------------------------------------------
	void setLatitude(double latitude)
	{
		coordinatePoint.first = latitude;
	}

	void setLongitude(double longitude)
	{
		coordinatePoint.second = longitude;
	}

protected:

	// Typedefs
	typedef std::pair<double, double> coord_t;

	Coordinate(coord_t coordinatePoint);

	coord_t getCoordinatePoint() const
	{
		return coordinatePoint;
	}

	coord_t& getCoordinatePoint()
	{
		return coordinatePoint;
	}

	void setCoordinatePoint(coord_t coordinatePoint)
	{
		this->coordinatePoint = coordinatePoint;
	}

private:

	coord_t coordinatePoint;

};

}

namespace std
{

string to_string(const math::Coordinate& value);

}

std::ostream& operator<<(std::ostream& o, const math::Coordinate& value);

#endif // COORDINATE_HPP
