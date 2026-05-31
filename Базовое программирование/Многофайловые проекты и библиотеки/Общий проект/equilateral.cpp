#include "equilateral.h"

equilateral::equilateral()
	: triangle()
{
	_b = _a; _c = _b;
	_A = 60;
	_B = _A; _C = _B;
	_figura = "Равноcторонний треугольник: ";
}