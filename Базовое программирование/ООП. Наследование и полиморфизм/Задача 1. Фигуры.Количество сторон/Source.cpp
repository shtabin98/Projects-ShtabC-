#include <iostream>

class figure
{
protected:
	int __storon{ 0 };
public:
	figure(int storon)
	{
		__storon = storon;
	}
	figure() {};

	void print()
	{
		std::cout << "Фигура: " << __storon << std::endl;
	}

};

class treu : public figure
{
protected:
	int __storon{ 3 };
public:
	void print()
	{
		std::cout << "Треугольник: " << __storon << std::endl;
	}
};

class chetyre : public figure
{
protected:
	int __storon{ 4 };
public:
	void print()
	{
		std::cout << "Четырехугольник: " << __storon << std::endl;
	}
};

int main()
{
	std::cout << "Количество сторон:" << std::endl;
	figure figa;
	figa.print();
	treu tri;
	tri.print();
	chetyre chet;
	chet.print();

	return 0;
}