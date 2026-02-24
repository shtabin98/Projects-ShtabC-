#include <iostream>
using namespace std;

int main()
{
	int const size{10};
	int massive[size]{ 5, 9, 5, 8, 589, 311, 711, 8958, 881, 1 };

	cout << "Массив: "; 
	for (int element{}; element < size; ++element)
	{
		cout << massive[element] << " ";
	}
	cout << endl;

	//Ищем максимальный элемент

	for (int i = 0; i < size - 1; ++i)
	{
		for (int j = 0; j < size - 1; ++j)
		{
			if (massive[j] > massive[j + 1])
			{
				int vremes{ massive[j] };
				massive[j] = massive[j + 1];
				massive[j + 1] = vremes;
			}
		}
	}

	cout << "Максимальный элемент: ";
	cout << massive[9] << endl;
	
	//Ищем минимальный элемент

	cout << "Минимальный элемент: ";
	cout << massive[0] << endl;

	return 0;
}