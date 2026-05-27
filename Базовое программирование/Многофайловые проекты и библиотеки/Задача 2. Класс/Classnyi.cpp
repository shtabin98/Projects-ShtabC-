#include "Classnyi.h"

void Counter::plus()
{
	this->__num += 1;
};

void Counter::minus()
{
	this->__num -= 1;
};

int Counter::ravno()
{
	return __num;
};