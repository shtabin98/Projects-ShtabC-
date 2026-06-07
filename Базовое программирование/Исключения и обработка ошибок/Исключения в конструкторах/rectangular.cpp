#include "rectangular.h"
#include "exp.h"

rectangular::rectangular()
	: triangle(){
	_A = 30;
	_C = 90;
	_figura = "Прямоугольный треугольник";
	_er = "Ошибка создания фигуры.Причина: количество сторон не равно 3 \nи/или сумма углов не равна 180 и/или угол C не равен 90";
	int plus = _A + _B + _C;
	if (get_storon() != 3) throw expection(get_er());
	else if (plus != 180) throw expection(get_er());
	else if (_C != 90) throw expection(get_er());
}