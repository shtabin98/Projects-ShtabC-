#pragma once
#include "figure.h"

class quadrilateral : public figure
{
public:
	quadrilateral();
	virtual void print_info() const;
	virtual bool virt_method();
};

