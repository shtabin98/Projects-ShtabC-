#include <iostream>

int swap (int &a, int &b);

int main(int argc, char** argv)
{
	int a = 5, b = 8;

	std::cout << "a = " << a << ", b = " << b << std::endl;

	swap(a, b);

	std::cout << "a = " << a << ", b = " << b << std::endl;

	return 0;
}


int swap(int &a, int &b)
{
	int c = b;
	b = a;
	a = c;

	return a,b;
}