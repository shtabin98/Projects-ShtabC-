#pragma once
#include "figure.h"

class expection :
    public std::domain_error
{
    std::string expect{};
public:
    expection(std::string expect);
    std::string get_expect() const;
};

