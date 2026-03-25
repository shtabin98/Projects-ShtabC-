#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <windows.h>

bool** create_array(int row, int col);
void print_ar(bool** ar, int row, int col, int& counter_live);
void pereprint_ar(bool** ar, bool** ar2, int row, int col);
void brotherhood(bool** ar, int i, int j, int row, int col, int& c);

int main()
{
	std::ifstream fin{ "in.txt" };
	int counter_live{ 0 };//Счетчик живых клеток

	if (fin.is_open())
	{
		std::string s{};

		fin >> s;
		int row = std::stoi(s);//Записываю кол-во строк

		fin >> s;
		int col = std::stoi(s);//Записываю кол-во столбцов

		bool** ar = create_array(row, col);//Создаю двухмерный динамический массив

		bool** ar2 = create_array(row, col);//И второй, для времменого перезаписывания

		//Проверка на заполненность.
		if (!(fin >> s))
		{
			pereprint_ar(ar, ar2, row, col);
		}

		//Заполняю первый элементами из открытого файла
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				if (fin.eof())
				{
					if (ar[i][j] != true)
					{
						ar[i][j] = false;
					}
				}
				else
				{
					fin >> s;
					int x = std::stoi(s);
					fin >> s;
					int y = std::stoi(s);
					ar[x][y] = true;
					if (ar[i][j] != true)
					{
						ar[i][j] = false;
					}
				}
			}
		}
		fin.close();//Закрываю файл после использования

		print_ar(ar, row, col, counter_live);//Вывожу на терминал первое поколение

		for (int y = 1; y < 10000 ; y++)//Cчетчик итераций
		{
			int counter_live{ 0 };//Счетчик живых клеток
			int kon{ 0 };//Счетчик для остановы цикла по стагнации

			//Перезаписываю массив
			pereprint_ar(ar2, ar, row, col);

			for (int i = 0; i < row; ++i)
			{
				for (int j = 0; j < col; ++j)
				{
					switch (ar[i][j])
					{
					//Проверяю неживые клетки на наличие соседей
					case false:
					{
						int c_f = 0;
						brotherhood(ar, i, j, row, col, c_f);
						if (c_f == 3)
						{
							ar2[i][j] = true;
						}
						else (ar2[i][j] = false);
					};
						break;
					//Проверяю живые клетки на наличие соседей
					case true:
					{
						int c_t = 0;
						brotherhood(ar, i, j, row, col, c_t);
						if (c_t == 2 || c_t == 3)
						{
							ar2[i][j] = true;
						}
						else (ar2[i][j] = false);
					};
						break;
					}
				}
			}
				
			std::system("cls");//Очистка экрана терминала перед следующей итерацией
			print_ar(ar2, row, col, counter_live);

			//Проверка на колличество живых клеток.
			if (counter_live == 0)
			{
				std::cout << "Живых клеток больше нет, игра окончена:(" << std::endl;
				break;
			}

			//Цикл для проверки на стагнацию
			for (int i = 0; i < row; ++i)
			{
				for (int j = 0; j < col; ++j)
				{
					if (ar[i][j] == ar2[i][j])
					{
						++kon;
					}
				}
			}

			if (kon == (row * col))
			{
				std::cout << "Цивилизация не развивается. Игра окончена." << std::endl;
				break;
			}

			//Перезаписываю массив
			pereprint_ar(ar, ar2, row, col);
		}
		delete[] ar,ar2;//Очищаю память
	}
	return 0;
}

//Функция создания динамических массивов
bool** create_array(int row, int col)
{
	bool** ar = new bool* [row] {};
	for (int i = 0; i < row; ++i)
	{
		ar[i] = new bool[col] {};
	}
	return ar;
}

//Функция вывода на терминал
 void print_ar(bool** ar, int row, int col, int &counter_live)
{
	static int counter = 1;
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			if (ar[i][j] == true)
			{
				std::cout << "*" << " ";
				++counter_live;
			}
			else (std::cout << "-" << " ");
		}
		std::cout << "\n";
	}
	//Вывод на терминал колличества итераций и колличество оставшихся в живых клеток.
	std::cout << "Поколение: " << counter << ". Колличество живых клеток: " << counter_live << "." << std::endl;
	counter++;//Счетчик для колличества итераций
	Sleep(1000);//Задержка времени вывода одна секунд
}

 //Функция перезаписывания массивов на терминал
 void pereprint_ar(bool** ar, bool** ar2, int row, int col)
 {
	 for (int i = 0; i < row; ++i)
	 {
		 for (int j = 0; j < col; ++j)
		 {
			 ar[i][j] = ar2[i][j];
		 }
	 }
 }

 //Функция для проверки соседей клетки
 void brotherhood(bool** ar, int i, int j, int row, int col, int& c)
 {
	 for (int l = 0; l < 8; ++l)
	 {
		 int ir[8]{ -1, 0, +1, -1, +1, -1, 0, +1 };
		 int jc[8]{ -1, -1, -1, 0, 0, +1, +1, +1 };
		 int ni = i + ir[l];
		 int nj = j + jc[l];
		 if (ni >= 0 && ni < row && nj >= 0 && nj < col && ar[ni][nj] == true)
		 {
			 ++c;
		 }
	 }
 }