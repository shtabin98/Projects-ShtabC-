#include <iostream>

class Counter
{
	int __num{ 1 };
public:

	Counter(int num) 
	{
		__num = num;
	};
	Counter() {};

	void plus()
	{
		this->__num += 1;
	}

	void minus()
	{
		this->__num -= 1;
	}

	int ravno(int num)
	{
		num = this->__num;
		return __num;
	}
};


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
			count.plus();
		}
		else if (task == "-")
		{
			count.minus();
		}
		else if (task == "=")
		{
			std::cout << count.ravno(num) << std::endl;
		}
	} while (true);
	
	return 0;
}