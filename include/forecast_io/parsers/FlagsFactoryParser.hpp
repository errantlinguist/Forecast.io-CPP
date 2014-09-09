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
	FlagsFactoryParser(listeners::FlagsListener* pFlagsListener,
			factories::FlagsFactory* pFactory);

	std::unordered_set<listeners::FlagsListener*>& getFlagsListeners()
	{
		return flagsListeners;
	}

	const std::unordered_set<listeners::FlagsListener*>& getFlagsListeners() const
	{
		return flagsListeners;
	}

	virtual void parse(json_object* const & pJsonObj);

private:
	factories::FlagsFactory* pFactory;
	std::unordered_set<listeners::FlagsListener*> flagsListeners;

};

}

}

#endif // FLAGSFACTORYPARSER_HPP
