#pragma once
#include "Ground.h"
class Camel_runner :
    public Ground
{
public:
    Camel_runner();
    double calc(size_t distantion);
};

