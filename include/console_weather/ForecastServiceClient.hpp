#ifndef FORECASTSERVICECLIENT_HPP
#define FORECASTSERVICECLIENT_HPP

#include <memory>

#include "../curl/WriteFunctionClient.hpp"
#include "../math/MeasurementSystem.hpp"

// Forward declarations
namespace forecast_io
{
class Forecast;
}

namespace console_weather
{

class ForecastServiceClient
{
public:
    ForecastServiceClient(curl::WriteFunctionClient& curlClient, math::MeasurementSystem measurementUnits);

    std::unique_ptr<forecast_io::Forecast> get(const char* url);

private:
    math::MeasurementSystem measurementUnits;
    curl::WriteFunctionClient& curlClient;
};

}

#endif // FORECASTSERVICECLIENT_HPP
