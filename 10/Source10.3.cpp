#include <iostream>

int** create_two_dim_array(int size_str, int size_col);
void fill_two_dim_array(int** arr, int size_str, int size_col);
void print_two_dim_array(int** arr, int size_str, int size_col);
void delete_two_dim_array(int** arr, int size_str, int size_col);

int main()
{
	int size_str{ 0 }, size_col{ 0 };

	std::cout << "Введите количество строк: ";
	std::cin >> size_str; 

	std::cout << "Введите количество столбцов: ";
	std::cin >> size_col; 

	int** arr = create_two_dim_array(size_str, size_col);

	fill_two_dim_array(arr, size_str, size_col);

	std::cout << "Таблица умножения:" << std::endl;
	print_two_dim_array(arr, size_str, size_col);

	delete_two_dim_array(arr, size_str, size_col);
	
	return 0;
}

//Функции

/*Принимает на вход кол - во строк и столбцов, создает целочисленный динамический массив
и возвращает указатель на него.*/
int** create_two_dim_array(int size_str, int size_col)
{
	int** arr = new int*[size_str];
	for (int i = 0; i < size_str; ++i)
	{
		arr[i] = new int[size_col];
	}
	return arr;
}

/*Принимает на вход указатель на двумерный целочисленный массив, количество строк и столбцов в нём.
Заполняет полученный массив значениями из таблицы умножения.Не возвращает ничего.*/
void fill_two_dim_array(int** arr, int size_str, int size_col)
{
	for (int i = 0; i < size_str; ++i)
	{
		for (int j = 0; j < size_col; ++j)
		{
			arr[i][j] = (i+1) * (j+1);
		}
	}
}

/*Принимает на вход указатель на двумерный целочисленный массив, количество строк и столбцов в нём.
Выводит полученный массив на консоль. Не возвращает ничего.*/
void print_two_dim_array(int** arr, int size_str, int size_col)
{
	for (int i = 0; i < size_str; ++i)
	{
		for (int j = 0; j < size_col; ++j)
		{
			std::cout << arr[i][j] << "\t";
		}
		std::cout << "\n";
	}
}

/*Принимает на вход указатель на двумерный целочисленный массив, количество строк и столбцов в нём.
Очищает полученный массив. Не возвращает ничего.*/
void delete_two_dim_array(int** arr, int size_str, int size_col)
{
for (int i = 0; i < size_str; ++i)
	{
		delete[] arr[i];
	}
delete[] arr;
}