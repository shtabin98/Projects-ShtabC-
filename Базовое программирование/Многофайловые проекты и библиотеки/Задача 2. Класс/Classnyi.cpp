#include "Classnyi.h"

void Counter::add()
{
	this->__num += 1;
};

void Counter::subtract()
{
	this->__num -= 1;
};

int Counter::equality()
{
	return __num;
};
