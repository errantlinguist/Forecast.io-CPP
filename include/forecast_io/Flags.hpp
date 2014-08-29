#ifndef FLAGS_HPP
#define FLAGS_HPP

#include <ostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

#include "../math/MeasurementSystem.hpp"

namespace forecast_io
{

class Flags
{

public:
	Flags(math::MeasurementSystem units);
	Flags(bool darkskyUnavailable,
			bool metnoLicense,
			std::unordered_set<std::string> sources,
			std::unordered_multimap<std::string, std::string> stations,
			math::MeasurementSystem units);
	Flags(const Flags& copyee);
	virtual ~Flags();

	virtual Flags& operator= (const Flags& other);

	virtual std::ostream& dump(std::ostream& o) const;
	virtual std::string str() const;

	// Constant getters ---------------------------------------------------------
	bool isDarkskyUnavailable() const
	{
		return darkskyUnavailable;
	}

	bool hasMetnoLicense() const
	{
		return metnoLicense;
	}

	const std::unordered_set<std::string>& getSources() const
	{
		return sources;
	}

	const std::unordered_multimap<std::string, std::string>& getStations() const
	{
		return stations;
	}

	math::MeasurementSystem getUnits() const
	{
		return units;
	}

	// Non-constant getters -----------------------------------------------------
	std::unordered_set<std::string>& getSources()
	{
		return sources;
	}

	std::unordered_multimap<std::string, std::string>& getStations()
	{
		return stations;
	}

	// Setters ------------------------------------------------------------------
	void setDarkskyUnavailable(bool darkskyUnavailable)
	{
		this->darkskyUnavailable = darkskyUnavailable;
	}

	void setSources(std::unordered_set<std::string> sources)
	{
		this->sources = sources;
	}

	void setStations(std::unordered_multimap<std::string, std::string> stations)
	{
		this->stations = stations;
	}

	void setMetnoLicense(bool metnoLicense)
	{
		this->metnoLicense = metnoLicense;
	}

	void setUnits(math::MeasurementSystem units)
	{
		this->units = units;
	}

private:

	bool darkskyUnavailable;
	bool metnoLicense;
	std::unordered_set<std::string> sources;
	std::unordered_multimap<std::string, std::string> stations;
	math::MeasurementSystem units;

};

}

namespace std
{

string to_string(const forecast_io::Flags& value);
}

std::ostream& operator<<(std::ostream& o, const forecast_io::Flags& value);

#endif // FLAGS_HPP
