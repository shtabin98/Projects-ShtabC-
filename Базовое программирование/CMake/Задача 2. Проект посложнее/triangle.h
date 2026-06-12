#pragma once

#include "figure.h"

class triangle
	: public figure
{
public:
	triangle();
	virtual void print_info() const;
};