#include <iostream>

class Counter
{
	size_t __num{ 1 };

public:
	void task_1(std::string task)
	{
		if (task == "да")
		{
			std::cout << "Введите начальное значение счетчика: ";
			std::cin >> __num;
		}
	}
	void task_2(std::string task)
	{
		if (task == "+")
		{
			__num += 1;
		}
		else if (task == "-")
		{
			__num -= 1;
		}
		else if (task == "=")
		{
			std::cout << __num << std::endl;
		}
		else if (task == "x" || task == "х")
		{
			std::cout << "До свидания\n";
		}
	}
};


int main()
{
	Counter count;
	std::string task;

	std::cout << "Вы хотите указать начальное значение счетчика ? Введите да или нет: ";
	std::cin >> task;
	count.task_1(task);
	do
	{
		std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
		std::cin >> task;
		count.task_2(task);
		if (task == "x" || task == "х")
		{
			return 0;
		}
	} while (true);
	
	return 0;
}