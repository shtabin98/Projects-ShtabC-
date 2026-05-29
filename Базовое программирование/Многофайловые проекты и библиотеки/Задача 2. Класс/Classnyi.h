#pragma once

class Counter
{
	int __num{ 1 };
public:
	void add(); void substract(); int equality();
	Counter(int num)
	{
		__num = num;
	};
	Counter() {};
};

