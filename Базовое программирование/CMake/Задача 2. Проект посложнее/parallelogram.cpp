#include "parallelogram.h"

parallelogram::parallelogram()
	: quadrilateral()
{
	_c = _a; _d = _b;
	_C = _A; _D = _B;
	_figura = "Параллелограмм: ";
}