#include <iostream>
#include <string>
#include <fstream>

int main()
{
	std::ifstream fin{ "in.txt" };

	if (fin.is_open())
	{
		std::string s{};
		fin >> s;
		int v = std::stoi(s);
		auto ar = std::make_unique<int[]>(v);

		for (int i = 0; fin >> s; ++i)
		{
			ar[i] = std::stoi(s);
		}

		for (int i = 0; i < v / 2; ++i)
		{
			int vremes = ar[i];
			ar[i] = ar[(v - 1) - i];
			ar[(v - 1) - i] = vremes;
		}

		for (int i = 0; i < v; ++i)
		{
			std::cout << ar[i] << " ";
		}

	}

	fin.close();

	return 0;
}
