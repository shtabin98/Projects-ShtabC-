#include <iostream>

double* create_array(int a);

int main()
{
	int size{ 0 };

	std::cout << "Введите размер массива: ";
	std::cin >> size; 

	double* arr = create_array(size);	

	std::cout << "Массив: ";
	for (int i = 0; i < size; ++i)
	{
		std::cout << arr[i] << " ";
	}
	delete[] arr;
	
	return 0;
}


double* create_array(int a)
{
	double* arr = new double[a]();
	return arr;
}
