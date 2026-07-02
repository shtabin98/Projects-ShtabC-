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
	double time_to_chill = converter_in_hour(_time_to_chill);
	double chill = converter_in_hour(_chill);

	double travel_time = static_cast<double> (distantion) / static_cast<double> (_speed);
	int intervals = static_cast<int>(travel_time / time_to_chill) - 1;

	if (intervals == 0)
	{
		return travel_time;
	}
	
	double total_rest_time = intervals * chill;
	double total = (travel_time + total_rest_time);

	return total;
}