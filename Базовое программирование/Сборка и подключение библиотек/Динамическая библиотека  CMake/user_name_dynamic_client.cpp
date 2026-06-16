#include <iostream>
#include "user_name_dynamic.h"

int main()
{
    std::string name{ "" };
    std::cout << "Введите имя: ";
    std::cin >> name;
    user_name_dynamic::Leaver l;
    std::cout << l.leave(name);
}