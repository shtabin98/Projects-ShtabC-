#include <iostream>

int main()
{
	int size{0};
	
	std::cout << "Введите размер массива: ";
	std::cin >> size; std::cout << std::endl;

	int* arr = new int[size];

	for (int i = 0; i < size; ++i)
	{
		std::cout << "arr[" << i << "] = ";
		std::cin >> arr[i];
	}

	std::cout << "Введенный массив: ";

	for (int i = 0; i < size; ++i)
	{
		std::cout << arr[i] << " ";
	}
	delete[] arr;

	return 0;
}