#include "extended_array.h"

int main()
{
	ExtArray ex({2,4,6,4,6,4,6,8,6,7,8,6});
	std::cout << ex.mean() << std::endl;
	std::cout << ex.median();
	return 0;
}