#include <iostream>
using namespace std;

//Рекурсивная функция, для малых Фибоначчей
long long int fibonachi(int a);

int main()
{
	int a{};
	
	cout << "Введите число: ";
	cin >> a;
	cout << "Числа Фибоначчи: ";

	for (int i = 0; i < a; i++)
	{
		cout << fibonachi(i) << " ";
	}
}

long long int fibonachi(int a)
{

	if (a < 2)
	{
		return a;
	}
	else
	{
		long long int b = fibonachi(a - 1);
		long long int c = fibonachi(a - 2);
		long long int d{};

		d = b + c;

		return d;
	}
}
