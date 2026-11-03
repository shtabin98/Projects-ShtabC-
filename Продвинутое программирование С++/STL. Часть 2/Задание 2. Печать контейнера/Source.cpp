#include <iostream>
#include <set>
#include <vector>
#include <list>

template <typename Container>
void print_container(const Container& container)
{
	bool first = true;
	for (const auto& el : container)
	{
		if (!first)
		{
			std::cout << ", ";
		}
		first = false;
		std::cout << el;
	}
}

int main()
{
	std::set<std::string> test_set = { "one", "two", "three", "four" };
	print_container(test_set); // four one three two. помните почему такой порядок? :)
	std::cout << std::endl;

	std::list<std::string> test_list = { "one", "two", "three", "four" };
	print_container(test_list); // one, two, three, four
	std::cout << std::endl;

	std::vector<std::string> test_vector = { "one", "two", "three", "four" };
	print_container(test_vector); // one, two, three, four
	std::cout << std::endl;

	return 0;
}