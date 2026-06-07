#include "square.h"
#include "exp.h"

square::square()
	:quadrilateral()
{
	_b = _a; _c = _b; _d = _c;
	_A = 90;
	_B = _A; _C = _B; _D = _C;
	_figura = "Квадрат";
	_er = "Ошибка создания фигуры.Причина: количество сторон не равно 4 и/или сумма углов не равна 360 \nи/или все стороны не равны и/или все углы не равны";
	int plus = _A + _B + _C + _D;
	if (plus != 360) throw expection(get_er());
	else if (get_storon() != 4) throw expection(get_er());
	else if (_a != _b) throw expection(get_er());
	else if (_c != _b) throw expection(get_er());
	else if (_A != 90) throw expection(get_er());
	else if (_B != _A) throw expection(get_er());
	else if (_C != _B) throw expection(get_er());
	else if (_D != _C) throw expection(get_er());
}