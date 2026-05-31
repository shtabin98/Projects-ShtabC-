#include "romb.h"

romb::romb()
	: quadrilateral()
{
	_b = _a; _c = _b; _d = _c;
	_C = _A; _D = _B;
	_figura = "Ромб: ";
}