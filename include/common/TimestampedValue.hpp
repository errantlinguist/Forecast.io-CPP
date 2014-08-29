#ifndef TIMESTAMPEDVALUE_HPP
#define TIMESTAMPEDVALUE_HPP

#include <ctime>

namespace common
{

template<typename V>
class TimestampedValue
{
public:
	TimestampedValue() : timestamp(0)
	{

	}

	TimestampedValue(V value, time_t timestamp) :
			value(value), timestamp(timestamp)
	{

	}

	// Constant getters ---------------------------------------------------------
	V getValue() const
	{
		return value;
	}

	time_t getTimestamp() const
	{
		return timestamp;
	}

	// Setters ------------------------------------------------------------------
	void setValue(V value)
	{
		this->value = value;
	}

	void setTimestamp(time_t timestamp)
	{
		this->timestamp = timestamp;
	}

private:
	V value;
	time_t timestamp;

};

}

#endif // TIMESTAMPEDVALUE_HPP
