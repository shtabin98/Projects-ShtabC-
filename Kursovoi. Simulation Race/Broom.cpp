#include "Broom.h"

Broom::Broom()
	: Air()
{
	_type_ts = 7
		; _speed = 20
		; _kf = 0.01;
}

double Broom::calc(size_t distantion)
{
	int count  = 0;
	double s = static_cast<double>(distantion) / 1000.0;
	
	if (s > 1.0)
	{
		for (int i = 0; s > i; ++i)
		{
			++count;
		}
	}

	if (distantion < 1000) { _kf = 0.0; }
	else { _kf = 0.01 * static_cast<double>(count); }
	double travel_time = static_cast<double>(distantion) * (1.0 - _kf) / static_cast<double>(_speed);

	return travel_time;
}