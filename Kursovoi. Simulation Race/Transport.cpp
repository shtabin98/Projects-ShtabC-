#include "Transport.h"

Transport::Transport(
	bool spec_ts
	, size_t type_ts
	, int speed
	, double time_to_chill
	, double chill
	, double kf) :  _spec_ts(spec_ts)
	, _type_ts(type_ts)
	, _speed(speed)
	, _time_to_chill(time_to_chill)
	, _chill(chill)
	, _kf(kf){ }

Transport::Transport() :
	_spec_ts(true)
	,_type_ts(1)
	,_speed(1)
	,_time_to_chill(1)
	,_chill(1)
	,_kf(1){ }

double Transport::converter_in_hour(double time) const
{
	time = time / 60.0;
	return time;
}
