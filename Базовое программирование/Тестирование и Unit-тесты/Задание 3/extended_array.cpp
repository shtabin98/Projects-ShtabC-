#include "extended_array.h"

int main()
{
	ExtArray ex({ 1,2,0,0,0,3,1,1 });
	std::cout << ex.mean() << std::endl;
	std::cout << ex.mean(4, 6) << std::endl;
	std::cout << ex.median() << std::endl;
	std::cout << ex.checkSum();
}