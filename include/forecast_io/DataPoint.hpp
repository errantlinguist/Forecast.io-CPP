#ifndef DATAPOINT_HPP
#define DATAPOINT_HPP

#include <ctime>
#include <string>

#include "DataOverview.hpp"
#include "Precipitation.hpp"
#include "../math/RadialVelocity.hpp"

namespace forecast_io
{

class DataPoint
{
public:
    DataPoint();
    DataPoint(time_t time, DataOverview overview, double cloudCover, double dewPoint, double humidity,
              double ozone, Precipitation precipitation, double pressure, double visibility, math::RadialVelocity wind);

    // Constant getters ---------------------------------------------------------
    double getCloudCover() const
    {
        return cloudCover;
    }

    double getDewPoint() const
    {
        return dewPoint;
    }

    double getHumidity() const
    {
        return humidity;
    }

    const DataOverview& getOverview() const
    {
        return overview;
    }

    double getOzone() const
    {
        return ozone;
    }

    const Precipitation& getPrecipitation() const
    {
        return precipitation;
    }

    double getPressure() const
    {
        return pressure;
    }

    time_t getTime() const
    {
        return time;
    }

    double getVisibility() const
    {
        return visibility;
    }

    const math::RadialVelocity& getWind() const
    {
        return wind;
    }

    // Non-constant getters -----------------------------------------------------
    DataOverview& getOverview()
    {
        return overview;
    }

    Precipitation& getPrecipitation()
    {
        return precipitation;
    }

    math::RadialVelocity& getWind()
    {
        return wind;
    }

    // Setters ------------------------------------------------------------------

    void setCloudCover(double cloudCover)
    {
        this->cloudCover = cloudCover;
    }

    void setDewPoint(double dewPoint)
    {
        this->dewPoint = dewPoint;
    }

    void setHumidity(double humidity)
    {
        this->humidity = humidity;
    }

    void setOverview(DataOverview overview)
    {
        this->overview = overview;
    }

    void setOzone(double ozone)
    {
        this->ozone = ozone;
    }

    void setPrecipitation(Precipitation precipitation)
    {
        this->precipitation = precipitation;
    }

    void setPressure(double pressure)
    {
        this->pressure = pressure;
    }

    void setTime(time_t time)
    {
        this->time = time;
    }

    void setVisibility(double visibility)
    {
        this->visibility = visibility;
    }

    void setWind(math::RadialVelocity wind)
    {
        this->wind = wind;
    }

private:

    double cloudCover;
    double dewPoint;
    double humidity;
    DataOverview overview;
    double ozone;
    Precipitation precipitation;
    double pressure;
    time_t time;
    double visibility;
    math::RadialVelocity wind;

};

}

#endif // DATAPOINT_HPP
