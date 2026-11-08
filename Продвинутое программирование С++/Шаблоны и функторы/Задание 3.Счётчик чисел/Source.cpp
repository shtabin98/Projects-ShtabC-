#include <iostream>
#include <vector>
#include <algorithm>

template <class T >
class functor
{
	int count{0};
	int sum{0};
	std::vector <int> ar{ 4, 1, 3, 6, 25, 54 };
public:
	functor() {}

	void operator ()()
	{
		for (int i = 0; i < ar.size(); ++i)
		{
			if (ar[i] % 3 == 0)
			{
				sum += ar[i];
				++count;
			}
		}
	}

	int get_sum() const { return sum;}
	int get_count() const {return count;}
};


int main()
{
	functor<int> f;
	f();

	std::cout << "get_sum() = " << f.get_sum() << std::endl;
	std::cout << "get_count() = " << f.get_count() << std::endl;

	return 0;
}