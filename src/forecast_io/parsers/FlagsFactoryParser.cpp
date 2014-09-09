#include "forecast_io/parsers/FlagsFactoryParser.hpp"

#include "forecast_io/Flags.hpp"
#include "forecast_io/factories/FlagsFactory.hpp"
#include "forecast_io/listeners/FlagsListener.hpp"
#include "forecast_io/parsers/NotifyingFlagParser.hpp"

namespace forecast_io
{

namespace parsers
{

FlagsFactoryParser::FlagsFactoryParser(listeners::FlagsListener* pListener,
		factories::FlagsFactory* pFactory) :
		NotifyingFlagParser(pFactory), pFactory(pFactory), pListener(
				pListener)
{
}

void FlagsFactoryParser::parse(json_object* const & pJsonObj)
{
	NotifyingFlagParser::parse(pJsonObj);
	Flags flags = pFactory->create();
	getListener()->notifyFlags(flags);
}

}

}

