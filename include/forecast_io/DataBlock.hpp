#ifndef DATABLOCK_HPP
#define DATABLOCK_HPP

#include <ctime>
#include <memory>
#include <vector>

#include "DataOverview.hpp"
#include "SingleDataPoint.hpp"

namespace forecast_io
{

// Forward declarations
//class SingleDataPoint;

class DataBlock
{
public:
    /** Default constructor */
    DataBlock() : DataBlock(0, DataOverview())
	{
		//ctor
	}

    DataBlock(time_t time, DataOverview overview) : overview(overview), time(time)
	{
		//ctor
	}

    // Constant getters ---------------------------------------------------------
    const std::vector<SingleDataPoint >& getData() const
    {
    	return data;
    }

    const DataOverview& getOverview() const
    {
        return overview;
    }

	time_t getTime() const
    {
        return time;
    }

    // Non-constant getters -----------------------------------------------------
    std::vector<SingleDataPoint >& getData()
    {
		return data;
    }


    DataOverview& getOverview()
    {
        return overview;
    }

    // Setters -----------------------------------------------------------------
    void setData(std::vector<SingleDataPoint > data)
    {
		this->data = data;
    }

    void setOverview(DataOverview overview)
    {
        this->overview = overview;
    }

	void setTime(time_t time)
    {
        this->time = time;
    }

private:

	std::vector<SingleDataPoint > data;
    DataOverview overview;
    time_t time;

};

}

#endif // DATABLOCK_HPP
