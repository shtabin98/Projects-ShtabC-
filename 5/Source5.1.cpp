#include <iostream>
using namespace std;

int main()
{
	int massive[10]{5, 9, 5, 8, 589, 311, 711, 8958, 881, 1};

	for (int element{}; element < 9; ++element)
	{
		cout << massive[element] << ", ";
	}

	cout << massive[9];

	return 0;
}