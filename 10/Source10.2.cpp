#include <iostream>

double* create_array(int a);

int main()
{
	int size{ 0 };

	std::cout << "Введите размер массива: ";
	std::cin >> size; 

	std::cout << "Массив: ";
	create_array(size);
	
	return 0;
}


double* create_array(int a)
{
	double* arr = new double[a]();
	for (int i = 0; i < a; ++i)
	{
		std::cout << arr[i] << " ";
	}
	return arr;
	delete[] arr;
}