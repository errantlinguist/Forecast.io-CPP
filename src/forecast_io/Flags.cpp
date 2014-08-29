#include "forecast_io/Flags.hpp"

#include "common/enumeration.hpp"
#include "common/to_string.hpp"
#include "forecast_io/MeasurementSystemDefaultNameArrayHolder.hpp"

namespace forecast_io
{


Flags::Flags(math::MeasurementSystem units)
:
	Flags(true,
	false,
	std::unordered_set<std::string>(),
	std::unordered_multimap<std::string, std::string>(),
	units)
{
}

Flags::Flags(bool darkskyUnavailable,
			bool metnoLicense,
			std::unordered_set<std::string> sources,
			std::unordered_multimap<std::string, std::string> stations,
			math::MeasurementSystem units) :
		darkskyUnavailable(darkskyUnavailable),
		metnoLicense(metnoLicense),
		sources(sources),
		stations(stations),
		units(units)
{

}

Flags::Flags(const Flags& copyee) : Flags(copyee.isDarkskyUnavailable(), copyee.hasMetnoLicense(), copyee.getSources(), copyee.getStations(), copyee.getUnits())
{
}

Flags::~Flags()
{

}

Flags& Flags::operator= (const Flags& other)
{
	if (this != &other) // protect against invalid self-assignment
	{
		this->darkskyUnavailable = other.isDarkskyUnavailable();
		this->metnoLicense = other.hasMetnoLicense();
		this->sources = other.getSources();
		this->stations = other.getStations();
		this->units = other.getUnits();
	}
	// by convention, always return *this
	return *this;
}

std::ostream& Flags::dump(std::ostream& o) const
{
	o << "Flags[hasMetnoLicense()=";
	o << common::to_quoted_string(hasMetnoLicense());
	o << ", isDarkskyUnavailable()=";
	o << common::to_quoted_string(isDarkskyUnavailable());
	o << ", getSources()=";
	o << common::to_collection_string(getSources());
	o << ", getStations()=";
	o << common::to_collection_string(getStations());
	o << ", getUnits()=";
	const math::MeasurementSystem units = getUnits();
	const std::string& defaultUnitsName = MeasurementSystemDefaultNameArrayHolder::getName(units);
	o << defaultUnitsName;
	o << ']';

	return o;
}

std::string Flags::str() const
{
	std::stringstream ss(std::stringstream::out);
	dump(ss);
	return ss.str();

}

}

namespace std
{

string to_string(const forecast_io::Flags& value)
{
	return value.str();
}

}

std::ostream& operator<<(std::ostream& o, const forecast_io::Flags& value)
{
	return value.dump(o);
}

