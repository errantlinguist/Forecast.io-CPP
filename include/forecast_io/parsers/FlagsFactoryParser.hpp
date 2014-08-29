#ifndef FLAGSFACTORYPARSER_HPP
#define FLAGSFACTORYPARSER_HPP

#include "NotifyingFlagParser.hpp" // Base class: forecast_io::parsers::NotifyingFlagParser

namespace forecast_io
{

// Forward declarations
namespace factories
{
class FlagsFactory;
}
namespace listeners
{
class FlagsListener;
}

namespace parsers
{

// Forward declarations
class NotifyingFlagParser;

/**
 * NOTE: This class extends NotifyingFlagParser so that it can be used as a drop-in replacement thereof in DelegatingForecastParser, allowing tree-like Forecast objects to be created.
 * Don't forget this and try to refactor!
 */
class FlagsFactoryParser: public NotifyingFlagParser
{
public:
	FlagsFactoryParser(listeners::FlagsListener& listener,
			factories::FlagsFactory& factory);

	listeners::FlagsListener* getListener()
	{
		return pListener;
	}

	const listeners::FlagsListener* getListener() const
	{
		return pListener;
	}

	virtual void parse(json_object* const & pJsonObj);

private:
	factories::FlagsFactory& factory;
	listeners::FlagsListener* pListener;

};

}

}

#endif // FLAGSFACTORYPARSER_HPP
