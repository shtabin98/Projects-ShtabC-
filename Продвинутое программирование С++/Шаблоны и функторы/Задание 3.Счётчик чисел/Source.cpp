#include <iostream>
#include <vector>

template <class T >
class functor
{
	int remainder{ 0 };
	std::vector <int> ar;
public:
	functor(std::vector <int> ar) : ar(std::move(ar)) {}

	auto get_sum()
	{
		auto sum{ 0 };
		for (int i = 0; i < ar.size(); ++i)
		{
			if (ar[i] % 3 == remainder)
				sum += ar[i];
		}
		return sum;
	}

	auto get_count()
	{
		auto count{ 0 };
		for (int i = 0; i < ar.size(); ++i)
		{
			if (ar[i] % 3 == remainder)
				++count;
		}
		return count;
	}
};


int main()
{
	std::vector <int> ar;
	ar.reserve(6);
	
	for (int i = 0; i < 6; ++i)
		{
			int value{};
			std::cin >> value;
			ar.push_back(value);
		}

	functor<int> f(ar);

	std::cout << "get_sum() = " << f.get_sum() << std::endl;
	std::cout << "get_count() = " << f.get_count() << std::endl;

	return 0;
}