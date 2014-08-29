#include "forecast_io/Alert.hpp"

#include <sstream>

#include "common/to_string.hpp"

namespace forecast_io
{

Alert::Alert() : Alert("", 0, "", "")
{
}

Alert::Alert(std::string title, time_t expiryTime, std::string description,
		std::string uri) :
		title(title), expiryTime(expiryTime), description(description), uri(uri)
{
}

Alert::Alert(const Alert& copyee) : Alert(copyee.getTitle(), copyee.getExpiryTime(), copyee.getDescription(), copyee.getUri())
{
}

Alert::~Alert()
{

}

Alert& Alert::operator= (const Alert& other)
{
	if (this != &other) // protect against invalid self-assignment
	{
		this->title = other.getTitle();
		this->expiryTime = other.getExpiryTime();
		this->description = other.getDescription();
        this->uri = other.getUri();
	}
	// by convention, always return *this
	return *this;
}

bool Alert::equal_to(const Alert& other) const
{
	return ((expiryTime == other.expiryTime) && (uri == other.uri)
			&& (title == other.title) && (description == other.description));
}

size_t Alert::hash() const
{
	size_t result(1U);
	static constexpr size_t prime = 31;

	static std::hash<std::string> str_hash;
	result = prime * result + (str_hash(title));
	result = prime * result + (str_hash(description));
	result = prime * result + (str_hash(uri));

	static std::hash<time_t> time_t_hash;
	result = prime * result + (time_t_hash(expiryTime));

	return result;
}

std::ostream& Alert::dump(std::ostream& o) const
{
	o << "Alert[getTitle()=";
	o << common::to_quoted_string(getTitle());
	o << ", getExpiryTime()=";
	o << common::to_quoted_string(getExpiryTime());
	o << ", getDescription()=";
	o << common::to_quoted_string(getDescription());
	o << ", getUri()=";
	o << common::to_quoted_string(getUri());
	o << ']';

	return o;
}

std::string Alert::str() const
{
	std::stringstream ss(std::stringstream::out);
	dump(ss);
	return ss.str();

}

}

namespace std
{
string to_string(const forecast_io::Alert& value)
{
	return value.str();
}
}

std::ostream& operator<<(std::ostream& o, const forecast_io::Alert& value)
{
	return value.dump(o);
}


