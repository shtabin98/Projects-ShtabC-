#pragma once

#include "figure.h"

class triangle
	: public figure
{
public:
	triangle();
	virtual bool virt_method();
	virtual void print_info() const;
};