#include "tipo_vector.h"
#include <iostream>

int main()
{
	tipo_vector<int> vector;

	vector.push_back(10);
	vector.push_back(20);
	vector.push_back(30);
	vector.push_back(40);
	vector.push_back(50);

	std::cout << "Размер вектора: " << vector.size() << std::endl;
	std::cout << "Вместимость вектора: " << vector.capacity() << std::endl;
	std::cout << "Значения 3 индекса вектора: " << vector.at(3) << std::endl;

	return 0;
}
