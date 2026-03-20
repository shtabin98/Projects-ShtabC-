#include <iostream>
#include <string>
#include <fstream>

int main()
{
	int f{};

	std::cout << "Введите размер массива: ";
	std::cin >> f;
	auto ar = std::make_unique<int[]>(f);

	for (int i = 0; i < f; ++i)
	{
		std::cout << "arr[" << i << "] = ";
		std::cin >> ar[i];
	}

	std::ofstream fout{ "out.txt" };

	if (fout.is_open())
	{
		std::string s{};
		fout << f << std::endl;

		for (int i = 0; i < f / 2; ++i)
		{
			int vremes = ar[i];
			ar[i] = ar[(f - 1) - i];
			ar[(f - 1) - i] = vremes;
		}

		for (int i = 0; i < f; ++i)
		{
			fout << ar[i] << " ";
		}
	}

	fout.close();

	return 0;
}
