#ifndef NOTIFYINGSYNCHRONICDATAPOINTPARSER_HPP
#define NOTIFYINGSYNCHRONICDATAPOINTPARSER_HPP

#include "../../json/AbstractJsonStateMapParser.hpp" // Base class: json::AbstractJsonStateMapParser
#include "../../common/Notifier.hpp" // Base class: Notifier

#include "DataPointAttribute.hpp"
#include "DataPointAttributeDefaultNameMapHolder.hpp"

namespace forecast_io
{

// Forward declarations
namespace listeners
{
class SynchronicDataPointDetailsListener;
}

namespace parsers
{

class NotifyingSynchronicDataPointParser: public json::AbstractJsonStateMapParser<
		DataPointAttribute>,
		public common::Notifier<listeners::SynchronicDataPointDetailsListener>
{
public:
	NotifyingSynchronicDataPointParser(
			listeners::SynchronicDataPointDetailsListener* pListener,
			const DataPointAttributeNameMap& attributeNames =
					*DataPointAttributeDefaultNameMapHolder::getInstance());

protected:

	virtual void parseAttribute(const DataPointAttribute& attribute,
			json_object* const & pValue);

};

}

}

#endif // NOTIFYINGSYNCHRONICDATAPOINTPARSER_HPP
