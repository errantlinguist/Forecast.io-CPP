#ifndef DATAOVERVIEW_HPP
#define DATAOVERVIEW_HPP

#include <ostream>
#include <string>

namespace forecast_io
{

class DataOverview
{
public:

	DataOverview();
	DataOverview(std::string summary, std::string iconName);
	DataOverview(const DataOverview& copyee) = default;
	virtual ~DataOverview() = default;

	virtual DataOverview& operator= (const DataOverview& other) = default;

	virtual std::ostream& dump(std::ostream& o) const;
	virtual std::string str() const;

	// Constant getters ---------------------------------------------------------
	std::string getSummary() const
	{
		return summary;
	}

	std::string getIconName() const
	{
		return iconName;
	}

	// Setters ------------------------------------------------------------------
	void setSummary(std::string summary)
	{
		this->summary = summary;
	}

	void setIconName(std::string iconName)
	{
		this->iconName = iconName;
	}

private:

	std::string summary;
	std::string iconName;

};

}

namespace std
{
string to_string(const forecast_io::DataOverview& value);
}

std::ostream& operator<<(std::ostream& o,
		const forecast_io::DataOverview& value);

#endif // DATAOVERVIEW_HPP
