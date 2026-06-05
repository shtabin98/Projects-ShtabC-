#include "equilateral.h"
#include "exp.h"

equilateral::equilateral()
	: triangle()
{
	_b = _a; _c = _b;
	_A = 60;
	_B = _A; _C = _B;
	_figura = "Равноcторонний треугольник";
}

bool equilateral::virt_method()
{
	std::string er{ "Ошибка создания фигуры.Причина: \nколичество сторон не равно 3 \nи/или сумма углов не равна 180 \nи/или сторона а, b и с не равны  \nи/или уголы А, B и С не равны \n" };
	int plus = _A + _B + _C;
	if (get_storon() != 3) throw expection(er);
	else if (plus != 180) throw expection(er);
	else if (_b != _a) throw expection(er);
	else if (_c != _b) throw expection(er);
	else if (_A != 60) throw expection(er);
	else if (_B != _A) throw expection(er);
	else if (_C != _B) throw expection(er);
};