#include <iostream>
#include <string>
#include <cmath>

int real_string_hash(int p, int n, std::string s);

int main()
{
	std::string str;
	int p{0};
	int n{0};

	std::cout << "Введите p: ";
	std::cin >> p;

	std::cout << "Введите n: ";
	std::cin >> n;

	do {
		std::cout << "Введите строку: ";
		std::cin >> str;

		std::cout << "Хэш строки " << str << " = " << real_string_hash(p,n,str) << std::endl;

	} while (str != "exit");
	return 0;
}

int real_string_hash(int p, int n, std::string s)
{
	uint64_t hash{};

	for (int i = 0; i < s.length(); i++)
	{
		int c = static_cast<int>(s[i]) * pow(p, i);
		hash += c;
	}
	int ans = hash % n;

	return ans;
}


