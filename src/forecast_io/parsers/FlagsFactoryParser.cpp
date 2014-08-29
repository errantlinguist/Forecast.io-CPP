#include "forecast_io/parsers/FlagsFactoryParser.hpp"

#include "forecast_io/Flags.hpp"
#include "forecast_io/factories/FlagsFactory.hpp"
#include "forecast_io/listeners/FlagsListener.hpp"
#include "forecast_io/parsers/NotifyingFlagParser.hpp"

namespace forecast_io
{

namespace parsers
{

FlagsFactoryParser::FlagsFactoryParser(listeners::FlagsListener& listener,
		factories::FlagsFactory& factory) :
		NotifyingFlagParser(factory), factory(factory), pListener(
				&listener)
{
}

void FlagsFactoryParser::parse(json_object* const & pJsonObj)
{
	NotifyingFlagParser::parse(pJsonObj);
	Flags flags = factory.create();
	getListener()->notifyFlags(flags);
}

}

}

