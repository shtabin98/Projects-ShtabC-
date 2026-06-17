#include "extended_array.h"

int main()
{
	ExtArray ex({ 2,3,4,6,8,5,4,3,1,5,3 });
	std::cout << ex.mean() << std::endl;
	std::cout << ex.mean(4, 6) << std::endl;
	std::cout << ex.median() << std::endl;
	//ex.mode();
}
