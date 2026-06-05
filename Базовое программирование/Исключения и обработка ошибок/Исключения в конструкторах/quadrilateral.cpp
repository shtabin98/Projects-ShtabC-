#include "quadrilateral.h"
#include "exp.h"

quadrilateral::quadrilateral()
	: figure(" ",4,10,20,30,40,50,80,130,100)
{ 
	_figura = "Четырехугольник";
}

bool quadrilateral::virt_method()
{
	std::string er{ "Ошибка создания фигуры.Причина: \nколичество сторон не равно 4 или сумма углов не равна 360\n" };
	int plus = _A + _B + _C + _D;
	if (plus != 360) throw expection(er);
	else if (get_storon() != 4) throw expection(er);
};

void quadrilateral::print_info() const
{
	std::cout << get_figura() << " (cтороны " << get_a() << " " << get_b()
		<< " " << get_c() << " " << get_d() << "; yглы " << get_A() << " " << get_B()
		<< " " << get_C() << " " << get_D() << ") создан" << std::endl;
}



