#include "main_1.cpp"
#include "main_2.cpp"
#include "main_3.cpp"
#include <cstdlib>

int main()
{

	std::cout << "Начало первой программы.\n";
	main_1(); 
	std::cout << std::endl << "Завершение первой программы." << std::endl << std::endl;
	
	std::cout << "Начало второй программы.\n";
	main_2();
	std::cout << std::endl << "Завершение второй программы." << std::endl << std::endl;

	std::cout << "Начало третьей программы.\n";
	main_3();
	std::cout << "Завершение третьей программы." << std::endl;
}