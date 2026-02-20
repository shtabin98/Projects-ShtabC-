#include <iostream>
using namespace std;

int main()
{
	int sumattttor;
	int sumattttoring = 0;

	do
	{
		cout << "Введите целое число или число '0', чтобы закончить:" << endl;
		cin >> sumattttor;
		sumattttoring += sumattttor;
	} while (sumattttor != 0);

	cout << "Сумма: " << sumattttoring << endl;

	return EXIT_SUCCESS;
}