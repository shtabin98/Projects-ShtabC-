#include <iostream>
#include <string>
#include <fstream>

int** create_array(int size_str, int size_col);

int main()
{
	std::ifstream fin{ "in.txt" };

	if (fin.is_open())
	{
		std::string s{};

		//Записываю кол-во строк
		fin >> s;
		int row = std::stoi(s);

		//Записываю кол-во столбцов
		fin >> s;
		int col = std::stoi(s);
		
		//Создаю двухмерный динамический массив
		int** ar = create_array(row, col);
		
		//Заполняю его элементами из открытого файла
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				fin >> s;
				ar[i][j] = std::stoi(s);
			}
		}

		//Вывожу на консоль перевернутый массив
		for (int i = 0; i < row; ++i)
		{
			for (int j = col - 1; j >= 0; --j)
			{
				std::cout << ar[i][j] << " ";
			}
			std::cout << "\n";
		}

		//Очищаю память
		delete[] ar;
	}
	fin.close();
	return 0;
}

//Создаю двухмерный динамический массив
int** create_array(int row, int col)
{
	int** ar = new int* [row];
	for (int i = 0; i < row; ++i)
	{
		ar[i] = new int[col];
	}
	return ar;
}
