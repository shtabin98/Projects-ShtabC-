#include <iostream>
#include "main_3.h"

int main()
{
	try
	{
		figure figure;
		figure.print_info();
	}
	catch (const expection& e ) {std::cout << e.get_expect() << std::endl;}

	catch (...) { std::cout << "Неизвестная ошибка" << std::endl; }

	try
	{
		triangle triangle;
		triangle.print_info();
	}
	catch (const expection& e) { std::cout << e.get_expect() << std::endl; }

	catch (...) { std::cout << "Неизвестная ошибка" << std::endl; }

	try
	{
		rectangular rectangular;
		rectangular.print_info();
	}
	catch (const expection& e) { std::cout << e.get_expect() << std::endl; }

	catch (...){std::cout << "Неизвестная ошибка" << std::endl;}

	try
	{
		isosceles isosceles;
		isosceles.print_info();
	}
	catch (const expection& e) { std::cout << e.get_expect() << std::endl; }

	catch (...) { std::cout << "Неизвестная ошибка" << std::endl; }

	try
	{
		equilateral equilateral;
		equilateral.print_info();
	}
	catch (const expection& e) { std::cout << e.get_expect() << std::endl; }

	catch (...) { std::cout << "Неизвестная ошибка" << std::endl; }

	try
	{
		quadrilateral quadrilateral;
		quadrilateral.print_info();
	}
	catch (const expection& e) { std::cout << e.get_expect() << std::endl; }

	catch (...) { std::cout << "Неизвестная ошибка" << std::endl; }

	try
	{
		rectangle rectangle;
		rectangle.print_info();
	}
	catch (const expection& e) { std::cout << e.get_expect() << std::endl; }

	catch (...) { std::cout << "Неизвестная ошибка" << std::endl; }

	try
	{
		square square;
		square.print_info();
	}
	catch (const expection& e) { std::cout << e.get_expect() << std::endl; }

	catch (...) { std::cout << "Неизвестная ошибка" << std::endl; }

	try
	{
		parallelogram parallelogram;
		parallelogram.print_info();
	}
	catch (const expection& e) { std::cout << e.get_expect() << std::endl; }

	catch (...) { std::cout << "Неизвестная ошибка" << std::endl; }

	try
	{
		romb romb;
		romb.print_info();
	}
	catch (const expection& e) { std::cout << e.get_expect() << std::endl; }

	catch (...) { std::cout << "Неизвестная ошибка" << std::endl; }

	return 0;
};
