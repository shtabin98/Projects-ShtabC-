#pragma once
#include "Race.h"

#include <string>
#include <vector>

struct Str_Db_Pair;

class Race_Air : public Race
{
public:
	Race_Air();
	Str_Db_Pair all_calc(int(&type_ts)[7], int distantion);
};
