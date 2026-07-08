#pragma once
#include "Ground.h"
class Camel :
    public Ground
{
public:
    Camel();
    double calc(size_t distantion);
};

