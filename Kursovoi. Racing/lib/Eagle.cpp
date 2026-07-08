#include "Eagle.h"

Eagle::Eagle()
	: Air()
{
	_type_ts = 6
		; _speed = 8
		; _kf = 0.06;
}

double Eagle::calc(size_t distantion)
{
	double travel_time = static_cast<double>(distantion) * (1.0 - _kf) / static_cast<double>(_speed);
	return travel_time;
}