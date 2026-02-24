#include <iostream> 
using namespace std;

int main()
{
	const int size{ 10 };
	int mas[size]{ 1,6,8,25,78,2,1200,150,54,20 };
	
	cout << "Массив до сортировки: ";
	for (int element{}; element < size; ++element)
	{
		cout << mas[element] << " ";
	}
	cout << endl;

	for (int i = 0; i < size - 1; ++i)
	{
		for (int j = 0; j < size - 1; ++j)
		{
			if (mas[j] > mas[j + 1])
			{
				int vremes{ mas[j] };
				mas[j] = mas[j + 1];
				mas[j + 1] = vremes;
			}
		}
	}

	cout << "Массив после сортировки: ";
	for (int element{}; element < size; ++element)
	{
		cout << mas[element] << " ";
	}
	cout << endl;

	return 0;
}