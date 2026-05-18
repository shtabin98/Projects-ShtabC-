#include <iostream>


class Calculator
{
private:
	double __num1{};
	double __num2{};

public:

	double add() //метод должен возвращать результат сложения num1 и num2
	{
		double result = __num1 + __num2;
		return result;;
	}

	double multiply() //метод должен возвращать результат перемножения num1 и num2
	{
		double result = __num1 * __num2;
		return result;
	}

	double subtract_1_2() //метод должен возвращать результат вычитания num2 из num1
	{
		double result = __num1 - __num2;
		return result;
	}
	
	double subtract_2_1() //метод должен возвращать результат вычитания num1 из num2
	{
		double result = __num2 - __num1;
		return result;
	}
		
	double divide_1_2() //метод должен возвращать результат деления num1 на num2
	{
		double result = __num1 / __num2;
		return result;
	}
	
	double divide_2_1() //метод должен возвращать результат деления num2 на num1
	{
		double result = __num2 / __num1;
		return result;
	}
	
	bool set_num1(double num1) //метод должен установить значение поля num1 равное значению аргумента num1 в случае, если значение аргумента не равно 0. Возвращает true, если установка произошла успешно, в обратном случае false
	{
		if (num1 == 0)
		{
			return false;
		}
		else
		{
			this->__num1 = num1;
			return true;
		}
	}

	bool set_num2(double num2) //Метод должен установить значение поля num2 равное значению аргумента num2 в случае, если значение аргумента не равно 0. Возвращает true, если установка произошла успешно, в обратном случае false
	{
		if (num2 == 0)
		{
			return false;
		}
		else
		{
			this->__num2 = num2;
			return true;
		}
	}
};

int main()
{
	Calculator num;
	do
	{
		double num1{0}, num2{0};
		
		std::cout << "Введите num1: ";
		std::cin >> num1;

		bool val1 = num.set_num1(num1); //Проверяю, что num1 не равен нулю и устанавливаю значение поля через метод

		if (val1 == false)
		{
			do
			{
				std::cout << "Неверный ввод!\n" << "Введите num1: ";
				std::cin >> num1;
				val1;
			} while (num.set_num1(num1) == false);
		}

		std::cout << "Введите num2: ";
		std::cin >> num2;

		bool val2 = num.set_num2(num2); //Проверяю, что num2 не равен нулю и устанавливаю значение поля через метод

		if (val2 == false)
		{
			do
			{
				std::cout << "Неверный ввод!\n" << "Введите num2: ";
				std::cin >> num2;
			} while (num.set_num2(num2) == false);
		}

		if (num.set_num1(num1) && num.set_num2(num2)) //Перепроверяю, что num1 и num2 не равен нулю
		{
			std::cout << "num1 + num2 = " << num.add() << std::endl;
			std::cout << "num1 - num2 = " << num.subtract_1_2() << std::endl;
			std::cout << "num2 - num1 = " << num.subtract_2_1() << std::endl;
			std::cout << "num1 * num2 = " << num.multiply() << std::endl;
			std::cout << "num1 / num2 = " << num.divide_1_2() << std::endl;
			std::cout << "num2 / num1 = " << num.divide_2_1() << std::endl;
		}
	} while (true);
	return 0;
}