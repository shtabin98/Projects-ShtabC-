#include <iostream>

void print(int* mas, int size);

int main()
{
	int mas_1[]{ 1,2,3,4,5,6,7,8,9 };
	int mas_2[]{ 6,5,4,8 };
	int mas_3[]{ 1,4,3,7,5 };

	int size_1 = sizeof(mas_1) / sizeof(mas_1)[0];
	int size_2 = sizeof(mas_2) / sizeof(mas_1)[0];
	int size_3 = sizeof(mas_3) / sizeof(mas_1)[0];

	print(mas_1, size_1);
	print(mas_2, size_2);
	print(mas_3, size_3);

	return 0;
}

void print(int* mas, int size)
{
	for (int i = 0; i < size; ++i)
	{
		std::cout << mas[i] << " ";
	}
	std::cout << "\n";

}
