#include "Allterrain_boots.h"

Allterrain_boots::Allterrain_boots()
	: Ground()
{
	_type_ts = 4
		; _speed = 6
		; _time_to_chill = 60
		; _chill = 10
		; _kf;
}

double Allterrain_boots::calc(size_t distantion)
{
	double travel_time = static_cast<double> (distantion) / static_cast<double> (_speed);
	int intervals = (distantion / (_time_to_chill * _speed));

	if (intervals == 0)
	{
		return travel_time;
	}

	double second_chill = 5.0;
	double total_rest_time = _chill + (intervals - 1) * second_chill;
	double total = (travel_time + total_rest_time);

	return total;
}