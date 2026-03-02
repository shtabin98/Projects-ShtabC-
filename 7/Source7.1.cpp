#include <iostream>

int main(int argc, char** argv)
{
	int number_1{};
	short int number_2{};
	long int number_3{};
	long long int number_4{};
	float number_5{};
	double number_6{};
	long double number_7{};
	bool number_8{};

	std::cout << "int: " << &number_1 << " " << sizeof(number_1) << std::endl;
	std::cout << "short: " << &number_2 << " " << sizeof(number_2) << std::endl;
	std::cout << "long: " << &number_3 << " " << sizeof(number_3) << std::endl;
	std::cout << "long long: " << &number_4 << " " << sizeof(number_4) << std::endl;
	std::cout << "float: " << &number_5 << " " << sizeof(number_5) << std::endl;
	std::cout << "double: " << &number_6 << " " << sizeof(number_6) << std::endl;
	std::cout << "long double: " << &number_7 << " " << sizeof(number_7) << std::endl;
	std::cout << "bool: " << &number_8 << " " << sizeof(number_8) << std::endl;


	return 0;
}