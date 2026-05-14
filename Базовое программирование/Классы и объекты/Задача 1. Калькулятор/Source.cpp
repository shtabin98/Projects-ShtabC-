#include <iostream>


class Calculator
{
private:
	double __num1{};
	double __num2{};

public:

	void add() //метод должен возвращать результат сложения num1 и num2
	{
		std::cout << "num1 + num2 = " << __num1 + __num2 << std::endl;
	}

	void multiply() //метод должен возвращать результат перемножения num1 и num2
	{
		std::cout << "num1 * num2 = " << __num1 * __num2 << std::endl;
	}

	double subtract_1_2() //метод должен возвращать результат вычитания num2 из num1
	{
		double result = __num1 - __num2;
		std::cout << "num1 - num2 = " << result << std::endl;
		return result;
	}
	
	double subtract_2_1() //метод должен возвращать результат вычитания num1 из num2
	{
		double result = __num2 - __num1;
		std::cout << "num2 - num1 = " << result << std::endl;
		return result;
	}
		
	double divide_1_2() //метод должен возвращать результат деления num1 на num2
	{
		double result = __num1 / __num2;
		std::cout << "num1 / num2 = " << result << std::endl;
		return result;
	}
	
	double divide_2_1() //метод должен возвращать результат деления num2 на num1
	{
		double result = __num2 / __num1;
		std::cout << "num2 / num1 = " << result << std::endl;
		return result;
	}
	
	bool set_num1(double num1) //метод должен установить значение поля num1 равное значению аргумента num1 в случае, если значение аргумента не равно 0. Возвращает true, если установка произошла успешно, в обратном случае false
	{
		if (num1 != 0)
		{
			this->__num1 = num1;
			if (__num1 == num1)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}

	bool set_num2(double num2) //Метод должен установить значение поля num2 равное значению аргумента num2 в случае, если значение аргумента не равно 0. Возвращает true, если установка произошла успешно, в обратном случае false
	{
		if (num2 != 0)
		{
			this->__num2 = num2;
			if (__num2 == num2)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
};

int main()
{
	Calculator num;
	do
	{
		double num1{}, num2{};

		num1 = 0;
		std::cout << "Введите num1: ";
		std::cin >> num1;

		if (num.set_num1(num1) == false) //Проверяю, что num1 не равен нулю и устанавливаю значение поля через метод
		{
			do
			{
				std::cout << "Неверный ввод!\n" << "Введите num1: ";
				std::cin >> num1;
			} while (num1 == 0);
		}

		num2 = 0;
		std::cout << "Введите num2: ";
		std::cin >> num2;

		if (num.set_num2(num2) == false) //Проверяю, что num2 не равен нулю и устанавливаю значение поля через метод
		{
			do
			{
				std::cout << "Неверный ввод!\n" << "Введите num2: ";
				std::cin >> num2;
			} while (num2 == 0);
		}

		if (num.set_num1(num1) && num.set_num2(num2)) //Перепроверяю, что num1 и num2 не равен нулю и устанавливаю значения полей через метод
		{
			num.add();
			num.subtract_1_2();
			num.subtract_2_1();
			num.multiply();
			num.divide_1_2();
			num.divide_2_1();
		}
	} while (true);
	return 0;
}