#include <iostream>
#include <vector>

template <class T >
class functor
{
	int remainder{ 0 };
	std::vector <int> ar{ 4, 1, 3, 6, 25, 54 };
public:
	functor() = default;

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
	functor<int> f;

	std::cout << "Сумма чисел, делящихся на 3 = " << f.get_sum() << std::endl;
	std::cout << "Кол-во чисел, делящихся на 3 = " << f.get_count() << std::endl;

	return 0;
}