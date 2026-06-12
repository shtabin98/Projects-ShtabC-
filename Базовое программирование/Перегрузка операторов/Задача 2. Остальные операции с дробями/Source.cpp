#include <iostream>
#include <string>
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

	std::string dump()
	{
		
		return std::to_string(numerator_) + "/" + std::to_string(denominator_);
	}

	Fraction operator+(Fraction other)
	{ 
		int new_denominator = std::lcm(denominator_, other.denominator_);
		int new_numerator = numerator_ * (new_denominator / denominator_) 
			+ other.numerator_ * (new_denominator / other.denominator_);
		return Fraction(new_numerator, new_denominator);
	}

	Fraction operator-(Fraction other)
	{
		int new_denominator = std::lcm(denominator_, other.denominator_);
		int new_numerator = numerator_ * (new_denominator / denominator_)
			- other.numerator_ * (new_denominator / other.denominator_);
		return Fraction(new_numerator, new_denominator);
	}

	Fraction operator*(Fraction other)
	{
		int new_numerator = numerator_ *  other.numerator_;
		int new_denominator = denominator_ * other.denominator_;
		return Fraction(new_numerator, new_denominator);
	}

	Fraction operator/(Fraction other)
	{
		int new_numerator = numerator_ * other.denominator_;
		int new_denominator = denominator_ * other.numerator_;
		return Fraction(new_numerator, new_denominator);
	}

	Fraction& operator++()
	{
		numerator_ = numerator_ + denominator_;
		return *this;
	}

	Fraction& operator++(int)
	{
		Fraction tmp = *this;
		++(*this);
		return tmp;
	}

	Fraction& operator--()
	{	
		numerator_ = numerator_ - denominator_;
		return *this;
	}

	Fraction& operator--(int)
	{
		Fraction tmp = *this;
		--(*this);
		return tmp;
	}
};

int main()
{
	int numerator_1{ 0 }, numerator_2{ 0 }, denominator_1{ 0 }, denominator_2{ 0 };

	std::cout << "Введите числитель дроби 1: ";
	std::cin >> numerator_1;
	std::cout << "Введите знаменатель дроби 1: ";
	std::cin >> denominator_1;
	Fraction f1(numerator_1, denominator_1);

	std::cout << "Введите числитель дроби 2: ";
	std::cin >> numerator_2;
	std::cout << "Введите знаменатель дроби 2: ";
	std::cin >> denominator_2;
	Fraction f2(numerator_2, denominator_2);

	Fraction add = f1 + f2;
	Fraction sub = f1 - f2;
	Fraction multi = f1 * f2;
	Fraction div = f1 / f2;

	Fraction inc = (++f1) * f2;
	Fraction f1_copy = f1;
	Fraction dec = (f1_copy--) * f2;

	std::cout << f1.dump() << " + " << f2.dump() << " = " << add.dump() <<"\n";
	std::cout << f1.dump() << " - " << f2.dump() << " = " << sub.dump() << "\n";
	std::cout << f1.dump() << " * " << f2.dump() << " = " << multi.dump() << "\n";
	std::cout << f1.dump() << " / " << f2.dump() << " = " << div.dump() << "\n";
	
	std::cout << "++" << f1.dump() << " * " << f2.dump() << " = " << inc.dump() <<
		"\nЗначение дроби 1: " << f1.dump() << "\n";
	std::cout << f1.dump() << "--" << " * " << f2.dump() << " = " << dec.dump() <<
		"\nЗначение дроби 1: " << f1_copy.dump() << "\n";
	return 0;
}