#include <iostream>
#include <string>

int function(std::string str, int forbidden_length);


int main()
{
	int forbidden_length{ 0 };
	std::string str{ "" };

	std::cout << "Введите запретную длину: ";
	std::cin >> forbidden_length;
	
	do {
		std::cout << "Введите слово: ";
		std::cin >> str;

		try
		{
			function(str, forbidden_length);
			std::cout << "Длина слова" << " \"" << str << "\" " << "равна " << function(str, forbidden_length) << "\n";
		}
		catch (std::exception)
		{
			std::cout << "Вы ввели слово запретной длины! До свидания";
		}
		catch (...)
		{
			std::cout << "Неизвестная ошибка";
		}
	} while (forbidden_length != str.length()/2);
	return 0;
}

int function(std::string str, int forbidden_length)
{
	int tmp = str.length() / 2;

	if (forbidden_length == tmp) throw std::exception();
	return tmp;
}