#include <iostream>

void print(int* mas, int size);
void reverse(int* mas, int size);

int main()
{
	int mas[]{ 1,2,3,4,5,6,7,8,9 };
	int size = sizeof(mas) / sizeof(mas)[0];
	
	std::cout << "До функции reverse: ";
	print(mas, size);

	reverse(mas, size);

	std::cout << "После функции reverse: ";
	print(mas, size);

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

void reverse(int* mas, int size)
{
	for (int i = 0; i < size/2; ++i)
	{
		int vremes = mas[i];
		mas[i] = mas[(size - 1) - i];
		mas[(size - 1) - i] = vremes;
	}

}
