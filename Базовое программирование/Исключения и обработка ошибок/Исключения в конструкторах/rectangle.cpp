#include "rectangle.h"
#include "exp.h"

rectangle::rectangle()
	: quadrilateral()
{
	_figura = "Прямоугольник";
	_a =_c; _d = _b;
	_A = 90;
	_B = _A; _C = _B; _D = _C;
}

bool rectangle::virt_method()
{
	std::string er{ "Ошибка создания фигуры.Причина: \nколичество сторон не равно 4 \nи/или сумма углов не равна 360 \nи/или стороны a,c и b,d попарно не равны \nи/или все углы не равны 90\n" };
	int plus = _A + _B + _C + _D;
	if (plus != 360) throw expection(er);
	else if (get_storon() != 4) throw expection(er);
	else if (_a !=_c) throw expection(er);
	else if (_d != _b) throw expection(er);
	else if (_A != 90) throw expection(er);
	else if (_B != _A) throw expection(er);
	else if (_C != _B) throw expection(er);
	else if (_D != _C) throw expection(er);
};