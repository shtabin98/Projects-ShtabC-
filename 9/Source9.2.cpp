#include <iostream>

void swap(int* pa, int* pb);

int main(int argc, char** argv)
{
	int a = 5, b = 8;
	int* pa{ &a };
	int* pb{ &b };

	std::cout << "a = " << a << ", b = " << b << std::endl;

	swap(pa, pb);

	std::cout << "a = " << a << ", b = " << b << std::endl;

	return 0;
}


void swap(int* pa, int* pb)
{
	int c = *pb;
	*pb = *pa;
	*pa = c;
}