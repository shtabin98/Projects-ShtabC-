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
	double time_to_chill = converter_in_hour(_time_to_chill);
	double chill = converter_in_hour(_chill);

	double travel_time = static_cast<double> (distantion) / static_cast<double> (_speed);
	int intervals = static_cast<int>(travel_time / time_to_chill) - 1;

	if (intervals == 0)
	{
		return travel_time;
	}

	double second_chill = 6.5 / 60.0;
	double third_chill = 8.0 / 60.0;
	double total_rest_time = chill + second_chill + (intervals - 2) * third_chill;
	double total = (travel_time + total_rest_time);

	return total;
}