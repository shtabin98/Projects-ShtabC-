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
	double time_to_chill = converter_in_hour(_time_to_chill);
	double chill = converter_in_hour(_chill);

	double travel_time = static_cast<double> (distantion) / static_cast<double> (_speed);
	int intervals = static_cast<int>(travel_time / time_to_chill) - 1;
	
	if (intervals == 0)
	{
		return travel_time;
	}
	
	const double first_rest = time_to_chill + chill;
	double second_chill = 8.0 / 60.0;

	const double sled_rest = time_to_chill + second_chill;
	double total_rest_time = first_rest;

	for (int i = 1; i < intervals; ++i)
	{
		total_rest_time += sled_rest;
	}

	double total = (travel_time + total_rest_time) ;

	return total;
}







