#ifndef RANGE_HPP
#define RANGE_HPP

namespace math
{

template<typename T>
class Range
{
public:
	Range()
	{
	}

	Range(T min, T max) :
			min(min), max(max)
	{
	}

	// Constant getters ---------------------------------------------------------
	T getMin() const
	{
		return min;
	}

	T getMax() const
	{
		return max;
	}

	// Setters ------------------------------------------------------------------
	void setMin(T min)
	{
		this->min = min;
	}

	void setMax(T max)
	{
		this->max = max;
	}

private:

	T min;
	T max;

};

}

#endif // RANGE_HPP
