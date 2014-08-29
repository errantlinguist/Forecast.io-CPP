#include "forecast_io/factories/AlertFactory.hpp"

namespace forecast_io
{

namespace factories
{

Alert AlertFactory::create()
{
	return result;
}

void AlertFactory::notifyDescription(const std::string& description)
{
	result.setDescription(description);
}

void AlertFactory::notifyExpiryTime(time_t expiryTime)
{
	result.setExpiryTime(expiryTime);
}

void AlertFactory::notifyTitle(const std::string& title)
{
	result.setTitle(title);
}

void AlertFactory::notifyUri(const std::string& uri)
{
	result.setUri(uri);
}

}

}

