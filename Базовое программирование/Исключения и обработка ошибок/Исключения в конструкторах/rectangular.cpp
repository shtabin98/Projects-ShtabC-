#include "rectangular.h"
#include "exp.h"

rectangular::rectangular()
	: triangle(){
	_A = 30;
	_C = 90;
	_figura = "Прямоугольный треугольник";
}

bool rectangular::virt_method()
{
	std::string er{ "Ошибка создания фигуры.Причина: \nколичество сторон не равно 3 \nи/или сумма углов не равна 180 \nи/или угол C не равен 90\n" };
	int plus = _A + _B + _C;
	if (get_storon() != 3) throw expection(er);
	else if (plus != 180) throw expection(er);
	else if (_C != 90) throw expection(er);
};