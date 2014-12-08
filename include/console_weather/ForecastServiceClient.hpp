#ifndef FORECASTSERVICECLIENT_HPP
#define FORECASTSERVICECLIENT_HPP

#include <memory>

#include "../math/MeasurementSystem.hpp"

// Forward declarations
namespace curl
{
	class CallbackClient;
}
namespace forecast_io
{
	class Forecast;
}

namespace console_weather
{

class ForecastServiceClient
{
public:
    ForecastServiceClient(curl::CallbackClient& curlClient, math::MeasurementSystem measurementUnits) noexcept;

	/**
	 * @param[in] url The API URL get method to call.
	 * @return A pointer to a new Forecast object created from the data returned by the server.
	 * @throw json::ParseException If there was an error while parsing the response as JSON.
	 * @throw std::out_of_range If the amount of bytes to read from the server response overflows the parameter type for the JSON parser input.
	 * @throw CURLcode If the cURL library call returns a code other than CURLE_OK.
	**/
    std::unique_ptr<forecast_io::Forecast> get(const char* url);

private:
    math::MeasurementSystem measurementUnits;
    curl::CallbackClient& curlClient;
};

}

#endif // FORECASTSERVICECLIENT_HPP
