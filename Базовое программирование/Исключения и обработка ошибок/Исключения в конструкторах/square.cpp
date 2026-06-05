#include "square.h"
#include "exp.h"

square::square()
	:quadrilateral()
{
	_b = _a; _c = _b; _d = _c;
	_A = 90;
	_B = _A; _C = _B; _D = _C;
	_figura = "Квадрат";
}

bool square::virt_method()
{
	std::string er{ "Ошибка создания фигуры.Причина: \nколичество сторон не равно 4 \nи/или сумма углов не равна 360 \nи/или все стороны не равны \nи/или все углы не равны \n" };
	int plus = _A + _B + _C + _D;
	if (plus != 360) throw expection(er);
	else if (get_storon() != 4) throw expection(er);
	else if (_a != _b) throw expection(er);
	else if (_c != _b) throw expection(er);
	else if (_A != 90) throw expection(er);
	else if (_B != _A) throw expection(er);
	else if (_C != _B) throw expection(er);
	else if (_D != _C) throw expection(er);
};