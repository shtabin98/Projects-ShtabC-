#include "parallelogram.h"
#include "exp.h"

parallelogram::parallelogram()
	: quadrilateral()
{
	_c = _a; _d = _b;
	_A = 80; _B = 100;
	_C = _A; _D = _B;
	_figura = "Параллелограмм";
	_er = "Ошибка создания фигуры.Причина: количество сторон не равно 4 \nи/или сумма углов не равна 360 и/или стороны a,c и b,d попарно не равны \nи/или углы A,C и B,D попарно не равны \n";
	int plus = _A + _B + _C + _D;
	if (plus != 360) throw expection(get_er());
	else if (get_storon() != 4) throw expection(get_er());
	else if (_a != _c) throw expection(get_er());
	else if (_d != _b) throw expection(get_er());
	else if (_C != _A) throw expection(get_er());
	else if (_B != _D) throw expection(get_er());
}