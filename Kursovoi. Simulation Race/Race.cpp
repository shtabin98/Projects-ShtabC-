#include "Race.h"

#include "Camel.h"
#include "Camel_runner.h"
#include "Centaur.h"
#include "Allterrain_boots.h"
#include "Flying_carpet.h"
#include "Eagle.h"
#include "Broom.h"

#include <algorithm>
#include <iostream>

Race::Race(){}

Str_Db_Pair Race::all_calc(int(&type_ts)[7], int distantion) const
{
	std::string oboznach[7] = { " "," "," "," "," "," "," " };
	double sorted[7] = { 0.0,0.0,0.0,0.0,0.0,0.0,0.0 };

	if (type_ts[0] == 1)
	{
		Camel Camel;
		sorted[0] = Camel.calc(distantion);
		oboznach[0] = "Верблюд";
	}
	if (type_ts[1] == 1)
	{
		Camel_runner Camel_runner;
		sorted[1] = Camel_runner.calc(distantion);
		oboznach[1] = "Верблюд-быстроход";
	}
	if (type_ts[2] == 1)
	{
		Centaur Centaur;
		sorted[2] = Centaur.calc(distantion);
		oboznach[2] = "Кентавр";
	}
	if (type_ts[3] == 1)
	{
		Allterrain_boots Allterrain_boots;
		sorted[3] = Allterrain_boots.calc(distantion);
		oboznach[3] = "Ботинки-вездеходы";
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
