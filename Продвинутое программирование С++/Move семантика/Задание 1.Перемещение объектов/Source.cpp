#include <iostream>
#include <vector>
#include <string>
#include <utility>

template <typename T> void move_vectors(T& one, T& two)
{
		T tmp = std::move(one);
		one = std::move(two);
		two = std::move(tmp);
}

int main()
{
	std::vector <std::string> one = { "test_string1", "test_string2" };
	std::vector <std::string> two;
	
	std::cout << one[0] << " " << one[1] << "\n";

	move_vectors(one, two);

	std::cout << two[0] << " " << two[1] << "\n";

	return 0;
}