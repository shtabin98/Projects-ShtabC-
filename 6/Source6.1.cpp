#include <iostream>
using namespace std;

int sum(int x, int y);
int diff(int x, int y);
int multiplication(int x, int y);
double division(double x, double y);

int main(int argc, char** argv)
{
	int a{ 5 }, b{ 10 };
	
	int s = sum(a, b);
	int dif = diff(a, b);
	int mult = multiplication(a, b);
	double div = division(a, b);

	cout << a << " + " << b << " = " << s << endl;
	cout << a << " - " << b << " = " << dif << endl;
	cout << a << " * " << b << " = " << mult << endl;
	cout << a << " / " << b << " = " << div << endl;

	return 0;
}

//Функция суммы
int sum(int x, int y)
{
	return x + y;
}

//Функция вычитания
int diff(int x, int y)
{
	return x - y;
}

//Функция умножения
int multiplication(int x, int y)
{
	return x * y;
}

//Функция деления
double division(double x, double y)
{
	return x / y;
}