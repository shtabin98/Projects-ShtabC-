#include <iostream>
using namespace std;

//Нерекурсивная функция, для больших Фибоначчей
long long int *fibonachi(int size);

int main()
{
	int size{};

	cout << "Введите чиcло: ";
	cin >> size;

	cout << "Числа Фибоначчи: ";

	fibonachi(size);
	return 0;
}

long long int *fibonachi(int size) 
{
	const int a = 100;
	long long int mas[a]{};

	for (int i = 0; i < size; ++i)
	{
		mas[0] = 0;
		mas[1] = 1;

		for (int j = 1; j < size - 1; ++j)
		{
			long long int vremes{ mas[j] };
			mas[j + 1] = mas[j - 1] + mas[j];

		}

	}
	
	for (int element{}; element < size; ++element)
	{ 
		cout << mas[element] << " ";
	} 

	return mas;
}
