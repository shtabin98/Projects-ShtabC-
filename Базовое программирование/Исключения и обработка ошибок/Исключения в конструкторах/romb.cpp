#include "romb.h"
#include "exp.h"

romb::romb()
	: quadrilateral()
{
	_b = _a; _c = _b; _d = _c;
	_A = 100; _C = _A; _D = _B;
	_figura = "Ромб";
	_er = "Ошибка создания фигуры.Причина: количество сторон не равно 4 и/или сумма углов не равна 360 \nи/или все стороны не равны и/или углы A,C и B,D попарно не равны ";
	int plus = _A + _B + _C + _D;
	if (plus != 360) throw expection(get_er());
	else if (get_storon() != 4) throw expection(get_er());
	else if (_a != _b) throw expection(get_er());
	else if (_c != _b) throw expection(get_er());
	else if (_d != _c) throw expection(get_er());
	else if (_C != _A) throw expection(get_er());
	else if (_B != _D) throw expection(get_er());
}