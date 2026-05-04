#include <iostream>

enum class months
{
	January = 1,
	February,
	March,
	April,
	May,
	June,
	July,
	August,
	September,
	October,
	November,
	December
};

int main() 
{

	int month{};
	do 
	{
		std::cout << "Введите номер месяца" << std::endl;
		std::cin >> month;
		switch (month)
		{
		case 0:
			std::cout << "До свидания\n";
			break;
		case 1:
			if (static_cast<int>(months::January) == 1)
			{
				std::cout << "Январь\n";
			};
			break;
		case 2:
			if (static_cast<int>(months::February) == 2)
			{
				std::cout << "Февраль\n";
			};
			break;
		case 3:
			if (static_cast<int>(months::March) == 3)
			{
				std::cout << "Март\n";
			};
			break;
		case 4:
			if (static_cast<int>(months::April) == 4)
			{
				std::cout << "Апрель\n";
			}
			break;
		case 5:
			if (static_cast<int>(months::May) == 5)
			{
				std::cout << "Май\n";
			}
			break;
		case 6:
			if (static_cast<int>(months::June) == 6)
			{
				std::cout << "Июнь\n";
			}
			break;
		case 7:
			if (static_cast<int>(months::July) == 7)
			{
				std::cout << "Июль\n";
			}
			break;
		case 8:
			if (static_cast<int>(months::August) == 8)
			{
				std::cout << "Август\n";
			}
			break;
		case 9:
			if (static_cast<int>(months::September) == 9)
			{
				std::cout << "Сентябрь\n";
			}
			break;
		case 10:
			if (static_cast<int>(months::October) == 10)
			{
				std::cout << "Октябрь\n";
			}
			break;
		case 11:
			if (static_cast<int>(months::November) == 11)
			{
				std::cout << "Ноябрь\n";
			}
			break;
		case 12:
			if (static_cast<int>(months::December) == 12)
			{
				std::cout << "Декабрь\n";
			}
			break;
		default:
			std::cout << "Неправильный номер!\n";
			break;
		}
	} while (month != 0);

	return 0;
}