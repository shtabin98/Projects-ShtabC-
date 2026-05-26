#include <iostream>

class figure
{
protected:
	std::string __figura{ "Фигура: " };
	int __storon{ 0 };
	int __a{ }, __b{ }, __c{ }, __d{ };
	int __A{ }, __B{ }, __C{ }, __D{ };
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

	std::string vshivost() 
	{
		if (get_storon() == 0) { return "Правильная"; }
		else { return "Неправильная"; }
	};
};

class treu : public figure
{
public:
	treu() : figure(" ", 3, 10, 20, 30, 40, 50, 60, 70, 80)
	{
		__figura = "Треугольник";
	};

	std::string vshivost()
	{
		int plus = __A + __B + __C;
		if (get_storon() == 3 && plus == 180 ) { return "Правильная"; }
		else { return "Неправильная"; }
	};
};

class chetyre : public figure
{
public:
	chetyre() : figure(" ", 4, 10, 20, 30, 40, 50, 60, 70, 80)
	{
		__figura = "Четырехугольник";
	};
	std::string vshivost()
	{
		int plus = __A + __B + __C + __D;
		if (get_storon() == 4 && plus == 360) { return "Правильная"; }
		else { return "Неправильная"; }
	};
};

class pryamougolnyi : public treu
{
public:
	pryamougolnyi() : treu()
	{
		__C = 90;
		__figura = "Прямоугольный треугольник: ";
	};
	std::string vshivost()
	{
		int plus = __A + __B + __C;
		if (get_storon() == 3 && plus == 180 && this-> __C == 90) { return "Правильная"; }
		else { return "Неправильная"; }
	};
};

class ravnobedr : public treu
{
public:
	ravnobedr() : treu()
	{
		__c = __a; __C = __A;
		__figura = "Равнобедренный треугольник: ";
	};
	std::string vshivost()
	{
		int plus = __A + __B + __C;
		if (get_storon() == 3 && plus == 180 && __c == __a && __C == __A)
		{ return "Правильная"; }
		else { return "Неправильная"; }
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
	std::string vshivost()
	{
		int plus = __A + __B + __C;
		if (get_storon() == 3 && plus == 180 && __b == __a && __c == __b
			&& __A == 60 && __B ==__A && __C == __B)
		{
				return "Правильная";
		}
		else { return "Неправильная"; }
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
	std::string vshivost()
	{
		int plus = __A + __B + __C + __D;
		if (get_storon() == 4 && plus == 360 && __a == __c && __d == __b
			&& __A == 90 && __B == __A && __C == __B && __D == __C)
		{
			return "Правильная";
		}
		else { return "Неправильная"; }
	};
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
	std::string vshivost()
	{
		int plus = __A + __B + __C + __D;
		if (get_storon() == 4 && plus == 360 &&
			__a == __b && __b == __c && __d == __c
			&& __A == 90 && __B == __A && __C == __B && __D == __C)
		{
			return "Правильная";
		}
		else { return "Неправильная"; }
	};
};

class parralelogram : public chetyre
{
public:
	parralelogram() : chetyre()
	{
		__c = __a; __d = __b;
		__C = __A; __D = __B;
		__figura = "Параллелограмм: ";
	};
	std::string vshivost()
	{
		int plus = __A + __B + __C + __D;
		if (get_storon() == 4 && plus == 360 && __a == __c && __d == __b
			&& __C == __A && __B == __D)
		{
			return "Правильная";
		}
		else { return "Неправильная"; }
	};
};

class romb : public chetyre
{
public:
	romb() : chetyre()
	{
		__b = __a; __c = __b; __d = __c;
		__C = __A; __D = __B;
		__figura = "Ромб: ";
	};
	std::string vshivost()
	{
		int plus = __A + __B + __C + __D;
		if (get_storon() == 4 && plus == 360 &&
			__a == __b && __c == __b && __c == __d
			&& __C == __A && __D == __B)
		{
			return "Правильная";
		}
		else { return "Неправильная"; }
	};
};

void print_info(figure& figa)
{
	figure f;
	figure* gu{ &f };
	switch (figa.get_storon())
	{
	case 0:
		std::cout << figa.get_figura() << std::endl << gu->vshivost() << "\nКоличество сторон: " << figa.get_storon() << std::endl << std::endl;
		break;
	case 3:
		std::cout << figa.get_figura() << std::endl << gu->vshivost() << "\nКоличество сторон: " << figa.get_storon() << std::endl << "Стороны: a=" << figa.get_a() << " b=" << figa.get_b()
			<< " c=" << figa.get_c() << std::endl
			<< "Углы: A=" << figa.get_A() << " B=" << figa.get_B()
			<< " C=" << figa.get_C() << std::endl << std::endl;
		break;
	case 4:
		std::cout << figa.get_figura() << std::endl << gu->vshivost() << "\nКоличество сторон: " << figa.get_storon() << std::endl << "Стороны: a=" << figa.get_a() << " b=" << figa.get_b()
			<< " c=" << figa.get_c() << " d=" << figa.get_d() << std::endl
			<< "Углы: A=" << figa.get_A() << " B=" << figa.get_B()
			<< " C=" << figa.get_C() << " D=" << figa.get_D() << std::endl << std::endl;
		break;
	}
}

int main()
{
	figure fi;
	print_info(fi);

	treu tre;
	print_info(tre);

	pryamougolnyi tr;
	print_info(tr);

	ravnobedr trz;
	print_info(trz);

	ravnostor tro;
	print_info(tro);

	chetyre chet;
	print_info(chet);

	prymougol pr;
	print_info(pr);

	kvadrat kv;
	print_info(kv);

	parralelogram par;
	print_info(par);

	romb romb;
	print_info(romb);
	
	return 0;
}
