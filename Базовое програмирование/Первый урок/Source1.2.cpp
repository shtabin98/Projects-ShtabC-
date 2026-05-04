#include <iostream>

struct bank_schet
{
	long long int number;
	std::string name;
	double balance;
};

void bank_func(bank_schet* schet, double new_balance);

int main()
{
	bank_schet schet;
	double new_balance;

	std::cout << "Введите номер счёта: ";
	std::cin >> schet.number; 
	std::cout << "Введите имя владельца: ";
	std::cin >> schet.name; 
	std::cout << "Введите баланс: ";
	std::cin >> schet.balance; 
	std::cout << "Введите новый баланс: ";
	std::cin >> new_balance;

	bank_func(&schet, new_balance);

	std::cout << "Ваш счет: " << schet.name << ", " << schet.number << ", " << schet.balance << std::endl;

	return 0;
}

void bank_func(bank_schet* schet, double new_balance)
{
	schet->balance = new_balance;
}
