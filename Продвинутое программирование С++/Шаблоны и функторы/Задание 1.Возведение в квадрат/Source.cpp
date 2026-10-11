#include <iostream>
#include <vector>

template <typename T>
T quatro(T a)
{
	return a * a;
};

template <typename T>
std::vector<T> quatro(std::vector <T> vec)
{
	std::vector<T> result;
	for (auto i = 0 ; i < vec.size(); ++i)
	{
		result.push_back(quatro(vec[i]));
	}
	return result;
}


int main()
{
	std::cout << "Для одного элемента: " << quatro(-1) << std::endl;

	std::vector<int> v = { 1, 2, 3, 4 , 5, 6};
	auto v2 = quatro(v);

	int i = 0;

	std::cout << "Для вектора: ";
	for (auto i = 0; i < v2.size(); ++i)
	{
		std::cout << v2[i] << " ";
	}
	return 0;
}