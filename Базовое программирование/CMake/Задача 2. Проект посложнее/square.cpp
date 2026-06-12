#include "square.h"

square::square()
	:quadrilateral()
{
	_b = _a; _c = _b; _d = _c;
	_A = 90;
	_B = _A; _C = _B; _D = _C;
	_figura = "Квадрат: ";
}