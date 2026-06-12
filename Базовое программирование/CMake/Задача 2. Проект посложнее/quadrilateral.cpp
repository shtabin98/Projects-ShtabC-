#include "quadrilateral.h"


quadrilateral::quadrilateral()
	: figure(" ", 4, 10, 20, 30, 40, 50, 60, 70, 80)
{
	_figura = "Четырехугольник";
}

void quadrilateral::print_info() const
{
	std::cout << get_figura() << std::endl << "Стороны: a=" << get_a() << " b=" << get_b()
		<< " c=" << get_c() << " d=" << get_d() << std::endl
		<< "Углы: A=" << get_A() << " B=" << get_B()
		<< " C=" << get_C() << " D=" << get_D() << std::endl << std::endl;
}
