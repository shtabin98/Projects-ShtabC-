#include <iostream>

class figure
{
protected:
	std::string __figura{ "Фигура: " };
	int __storon{ 0 };
	int __a{0}, __b{0}, __c{0}, __d{0};
	int __A{0}, __B{0}, __C{0}, __D{0};

public:
	figure(std::string figura, int storon, int a, int b, int c, int d, int A, int B, int C, int D)
	{
		__figura = figura;
		__storon = storon;
		__a = a; __b = b; __c = c; __d = d; __A = A; __B = B; __C = C; __D = D;
	};
	figure() {};

	std::string get_figura() const { return __figura; };
	int get_storon() const { return __storon; };
	int get_a() const { return __a; }; int get_b() const { return __b; }; int get_c() const { return __c; }; int get_d() const { return __d; };
	int get_A() const { return __A; }; int get_B() const { return __B; }; int get_C() const { return __C; }; int get_D() const { return __D; };

	virtual bool virt_method()
	{
		if (get_storon() == 0) { return true; }
		else { return false; }
	};
	
	virtual std::string check()
	{
		std::string check = { "Правильная" };
		if (virt_method() == true) { check; }
		else (check = "Неправильная");
		return check;
	};

	void print_info()
	{
		std::cout << get_figura() << std::endl << check() << std::endl << "Количество сторон: " << get_storon() << std::endl << std::endl;
	}
};

class treu : public figure
{
public:
	treu() : figure(" ", 3, 10, 20, 30, 40, 50, 60, 70, 80)
	{
		__figura = "Треугольник";
	};

	bool virt_method()
	{
		int plus = __A + __B + __C;
		if (get_storon() == 3 && plus == 180) { return true; }
		else { return false; }
	};

	void print_info()
	{
		std::cout << get_figura() << std::endl << check() << std::endl << "Количество сторон: " << get_storon() << std::endl
			<< "Стороны: a=" << get_a() << " b=" << get_b()
			<< " c=" << get_c() << std::endl
			<< "Углы: A=" << get_A() << " B=" << get_B()
			<< " C=" << get_C() << std::endl << std::endl;
	}
};

class chetyre : public figure
{
public:
	chetyre() : figure(" ", 4, 10, 20, 30, 40, 50, 80, 130, 100)
	{
		__figura = "Четырехугольник";
	};

	bool virt_method()
	{
		int plus = __A + __B + __C + __D;
		if (get_storon() == 4 && plus == 360) { return true; }
		else { return false; }
	};

	void print_info()
	{
		std::cout << get_figura() << std::endl << check() << std::endl
			<< "Количество сторон: " << get_storon() << std::endl
			<< "Стороны: a=" << get_a() << " b=" << get_b()
			<< " c=" << get_c() << " d=" << get_d() << std::endl
			<< "Углы: A=" << get_A() << " B=" << get_B()
			<< " C=" << get_C() << " D=" << get_D() << std::endl << std::endl;

	}
};

class pryamougolnyi : public treu
{
public:
	pryamougolnyi() : treu()
	{
		__A = 30;
		__C = 90;
		__figura = "Прямоугольный треугольник: ";
	};

	bool virt_method()
	{
		int plus = __A + __B + __C;
		if (get_storon() == 3 && plus == 180 && this-> __C == 90)
		{ return true; }
		else { return false; }
	};
};

class ravnobedr : public treu
{
public:
	ravnobedr() : treu()
	{
		__c = __a; __C = __A; __B = 80;
		__figura = "Равнобедренный треугольник: ";
	};

	bool virt_method()
	{
		int plus = __A + __B + __C;
		if (get_storon() == 3 && plus == 180 && __c == __a && __C == __A)
		{ return true; }
		else { return false; }
	};
};


class ravnostor : public treu
{
public:
	ravnostor() : treu()
	{
		__b = __a; __c = __b;
		__A = 60;
		__B = __A; __C = __B;
		__figura = "Равноcторонний треугольник: ";
	}

	bool virt_method()
	{
		int plus = __A + __B + __C;
		if (get_storon() == 3 && plus == 180 && __b == __a && __c == __b
			&& __A == 60 && __B == __A && __C == __B)
		{return true;}
		else { return false; };
	};
};

class prymougol : public chetyre
{
public:
	prymougol() : chetyre()
	{
		__figura = "Прямоугольник: ";
		__a = __c; __d = __b;
		__A = 90;
		__B = __A; __C = __B; __D = __C;
	};

	bool virt_method()
	{
		int plus = __A + __B + __C + __D;
		if (get_storon() == 4 && plus == 360 && __a == __c && __d == __b
			&& __A == 90 && __B == __A && __C == __B && __D == __C)
		{return true;}
		else { return false; };
	}
};

class kvadrat : public chetyre
{
public:
	kvadrat() : chetyre()
	{
		__b = __a; __c = __b; __d = __c;
		__A = 90;
		__B = __A; __C = __B; __D = __C;
		__figura = "Квадрат: ";
	};
	
	bool virt_method()
	{
		int plus = __A + __B + __C + __D;
		if (get_storon() == 4 && plus == 360 &&
			__a == __b && __b == __c && __d == __c
			&& __A == 90 && __B == __A && __C == __B && __D == __C)
		{return true;}
		else { return false; };
	}
};

class parralelogram : public chetyre
{
public:
	parralelogram() : chetyre()
	{
		__c = __a; __d = __b;
		__A = 80; __B = 100;
		__C = __A; __D = __B;
		__figura = "Параллелограмм: ";
	};
	
	bool virt_method()
	{
		int plus = __A + __B + __C + __D;
		if (get_storon() == 4 && plus == 360 && __a == __c && __d == __b
			&& __C == __A && __B == __D)
		{return true;}
		else { return false; };
	}
};

class romb : public chetyre
{
public:
	romb() : chetyre()
	{
		__b = __a; __c = __b; __d = __c;
		__A = 100;
		__C = __A; __D = __B;
		__figura = "Ромб: ";
	};

	bool virt_method()
	{
		int plus = __A + __B + __C + __D;
		if (get_storon() == 4 && plus == 360 &&
			__a == __b && __c == __b && __c == __d
			&& __C == __A && __D == __B)
		{return true;}
		else { return false;}
	};
};

int main()
{
	figure fi;
	fi.print_info();

	treu tre;
	tre.print_info();

	pryamougolnyi tr;
	tr.print_info();

	ravnobedr trz;
	trz.print_info();

	ravnostor tro;
	tro.print_info();

	chetyre chet;
	chet.print_info();

	prymougol pr;
	pr.print_info();

	kvadrat kv;
	kv.print_info();

	parralelogram par;
	par.print_info();

	romb romb;
	romb.print_info();
	
	return 0;
}