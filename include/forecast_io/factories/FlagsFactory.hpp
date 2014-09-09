#ifndef FLAGSFACTORY_HPP
#define FLAGSFACTORY_HPP

#include "../../common/AbstractFactory.hpp" // Base class: AbstractFactory
#include "../listeners/FlagListener.hpp" // Base class: forecast_io::listeners::FlagListener

#include "../Flags.hpp"

#include "../../math/MeasurementSystem.hpp"

namespace forecast_io
{

namespace factories
{

class FlagsFactory: public common::AbstractFactory<Flags>,
		public forecast_io::listeners::FlagListener
{
public:

	FlagsFactory(math::MeasurementSystem defaultUnits);

	virtual Flags create();

	math::MeasurementSystem getDefaultUnits() const
	{
		return defaultUnits;
	}

	void setDefaultUnits(math::MeasurementSystem defaultUnits)
	{
		this->defaultUnits = defaultUnits;
	}

	virtual void notifyDarkskyUnavailable(bool darkskyUnavailable);
	virtual void notifyMetnoLicense(bool metnoLicense);
	virtual void notifySources(std::unordered_set<std::string>& sources);
	virtual void notifyStations(std::unordered_multimap<std::string, std::string>& stations);
	virtual void notifyUnits(math::MeasurementSystem units);

private:

	math::MeasurementSystem defaultUnits;

	Flags result;

};

}

}

#endif // FLAGSFACTORY_HPP
