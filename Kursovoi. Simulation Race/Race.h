#pragma once

#include <string>
#include <vector>

struct Str_Db_Pair
{
	std::vector<std::string> strings;
	std::vector<double> doubles;
};

class Race
{
public:
	Race();
	Str_Db_Pair all_calc(int (&type_ts)[7], int distantion) const;
};

