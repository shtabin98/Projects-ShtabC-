#include <iostream>
#include <cmath>

void print_pyramid(int* arr, int size);
void search_pyramid(int* arr, int size);

int main()
{
	int size{};
	int* arr = new int[10] {16, 11, 9, 10, 5, 6, 8, 1, 2, 4};
	print_pyramid(arr, 10);
	search_pyramid(arr, 10);

	return 0;
}

void print_pyramid(int* arr, int size)
{
	std::cout << "Исходный массив: ";

	for (int i = 0; i < size; ++i)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "Пирамида: " << std::endl;
	for (int i = 0; i < size; ++i)
	{
		int stupen = static_cast<int>(std::log10(i + 1) / std::log10(2));
		if (i == 0)
		{
			std::cout << 0 << " root " << arr[i] << std::endl;
		}
		else
		{
			int parent = (i - 1) / 2;
			if (i % 2 != 0)
			{
				std::cout << stupen << " left " << "(" << arr[parent] << ") " << arr[i] << std::endl;
			}
			else
			{
				std::cout << stupen << " right " << "(" << arr[parent] << ") " << arr[i] << std::endl;
			}
		}
	}
}

void print_search(int* arr, int size)
{
	int level = 0;
	if (size > 0) {
		level = static_cast<int>(std::log2(static_cast<double>(size + 1)));
	}

	if (size == 0) {
		std::cout << level << " root " << arr[size];
	}
	else {
		int parent = (size - 1) / 2;
		bool is_left = (size % 2 != 0);
		const char* type = is_left ? "left" : "right";
		std::cout << level << " " << type << " (" << arr[parent] << ") " << arr[size];
	}
}

void search_pyramid(int* arr, int size)
{
	int stupen = 0;

	while (true)
	{
		std::cout << "Вы находитесь здесь: ";
		print_search(arr, stupen);
		std::cout << "\n";

		std::cout << "Введите команду: ";
		std::string search;
		std::cin >> search;

		if (search == "exit")
		{
			break;
		}

		int next = -1;
		std::string er_msg;

		if (search == "up") {
			if (stupen == 0) {
				er_msg = "Ошибка! Отсутствует родитель.";
			}
			else {
				next = (stupen - 1) / 2;
			}
		}
		else if (search == "left") {
			int left_child = 2 * stupen + 1;
			if (left_child >= static_cast<int>(size)) {
				er_msg = "Ошибка! Отсутствует левый потомок.";
			}
			else {
				next = left_child;
			}
		}
		else if (search == "right") {
			int right_child = 2 * stupen + 2;
			if (right_child >= static_cast<int>(size)) {
				er_msg = "Ошибка! Отсутствует правый потомок.";
			}
			else {
				next = right_child;
			}
		}
		else {
			er_msg = "Ошибка! Неизвестная команда.";
		}

		if (!er_msg.empty())
		{
			std::cout << er_msg << "\n";
		}
		else
		{
			stupen = next;
			std::cout << "Ок\n";
		}
	}
}

