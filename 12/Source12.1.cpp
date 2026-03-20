#include <iostream>
#include <string>
#include <fstream>

int main()
{
	std::ifstream fin("in.txt");

	if (fin.is_open())
	{
		std::string s{};
		
		while (fin >> s)
		{
			std::cout << s << std::endl;
		}
	}
	fin.close();

	return 0;
}

