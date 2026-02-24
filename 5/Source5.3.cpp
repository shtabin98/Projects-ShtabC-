#include <iostream>
using namespace std;

int main()
{
	const int rows = 3, columns = 6;
	int a{};
	int mas[rows][columns] =
	{
		{3, 2, 55, 5, 9, 1},
		{4, 3, 7, 96, 10, 2},
		{2, 1, 5, 4, 8, 0}
	};

	cout << "Массив:" << endl;

	//Выводим в терминал изначальный массив

	for (int row{}; row < rows; ++row)
	{
		for (int column{}; column < columns; ++column)
		{
			cout << mas[row][column] << "\t";
		}
		cout << endl;
	}

	//Сортируем от меньшего к большему

	for (a; a <= (rows * columns); ++a)
	{
		// Проходка по строкам
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < columns - 1; ++j)
			{
				if (mas[i][j] > mas[i][j + 1])
				{
					int vremes{ mas[i][j] };
					mas[i][j] = mas[i][j + 1];
					mas[i][j + 1] = vremes;
				}
			}
		}

		// Проходка по столбцам
		for (int x = 0; x < columns; ++x)
		{
			for (int y = 0; y < rows - 1; ++y)
			{
				if (mas[x][y] > mas[x][y + 1])
				{
					int vremes{ mas[x][y] };
					mas[x][y] = mas[x][y + 1];
					mas[x][y + 1] = vremes;
				}
			}
		}
	}

	cout << "\n";

	cout << "Отсортированный массив: \n";

	for (int row{}; row < rows; ++row)
	{
		for (int column{}; column < columns; ++column)
		{
			cout << mas[row][column] << "\t";
		}
		cout << endl;
	}

	cout << "\n";

	//Выводим индекс минимального элемента
	
	int min_result = mas[0][0] < mas[1][0] ? mas[0][0] < mas[2][0] ? mas[0][0] : mas[2][0] : mas[1][0] < mas[2][0] ? mas[1][0] : mas[2][0];

	if (min_result == mas[0][0])
	{
		cout << "Индекс минимального элемента: 0 0 " << endl;
	}
	else if (min_result == mas[1][0])
	{
		cout << "Индекс минимального элемента: 1 0 " << endl;
	}
	else
	{
		cout << "Индекс минимального элемента: 2 0 " << endl;
	}

	//Выводим индекс максимального элемента
	
	int max_result = mas[0][5] > mas[1][5] ? mas[0][5] > mas[2][5] ? mas[0][5] : mas[2][5] : mas[1][5] > mas[2][5] ? mas[1][5] : mas[2][5];

	if (max_result == mas[0][5])
	{
		cout << "Индекс минимального элемента: 0 5 " << endl;
	}
	else if (max_result == mas[1][5])
	{
		cout << "Индекс минимального элемента: 1 5 " << endl;
	}
	else
	{
		cout << "Индекс минимального элемента: 2 5 " << endl;
	}

	return 0;
}