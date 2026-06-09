#include <iostream>
#include <string>
#include <numeric>

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}

	std::string dump(int numerator, int denominator)
	{
		
		return std::to_string(numerator) + "/" + std::to_string(denominator);
	}

	Fraction operator+(Fraction other)
	{ 
		int nok = std::lcm(denominator_, other.denominator_);

		int new_numerator = numerator_ * (nok / denominator_) + other.numerator_ * (nok / other.denominator_);
		int new_denominator = nok;
		return Fraction(new_numerator, new_denominator);
	}

	Fraction operator-(Fraction other)
	{
		int nok = std::lcm(denominator_, other.denominator_);

		int new_numerator = numerator_ * (nok / denominator_) - other.numerator_ * (nok / other.denominator_);
		int new_denominator = nok;
		return Fraction(new_numerator, new_denominator);
	}

	Fraction operator*(Fraction other)
	{
		int new_numerator = numerator_ *  other.numerator_;
		int new_denominator = denominator_ * other.denominator_;
		int nod = std::gcd(new_numerator, new_denominator);
		new_numerator = new_numerator / nod;
		new_denominator = new_denominator / nod;
		return Fraction(new_numerator, new_denominator);
	}

	Fraction operator/(Fraction other)
	{
		int new_numerator = numerator_ * other.denominator_;
		int new_denominator = denominator_ * other.numerator_;
		int nod = std::gcd(new_numerator, new_denominator);
		new_numerator = new_numerator / nod;
		new_denominator = new_denominator / nod;
		return Fraction(new_numerator, new_denominator);
	}

	int get_numerator() { return numerator_; }
	int get_denominator() { return denominator_; }


	Fraction& operator++()
	{
		numerator_ = numerator_ + denominator_;
		denominator_;
		return *this;
	}

	Fraction& operator--()
	{
		Fraction tmp{ *this };
		numerator_ = numerator_ + denominator_;
		denominator_;
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
	Fraction dec = (--f1) * f2;



	std::cout << f1.dump(numerator_1,denominator_1) << " + " << f2.dump(numerator_2, denominator_2) <<
		" = " << add.get_numerator() << "/" << add.get_denominator() << "\n";

	std::cout << f1.dump(numerator_1, denominator_1) << " - " << f2.dump(numerator_2, denominator_2) <<
		" = " << sub.get_numerator() << "/" << sub.get_denominator() << "\n";

	std::cout << f1.dump(numerator_1, denominator_1) << " * " << f2.dump(numerator_2, denominator_2) <<
		" = " << multi.get_numerator() << "/" << multi.get_denominator() << "\n";

	std::cout << f1.dump(numerator_1, denominator_1) << " / " << f2.dump(numerator_2, denominator_2) <<
		" = " << div.get_numerator() << "/" << div.get_denominator() << "\n";

	std::cout << "++" << f1.dump(numerator_1, denominator_1) << " * " << f2.dump(numerator_2, denominator_2) <<
		" = " << inc.get_numerator() << "/" << inc.get_denominator() <<
		"\nЗначение дроби 1: " << f1.dump(numerator_1, denominator_1) << "\n";

	std::cout << f1.dump(numerator_1, denominator_1) << "--" << " * " << f2.dump(numerator_2, denominator_2) <<
		" = " << dec.get_numerator() << "/" << dec.get_denominator() <<
		"\nЗначение дроби 1: " << f1.dump(numerator_1, denominator_1) << "\n";

	return 0;
}