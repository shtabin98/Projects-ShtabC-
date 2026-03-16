#include <iostream>

int main()
{
	std::string slovo;

	do
	{
		std::cout << "Угадайте слово: ";
		std::cin >> slovo;

		if (slovo == "шпон")
		{
			std::cout << "Правильно! Вы победили! Угаданное слово - шпон";
		}
		else
		{
			std::cout << "Неправильно" << std:: endl;
		}

	} while (slovo != "шпон");

	return 0;
}