#include <iostream>
#include <string>

int simple_string_hash(std::string s);

int main()
{

	std::string str;
	do {
		std::cout << "Введите строку: ";

		std::cin >> str;

		std::cout << "Наивный хэш строки " << str << " = " << simple_string_hash(str) << std::endl;
	} while (str != "exit");
	return 0;
}

int simple_string_hash(std::string s)
{
	int hash{};

	for (int i = 0; i < s.length(); i++)
	{
		int c = static_cast<int>(s[i]);
		hash += c;
	}
	return hash;
}


