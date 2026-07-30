#include <iostream>
#include <cmath>

void print_pyramid(int* arr, int size);

int main()
{
	int size{};

	std::cout << "Введите  размер массива: ";
	std::cin >> size;
	
	int* arr = new int[size] {16, 11, 9, 10, 5, 6, 8, 1, 2, 4};

	for (int i = 0; i < size; ++i)
	{
		std::cout << "Введите arr[" << i << "]: ";
		std::cin >> arr[i];
	}

	print_pyramid(arr, size);

	return 0;
}

void print_pyramid(int* arr, int size)
{
	std::cout << "Исходный массив: ";
 
	for (int i = 1; i < size; ++i)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	std::cout <<"Пирамида: " << std::endl;
	for (int i = 0; i < size; ++i)
	{
		int stupen = static_cast<int>(std::log10(i+1) / std::log10(2));
		if (i == 0)
		{
			std::cout  << 0 << " root " << arr[i] << std::endl;
		}
		else
		{
			int parent = (i - 1) / 2;
			if (i % 2 != 0)
			{
				std::cout << stupen <<" left " << "(" << arr[parent] << ") " << arr[i] << std::endl;
			}
			else
			{
				std::cout << stupen << " right " << "(" << arr[parent] << ") " << arr[i] << std::endl;
			}
		}
	}
}
