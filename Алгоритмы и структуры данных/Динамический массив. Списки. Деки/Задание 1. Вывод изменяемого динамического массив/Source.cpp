#include <iostream>

void print_dynamic_array(int* arr, int size_fact, int size_logic);

int main()
{
	int size_fact{}, size_logic{};

	std::cout << "Введите фактический размер массива: ";
	std::cin >> size_fact;
	std::cout << "Введите логический размер массива: ";
	std::cin >> size_logic;
	if (size_fact < size_logic)
	{
		std::cout << "Ошибка! Логический размер массива не может превышать физический!";
		return 0;
	}
	
	int *arr = new int[size_fact];

	print_dynamic_array(arr, size_fact,size_logic);

	delete[] arr;

	return 0;
}

void print_dynamic_array(int* arr, int size_fact,int size_logic)
{
	for (int i = 0; i < size_logic; ++i)
	{
		std::cout << "Введите arr[" << i << "]: ";
		std::cin >> arr[i];
	}
	int minus = size_fact - size_logic;

	for (int i = size_logic; i < size_fact; ++i)
	{
		arr[i] = 0;
	}

	std::cout << "Динамический массив: ";

	for (int i = 0; i < size_fact; ++i)
	{
		if (arr[i] == 0)
		{
			std::cout << "_ ";
		}
		else
		{
			std::cout << arr[i] << " ";
		}
	}
}