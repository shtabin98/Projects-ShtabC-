#include "Race_Air.h"

#include "Flying_carpet.h"
#include "Eagle.h"
#include "Broom.h"

#include <algorithm>
#include <iostream>

Race_Air::Race_Air() {}

Str_Db_Pair Race_Air::all_calc(int(&type_ts)[7], int distantion)
{
	std::string oboznach[7] = { " "," "," "," "," "," "," " };
	double sorted[7] = { 0.0,0.0,0.0,0.0,0.0,0.0,0.0 };

	if (type_ts[0] == 1 && type_ts[1] == 1 && type_ts[2] == 1 && type_ts[3] == 1)
	{
		std::cout << "Нельзя зарегистрировать данный вид траспорта на эту гонку!";
	}

	if (type_ts[4] == 1)
	{
		Flying_carpet Flying_carpet;
		sorted[4] = Flying_carpet.calc(distantion);
		oboznach[4] = "Ковёр-самолёт";
	}
	if (type_ts[5] == 1)
	{
		Eagle Eagle;
		sorted[5] = Eagle.calc(distantion);
		oboznach[5] = "Орёл";
	}
	if (type_ts[6] == 1)
	{
		Broom Broom;
		sorted[6] = Broom.calc(distantion);
		oboznach[6] = "Метла";
	}

	Str_Db_Pair res;
	res.strings.reserve(7);
	res.doubles.reserve(7);

	for (int i = 0; i < 7; ++i) {
		res.strings.push_back(oboznach[i]);
		res.doubles.push_back(sorted[i]);
	}

	size_t n = res.doubles.size();
	for (size_t i = 0; i < n - 1; ++i)
	{
		size_t minIdx = i;
		for (size_t j = i + 1; j < n; ++j)
		{
			if (res.doubles[j] < res.doubles[minIdx])
			{
				minIdx = j;
			}
		}
		if (minIdx != i)
		{
			std::swap(res.doubles[i], res.doubles[minIdx]);
			std::swap(res.strings[i], res.strings[minIdx]);
		}
	}

	return res;
}
