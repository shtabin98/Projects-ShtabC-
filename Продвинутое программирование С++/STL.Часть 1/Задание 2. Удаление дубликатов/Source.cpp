#include <iostream>
#include <set>

template<typename T>
void print_array(T arr)
{
	for (auto it = arr.rbegin(); it != arr.rend(); it++)
	{
		std::cout << *it << "\n";
	}
}

int main()
{
	int size{};
	int c{};
	std::cout << "Введите желаемое колличество элементов массива: ";
	std::cin >> size;
	std::set<int> S;
	
	std::cout << "Введите элементы массива: \n";
	for (auto i = 0; i < size; i++)
	{
		std::cin >> c;
		S.insert(c);
	}

	std::cout << "Ваш отсортированный массив без дублей: \n";
	print_array(S);
	return 0;
}