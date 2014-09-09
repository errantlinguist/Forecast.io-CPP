#ifndef SYNCHRONICDATAPOINTFACTORYPARSER_HPP
#define SYNCHRONICDATAPOINTFACTORYPARSER_HPP

#include "NotifyingSynchronicDataPointParser.hpp" // Base class: forecast_io::parsers::NotifyingSynchronicDataPointParser

namespace forecast_io
{

// Forward declarations
namespace factories
{
	class SynchronicDataPointFactory;
}
namespace listeners
{

}

namespace parsers
{

class SynchronicDataPointFactoryParser : public forecast_io::parsers::NotifyingSynchronicDataPointParser
{
public:
	SynchronicDataPointFactoryParser(factories::SynchronicDataPointFactory& factory);

	virtual void parse(json_object* const & pJsonObj);

private:
	factories::SynchronicDataPointFactory& factory;

};

}

}

#endif // SYNCHRONICDATAPOINTFACTORYPARSER_HPP
