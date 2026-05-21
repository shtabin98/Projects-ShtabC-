#include <iostream>
#include <string>
#include <fstream>

class Adress 
	{
		std::string __City = "Unknown";
		std::string __Street = "Unknown";
		int __House = 0;
		int __kv = 0;
	public:
		Adress(std::string City, std::string Street, int House, int kv)
		{
			__City = City;
			__Street = Street;
			__House = House;
			__kv = kv;
		};
		Adress() {};

		std::string get_City() const { return __City; };
		std::string get_Street() const { return __Street; };
		int get_House() const { return __House; };
		int get_kv() const { return __kv; };
	};

int main()
{
	std::ifstream fin{ "in.txt" };

	if (fin.is_open())
	{
		int size{};
		std::string City{};
		std::string Street{};
		int House = 0;
		int kv = 0;

		fin >> size;

		Adress* ar = new Adress[size];

		for (int i = 0; i < size; i++)
		{
			fin >> City;
			fin >> Street;
			fin >> House;
			fin >> kv;
			ar[i] = { City,Street, House, kv };
		}

		std::ofstream fout{ "out.txt" };

		if (fout.is_open())
		{
			fout << size << std::endl;
			for (int i = size-1; i >= 0; --i)
			{
				fout << ar[i].get_City() << ", ";
				fout << ar[i].get_Street() << ", ";
				fout << ar[i].get_House() << ", ";
				fout << ar[i].get_kv() << std::endl;
			}
		}
		delete[] ar;
	}
	fin.close();

	return 0;
}


