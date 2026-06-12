#include "rectangle.h"

rectangle::rectangle()
	: quadrilateral()
{
	_figura = "Прямоугольник: ";
	_a = _c; _d = _b;
	_A = 90;
	_B = _A; _C = _B; _D = _C;
}