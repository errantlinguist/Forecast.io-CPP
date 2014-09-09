#ifndef SINGLEDATAPOINTDETAILSLISTENER_HPP
#define SINGLEDATAPOINTDETAILSLISTENER_HPP

#include "DataPointDetailsListener.hpp" // Base class: forecast_io::listeners::DataPointDetailsListener

namespace forecast_io
{

namespace listeners
{

class SingleDataPointDetailsListener: public forecast_io::listeners::DataPointDetailsListener
{

public:

	virtual ~SingleDataPointDetailsListener() = default;

	virtual void notifyApparentTemperature(double temperature);
	virtual void notifyTemperature(double temperature);

};

}

}

#endif // SINGLEDATAPOINTDETAILSLISTENER_HPP
