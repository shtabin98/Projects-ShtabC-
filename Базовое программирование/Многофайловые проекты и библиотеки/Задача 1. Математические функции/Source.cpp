
#include <iostream>
#include "math_p.h"

int main()
{
	double i{}, j{};
	int pes{};
	std::cout << "Введите первое число: ";
	std::cin >> i;
	std::cout << "Введите второе число: ";
	std::cin >> j;
	std::cout << "Введите операцию (1 - сложение, 2 - вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень): ";
	std::cin >> pes;
	switch (pes)
	{
	case 1:
		std::cout << i << " + " << j << " = " << addition(i, j);
		break;
	case 2:
		std::cout << i << " - " << j << " = " << subtraction(i, j);
		break;
	case 3:
		std::cout << i << " * " << j << " = " << multiplication(i, j);
		break;
	case 4:
		std::cout << i << " / " << j << " = " << division(i, j);
		break;
	case 5:
		std::cout << i << " в степени " << j << " = " << exponentiation(i, j);
		break;
	}
	return 0;
}

