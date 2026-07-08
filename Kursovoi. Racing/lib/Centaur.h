#pragma once
#include "Ground.h"
class Centaur :
    public Ground
{
public:
    Centaur();
    double calc(size_t distantion);
};

