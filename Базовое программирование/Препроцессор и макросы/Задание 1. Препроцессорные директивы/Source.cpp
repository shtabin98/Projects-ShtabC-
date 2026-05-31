#include <iostream>

#define MODE 1

#ifndef MODE
	#error "Необходимо определить MODE"
#endif

int add(int i, int j);

int main()
{
#if MODE == 0
	std::cout << "Работаю в режиме тренировки";
#elif MODE == 1
	int i, j;
	std::cout << "Работаю в боевом режиме\n";
	std::cout << "Введите число 1: "; std::cin >> i;
	std::cout << "Введите число 2: "; std::cin >> j;
	std::cout << "Результат сложения: " << add(i, j);
#else
	std::cout << "Неизвестный режим.Завершение работы";
#endif
		return 0;
}

int add(int i, int j)
{
	return i + j;
}