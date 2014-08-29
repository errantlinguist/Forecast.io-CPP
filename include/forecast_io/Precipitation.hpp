#ifndef PRECIPITATION_HPP
#define PRECIPITATION_HPP

#include <ostream>
#include <string>

namespace forecast_io
{

class Precipitation
{
public:
	Precipitation();
	Precipitation(double intensity, double probability, std::string type);

//	virtual std::ostream& dump(std::ostream& o) const;
//	virtual std::string str() const;

// Constant getters ---------------------------------------------------------
	double getIntensity() const
	{
		return intensity;
	}

	double getProbability() const
	{
		return probability;
	}
	
	std::string getType() const
	{
		return type;
	}

	// Setters ------------------------------------------------------------------
	void setIntensity(double intensity)
	{
		this->intensity = intensity;
	}

	void setProbability(double probability)
	{
		this->probability = probability;
	}
	
	void setType(std::string type)
	{
		this->type = type;
	}

private:

	double intensity;
	double probability;
	std::string type;

};

}

/*namespace std
 {

 string to_string(const forecast_io::Precipitation& value);

 }

 std::ostream& operator<<(std::ostream& o, const forecast_io::Precipitation& value);*/

#endif // PRECIPITATION_HPP
