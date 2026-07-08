#pragma once
class Transport
{
protected:
	bool _spec_ts{};//тип ТС
	size_t _type_ts{};// вид ТС
	int _speed{};//Скорость ТС
	double _time_to_chill{};//Время без остановки до отдыха
	double _chill{};//Длительность отдыха
	double _kf{};//Коэффициент сокращения расстояния
public:
	Transport(
		bool spec_ts
		, size_t type_ts
		, int speed
		, double time_to_chill
		, double chill
		, double kf);
	Transport();
	virtual double converter_in_hour(double time) const;
};

