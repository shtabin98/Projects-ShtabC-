#include "Camel.h"

Camel::Camel()
	: Ground()
{
		_type_ts = 1
		; _speed = 10 
		; _time_to_chill = 30
		; _chill = 5
		; _kf;
}

double Camel::calc(size_t distantion) 
{
	double travel_time = static_cast<double> (distantion) / static_cast<double> (_speed);
	int intervals = (distantion / (_time_to_chill * _speed)) - 1;
	
	if (intervals == 0)
	{
		return travel_time;
	}
	
	double second_chill = 8.0;
	double rest = _chill + (second_chill*(intervals-1));

	double total = (travel_time + rest);

	return total;
}







