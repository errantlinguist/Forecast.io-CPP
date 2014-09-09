#include "math/Coordinate.hpp"

#include <cmath>
#include <iomanip>
#include <sstream>

namespace math
{

static constexpr const char * const POLARITY_SEPARATOR = "\u00B0 ";

static constexpr int DEFAULT_PRECISION = 2;

static constexpr char LATITUDE_POSITIVE_SYMBOL = 'N';
static constexpr char LATITUDE_NEGATIVE_SYMBOL = 'S';
static constexpr char LONGITUDE_POSITIVE_SYMBOL = 'E';
static constexpr char LONGITUDE_NEGATIVE_SYMBOL = 'W';

// Class members ----------------------------------------------------------------

std::string Coordinate::createLatitudeString(double latitude)
{
	std::stringstream ss(std::stringstream::out);
	ss << std::setprecision(DEFAULT_PRECISION) << std::abs(latitude);
	ss << POLARITY_SEPARATOR;

	if (latitude < 0)
	{
		ss << LATITUDE_NEGATIVE_SYMBOL;

	}
	else
	{
		ss << LATITUDE_POSITIVE_SYMBOL;
	}

	return ss.str();
}

std::string Coordinate::createLongitudeString(double longitude)
{
	std::stringstream ss(std::stringstream::out);
	ss << std::setprecision(DEFAULT_PRECISION) << std::abs(longitude);
	ss << POLARITY_SEPARATOR;

	if (longitude < 0)
	{
		ss << LONGITUDE_NEGATIVE_SYMBOL;
	}
	else
	{
		ss << LONGITUDE_POSITIVE_SYMBOL;
	}

	return ss.str();
}

// Con-/destructors -------------------------------------------------------------

Coordinate::Coordinate() : Coordinate(coord_t(0, 0))
{
}

Coordinate::Coordinate(coord_t coordinatePoint) :
		coordinatePoint(coordinatePoint)
{
}

// Instance members -------------------------------------------------------------

std::ostream& Coordinate::dump(std::ostream& o) const
{
	o << createLatitudeString() << ", " << createLongitudeString();

	return o;
}

std::string Coordinate::str() const
{
	std::stringstream ss(std::stringstream::out);
	dump(ss);
	return ss.str();
}

std::string Coordinate::createLatitudeString() const
{
	const double latitude = getLatitude();
	return createLatitudeString(latitude);

}

std::string Coordinate::createLongitudeString() const
{
	const double longitude = getLongitude();
	return createLongitudeString(longitude);

}

}

namespace std
{

string to_string(const math::Coordinate& value)
{
	return value.str();
}

}

std::ostream& operator<<(std::ostream& o, const math::Coordinate& value)
{
	return value.dump(o);
}
