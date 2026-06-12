#include "triangle.h"

triangle::triangle()
    : figure(" ", 3, 10, 20, 30, 40, 50, 60, 70, 80)
{
    _figura = "Треугольник";
}

void triangle::print_info() const
{
    std::cout << get_figura() << std::endl
        << "Стороны: a=" << get_a() << " b=" << get_b()
        << " c=" << get_c() << std::endl
        << "Углы: A=" << get_A() << " B=" << get_B()
        << " C=" << get_C() << std::endl << std::endl;
}