#include <iostream>
#include "Classnyi.h"

int main()
{
	std::string task;
	int num{};

	std::cout << "Вы хотите указать начальное значение счетчика ? Введите да или нет: ";
	std::cin >> task;
	if (task == "да")
	{
		std::cout << "Введите начальное значение счетчика: ";
		std::cin >> num;
	}
	else num = 1;

	Counter count(num);

	do
	{
		std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
		std::cin >> task;
		if (task == "x" || task == "х")
		{
			std::cout << "До свидания\n";
			return 0;
		}
		else if (task == "+")
		{
			count.add();
		}
		else if (task == "-")
		{
			count.subtract();
		}
		else if (task == "=")
		{
			std::cout << count.equality() << std::endl;
		}
	} while (true);


	return 0;
}
