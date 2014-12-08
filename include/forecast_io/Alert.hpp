#ifndef ALERT_HPP
#define ALERT_HPP

#include <ctime>
#include <functional>
#include <ostream>
#include <string>

namespace forecast_io
{

class Alert
{

public:
	Alert() = default;
	Alert(std::string title, time_t expiryTime, std::string description,
			std::string uri) noexcept;
	Alert(const Alert& copyee) = default;
	virtual ~Alert() = default;

	virtual Alert& operator= (const Alert& other) = default;

	virtual bool operator==(const Alert& other) const
	{
		return ((this == &other) || equal_to(other));
	}

	virtual bool equal_to(const Alert& other) const;

	virtual size_t hash() const;
	virtual std::ostream& dump(std::ostream& o) const;
	virtual std::string str() const;

	// Constant getters ---------------------------------------------------------
	std::string getTitle() const
	{
		return title;
	}

	time_t getExpiryTime() const
	{
		return expiryTime;
	}

	std::string getDescription() const
	{
		return description;
	}

	std::string getUri() const
	{
		return uri;
	}

	// Setters ------------------------------------------------------------------
	void setTitle(std::string title)
	{
		this->title = title;
	}

	void setExpiryTime(time_t expiryTime)
	{
		this->expiryTime = expiryTime;
	}

	void setDescription(std::string description)
	{
		this->description = description;
	}

	void setUri(std::string uri)
	{
		this->uri = uri;
	}

private:

	std::string title;
	time_t expiryTime;
	std::string description;
	std::string uri;

};

}

// Standard-library template extensions
namespace std
{

template<>
struct equal_to<forecast_io::Alert>
{
	bool operator()(const forecast_io::Alert& first,
			const forecast_io::Alert& second) const
	{
		return first.equal_to(second);
	}
};

template<>
struct hash<forecast_io::Alert>
{
	size_t operator ()(const forecast_io::Alert& value) const
	{
		return value.hash();
	}
};

string to_string(const forecast_io::Alert& value);

}

std::ostream& operator<<(std::ostream& o, const forecast_io::Alert& value);

#endif // ALERT_HPP
