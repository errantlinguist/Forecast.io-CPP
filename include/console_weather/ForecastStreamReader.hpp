#ifndef FORECASTSTREAMREADER_HPP
#define FORECASTSTREAMREADER_HPP

#include <cstddef>
#include <memory>

#include "../math/MeasurementSystem.hpp"

// Forward declarations
namespace forecast_io
{
class Forecast;
}

namespace console_weather
{

/**
* A class for reading in JSON structures from an input stream and creating a forecast_io::Forecast object from the data contained therein.
*/
class ForecastStreamReader
{
public:
    ForecastStreamReader(math::MeasurementSystem measurementUnits, int readBufferSize);

	/**
	* Parses a Forecast object from a stream of JSON data.
	* @param[in] input The stream of JSON data to parse.
	* @return A pointer to a new forecast_io::Forecast object representing the data.
	* @throw json::ParseException If there was an error while parsing the input as JSON.
	**/
    std::unique_ptr<forecast_io::Forecast> read(std::istream& input);

private:
    math::MeasurementSystem measurementUnits;
    std::unique_ptr<char[]> pBuffer;
    int readBufferSize;
};

}

#endif // FORECASTSTREAMREADER_HPP
