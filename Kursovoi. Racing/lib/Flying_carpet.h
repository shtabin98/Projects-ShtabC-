#pragma once
#include "Air.h"
class Flying_carpet :
    public Air
{
public:
    Flying_carpet();
    double calc(size_t distantion);
};

