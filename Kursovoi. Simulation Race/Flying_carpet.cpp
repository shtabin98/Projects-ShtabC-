#include "Flying_carpet.h"

Flying_carpet::Flying_carpet()
	: Air()
{
		_type_ts = 5
		; _speed = 10
		; _kf = 1.0;
}

double Flying_carpet::calc(size_t distantion)
{
	if (distantion < 1000) {_kf = 0.0;}
	else if (distantion >= 1000 && distantion < 5000) {_kf = 0.03;}
	else if (distantion >= 5000 && distantion < 10000) {_kf = 0.1;}
	else { _kf = 0.05;}

	double travel_time = static_cast<double>(distantion) * (1.0 -_kf) / static_cast<double>(_speed);

	return travel_time;
}
