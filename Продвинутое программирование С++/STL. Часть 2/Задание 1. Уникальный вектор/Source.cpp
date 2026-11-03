#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::vector<int> V1 = { 1, 1, 2 ,5, 6, 1, 2, 4 };
	std::sort(V1.begin(), V1.end());
	auto it = std::unique(V1.begin(), V1.end());
	V1.erase(it, V1.end());

	for (int x : V1) {
		std::cout << x << " ";
	}

	return 0;
}