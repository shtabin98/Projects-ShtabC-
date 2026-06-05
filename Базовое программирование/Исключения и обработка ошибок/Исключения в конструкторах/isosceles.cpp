#include "isosceles.h"
#include "exp.h"

isosceles::isosceles()
	: triangle() {
	_c = _a; _C = _A;
	_B = 80;
	_figura = "Равнобедренный треугольник";
}

bool isosceles::virt_method()
{
	std::string er{ "Ошибка создания фигуры.Причина: \nколичество сторон не равно 3 \nи/или сумма углов не равна 180 \nи/или сторона а не равна стороне с \nи/или угол А не равен углу С \n" };
	int plus = _A + _B + _C;
	if (get_storon() != 3) throw expection(er);
	else if (plus != 180) throw expection(er);
	else if (_c != _a) throw expection(er);
	else if (_C != _A) throw expection(er);
};