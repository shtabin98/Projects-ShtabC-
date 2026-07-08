#include "Camel_runner.h"

Camel_runner::Camel_runner()
	: Ground()
{
	_type_ts = 2
	; _speed = 40
	; _time_to_chill = 10
	; _chill = 5
	; _kf;
}

double Camel_runner::calc(size_t distantion)
{
	double travel_time = static_cast<double> (distantion) / static_cast<double> (_speed);
	int intervals = (distantion / (_time_to_chill * _speed)) - 1;

	if (intervals == 0)
	{
		return travel_time;
	}

	double second_chill = 6.5;
	double third_chill = 8.0;
	double total_rest_time = _chill + second_chill + (intervals - 1) * third_chill;
	double total = (travel_time + total_rest_time);

	return total;
}