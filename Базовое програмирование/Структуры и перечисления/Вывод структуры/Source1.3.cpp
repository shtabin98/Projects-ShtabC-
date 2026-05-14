#include <iostream>

struct adress
{
	std::string city;
	std::string street;
	std::string n_house; //Специально использую строку(для домов с адресами "2/3; 2к15" и т.п.
	int n_flat;
	int index;
};

void adr_func(adress* adr);

int main()
{
	adress adr_netology{ "Москва", "Варшавское шоссе", "1, строение 6", 315, 117105 };
	adress adr_my{ "Новосибирск", "Эйхе", "2", 89, 630037 };
	adr_func(&adr_netology);
	std::cout << std::endl;
	adr_func(&adr_my);

	return 0;
}

void adr_func(adress* adr)
{
	std::cout << "Город: " << adr->city << std::endl;
	std::cout << "Улица: " << adr->street << std::endl;
	std::cout << "Номер дома: " << adr->n_house << std::endl;
	std::cout << "Номер квартиры: " << adr->n_flat << std::endl;
	std::cout << "Индекс: " << adr->index << std::endl;
}