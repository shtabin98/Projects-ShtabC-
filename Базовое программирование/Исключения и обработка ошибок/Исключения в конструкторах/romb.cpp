#include "romb.h"
#include "exp.h"

romb::romb()
	: quadrilateral()
{
	_b = _a; _c = _b; _d = _c;
	_A = 100; _C = _A; _D = _B;
	_figura = "Ромб";
}

bool romb::virt_method()
{
	std::string er{ "Ошибка создания фигуры.Причина: \nколичество сторон не равно 4 \nи/или сумма углов не равна 360 \nи/или все стороны не равны \nи/или углы A,C и B,D попарно не равны \n" };
	int plus = _A + _B + _C + _D;
	if (plus != 360) throw expection(er);
	else if (get_storon() != 4) throw expection(er);
	else if (_a != _b) throw expection(er);
	else if (_c != _b) throw expection(er);
	else if (_d != _c) throw expection(er);
	else if (_C != _A) throw expection(er);
	else if (_B != _D) throw expection(er);
};