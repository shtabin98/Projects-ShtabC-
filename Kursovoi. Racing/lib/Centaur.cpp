#include "Centaur.h"

Centaur::Centaur()
	: Ground()
{
	_type_ts = 3
		; _speed = 15
		; _time_to_chill = 8
		; _chill = 2
		; _kf;
}

double Centaur::calc(size_t distantion)
{
	double travel_time = static_cast<double> (distantion) / static_cast<double> (_speed);
	int intervals = (distantion / (_time_to_chill * _speed));

	if (intervals == 0)
	{
		return travel_time;
	}
	
	double total_rest_time = intervals * _chill;
	double total = (travel_time + total_rest_time);

	return total;
}
