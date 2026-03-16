#include <iostream>

int main()
{
	std::string Name, Family;

	std::cout << "Введите имя: ";
	std::cin >> Name;

	std::cout << "Введите фамилию: ";
	std::cin >> Family;

	std::cout << "Здравствуйте, " << Name + " " << Family + "!";

	return 0;
}