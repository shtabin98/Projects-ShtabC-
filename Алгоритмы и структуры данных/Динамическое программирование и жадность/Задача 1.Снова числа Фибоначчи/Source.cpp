#include <iostream>
#include <vector>

int main()
{
	int size{};

	std::cout << "Введите размерность ряда чисел Фибоначчи: ";
	std::cin >> size;

	if (size <= 0)
	{
		std::cout << "Нельзя вводить 0! "; 
		return 0;
	}
	
	if (size == 1)
	{
		std::cout << "Ряд чисел Фибоначчи до " << size << " элемента(включительно):\n0";
		return 0;
	}

	std::vector<size_t> fiba(size);

	fiba[0] = 0;
	fiba[1] = 1;

	for (int i = 2; i < size ; ++i)
	{
		fiba[i] = fiba[i - 2] + fiba[i - 1];
	}
	
	std::cout << "Ряд чисел Фибоначчи до " << size  << " элемента(включительно):\n";
	
	for (int i = 0; i < size ; ++i)
	{
		std::cout << fiba[i] << " ";
	}

	return 0;
}