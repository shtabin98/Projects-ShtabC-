#pragma once
#include "Ground.h"
class Allterrain_boots :
    public Ground
{
public:
    Allterrain_boots();
    double calc(size_t distantion);
};

