#include <iostream>
using namespace std;

int stepen(int value, int power, int result);

int main(int argc, char** argv)
{
	stepen(5, 2, 1);
	stepen(3, 3, 1);
	stepen(4, 4, 1);

	return 0;
}

int stepen(int value, int power, int result)
{
	for (int i = 0; i < power; i++)
	{
		result *= value;
	}
	cout << value << " в степени " << power << " = " << result << endl;
	return 0;
}