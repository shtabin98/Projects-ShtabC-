#pragma once

#include <string>
#include <iostream>

class figure
{
protected:
	std::string _figura;
	int _storon;
	int _a, _b, _c, _d;
	int _A, _B, _C, _D;
public:
	figure(std::string figura, int storon,
		int a, int b, int c, int d,
		int A, int B, int C, int D);
	figure();

	std::string get_figura() const;
	int get_storon() const;
	int get_a()const; int get_b()const; int get_c()const; int get_d()const;
	int get_A()const; int get_B()const; int get_C()const; int get_D()const;
	virtual void print_info() const;
};