#include <iostream>
#include <numeric>

#include <cassert>

class Fraction
{
private:
	int numerator_;
	int denominator_;
public:
	Fraction(int numerator, int denominator)
	{
		int gcd = std::gcd(numerator, denominator);
		numerator_ = numerator / gcd;
		denominator_ = denominator / gcd;
	}

	int nok(Fraction other)
	{
		int nok_ = std::lcm(denominator_, other.denominator_);
		int mn_1 = nok_ / denominator_;
		int mn_2 = nok_ / other.denominator_;
		numerator_ = numerator_ * mn_1;
		other.numerator_ = other.numerator_ * mn_2;
		return other.numerator_;
	}

	bool operator==(Fraction other) { nok(other); return numerator_ == other.numerator_; }
	bool operator!=(Fraction other) { nok(other);	return !(numerator_ == other.numerator_);}
	bool operator<(Fraction other)	{ nok(other); return numerator_ < other.numerator_;}
	bool operator>(Fraction other)	{ nok(other); return numerator_ > other.numerator_;}
	bool operator<=(Fraction other) { nok(other); return !(numerator_ > other.numerator_); }
	bool operator>=(Fraction other) { nok(other); return !(numerator_ < other.numerator_); }
};

int main()
{
	// Тест 2: Проверка неравенства    
	//Fraction f1(4, 3);
	//Fraction f2(6, 11);
	//assert(!(f1 == f2));
	//assert(f1 != f2);
	//assert(!(f1 < f2));
	//assert(f1 > f2);
	//assert(!(f1 <= f2));
	//assert(f1 >= f2);

	// Тест 3: Проверка равенства    
	Fraction f1(4, 3);
	Fraction f2(8, 6);
	assert(f1 == f2);
	assert(!(f1 != f2));
	assert(!(f1 < f2));
	assert(!(f1 > f2));
	assert(f1 <= f2);
	assert(f1 >= f2);


	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';
	return 0;
}