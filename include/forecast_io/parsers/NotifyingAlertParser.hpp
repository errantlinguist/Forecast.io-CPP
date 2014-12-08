#ifndef NOTIFYINGALERTPARSER_HPP
#define NOTIFYINGALERTPARSER_HPP

#include "../../json/AbstractJsonStateMapParser.hpp" // Base class: json::AbstractJsonStateMapParser
#include "../../common/Notifier.hpp" // Base class: Notifier

#include "AlertAttribute.hpp"

namespace forecast_io
{

// Forward declarations
namespace listeners
{
class AlertDetailsListener;
}

namespace parsers
{

class NotifyingAlertParser: public json::AbstractJsonStateMapParser<
		AlertAttribute>, public common::Notifier<listeners::AlertDetailsListener>
{
public:
	NotifyingAlertParser(listeners::AlertDetailsListener* pListener,
			const AlertAttributeNameMap& attributeNames =
					DEFAULT_ATTRIBUTE_NAMES) noexcept;

protected:

	virtual void parseAttribute(const AlertAttribute& attribute,
			json_object* const & pValue);

private:

	static const AlertAttributeNameMap DEFAULT_ATTRIBUTE_NAMES;

};

}
}

#endif // NOTIFYINGALERTPARSER_HPP
