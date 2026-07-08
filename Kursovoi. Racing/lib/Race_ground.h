#pragma once
#include "Race.h"

#include <string>
#include <vector>

struct Str_Db_Pair;

class Race_ground : public Race
{
public:
	Race_ground();
	Str_Db_Pair all_calc(int(&type_ts)[7], int distantion);
};


