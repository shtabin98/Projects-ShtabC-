#include <iostream>

namespace math 
{
	namespace stas {int calc(int x, int y);}
	namespace misha {int calc(int x, int y);}
	namespace lexa{int calc(int x, int y);}
	namespace anatol{int calc(int x, int y);}
}

int main()
{
	int x{ 6 }, y{ 9 };
	std::cout << "x = " << x << ", y = " << y << std::endl;
	std::cout << math::stas::calc(x, y) << std::endl;
	std::cout << math::misha::calc(x, y) << std::endl;
	std::cout << math::lexa::calc(x, y) << std::endl;
	std::cout << math::anatol::calc(x, y) << std::endl;

	return EXIT_SUCCESS;
}

int math::stas::calc(int x, int y)
{
	std::cout << "Сложение: "; //<< std::endl;
	return x + y;
}

int math::misha::calc(int x, int y)
{
	std::cout << "Вычитание: "; //<< std::endl;
	return x - y;
}

int math::lexa::calc(int x, int y)
{
	std::cout << "Умножение: "; //<< std::endl;
	return x * y;
}

int math::anatol::calc(int x, int y)
{
	std::cout << "Деление: "; //<< std::endl;
	return x / y;
}