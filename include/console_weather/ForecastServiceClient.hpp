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
    ForecastServiceClient(curl::CallbackClient& curlClient, math::MeasurementSystem measurementUnits);

    std::unique_ptr<forecast_io::Forecast> get(const char* url);

private:
    math::MeasurementSystem measurementUnits;
    curl::CallbackClient& curlClient;
};

}

#endif // FORECASTSERVICECLIENT_HPP
