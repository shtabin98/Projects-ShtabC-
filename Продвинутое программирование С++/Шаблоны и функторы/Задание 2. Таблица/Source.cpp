#include <iostream>
#include <vector>
#include <string>

template <class T>
class table
{
	int num_row;
	int num_col;
	std::vector<std::vector<T>> ar;

public:
	table(int row, int col) : num_row(row), num_col(col)
	{
		ar = std::vector<std::vector<int>> (row, std::vector<int>(col));
	}

	std::vector<T>& operator[] (int r)
	{
		return ar[r];
	}

	std::vector<T>& operator[] (int r) const 
	{
		return ar[r];
	}

	std::string Size()
	{
		return std::to_string(num_row) + " X " + std::to_string(num_col);
	}
};


int main()
{
	auto test = table<int>(2, 3);
	test[0][0] = 4;

	std::cout << test[0][0] << std::endl;
	std::cout << test.Size() << std::endl;
	
	return 0;
}