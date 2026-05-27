#pragma once

class Counter
{
	int __num{ 1 };
public:
	void plus(); void minus(); int ravno();
	Counter(int num)
	{
		__num = num;
	};
	Counter() {};
};

