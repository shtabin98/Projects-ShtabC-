#include <iostream>
#include "main_3.h"

int main()
{
	try
	{
		figure figure;
		figure.virt_method();
		figure.print_info();
	}
	catch (const expection& e ) {std::cout << e.get_expect() << std::endl;}

	catch (...) { std::cout << "Неизвестная ошибка" << std::endl; }

	try
	{
		triangle triangle;
		triangle.virt_method();
		triangle.print_info();
	}
	catch (const expection& e) { std::cout << e.get_expect() << std::endl; }

	catch (...) { std::cout << "Неизвестная ошибка" << std::endl; }

	try
	{
		rectangular rectangular;
		rectangular.virt_method();
		rectangular.print_info();
	}
	catch (const expection& e) { std::cout << e.get_expect() << std::endl; }

	catch (...){std::cout << "Неизвестная ошибка" << std::endl;}

	try
	{
		isosceles isosceles;
		isosceles.virt_method();
		isosceles.print_info();
	}
	catch (const expection& e) { std::cout << e.get_expect() << std::endl; }

	catch (...) { std::cout << "Неизвестная ошибка" << std::endl; }

	try
	{
		equilateral equilateral;
		equilateral.virt_method();
		equilateral.print_info();
	}
	catch (const expection& e) { std::cout << e.get_expect() << std::endl; }

	catch (...) { std::cout << "Неизвестная ошибка" << std::endl; }

	try
	{
		quadrilateral quadrilateral;
		quadrilateral.virt_method();
		quadrilateral.print_info();
	}
	catch (const expection& e) { std::cout << e.get_expect() << std::endl; }

	catch (...) { std::cout << "Неизвестная ошибка" << std::endl; }

	try
	{
		rectangle rectangle;
		rectangle.virt_method();
		rectangle.print_info();
	}
	catch (const expection& e) { std::cout << e.get_expect() << std::endl; }

	catch (...) { std::cout << "Неизвестная ошибка" << std::endl; }

	try
	{
		square square;
		square.virt_method();
		square.print_info();
	}
	catch (const expection& e) { std::cout << e.get_expect() << std::endl; }

	catch (...) { std::cout << "Неизвестная ошибка" << std::endl; }

	try
	{
		parallelogram parallelogram;
		parallelogram.virt_method();
		parallelogram.print_info();
	}
	catch (const expection& e) { std::cout << e.get_expect() << std::endl; }

	catch (...) { std::cout << "Неизвестная ошибка" << std::endl; }

	try
	{
		romb romb;
		romb.virt_method();
		romb.print_info();
	}
	catch (const expection& e) { std::cout << e.get_expect() << std::endl; }

	catch (...) { std::cout << "Неизвестная ошибка" << std::endl; }

	return 0;
};
