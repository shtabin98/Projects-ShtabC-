#include <iostream>
using namespace std;

int main()
{
	int num1, num2, num3;
	cout << "Введите первое число: ";
	cin >> num1;
	cout << "Введите второе число: ";
	cin >> num2;
	cout << "Введите третье число: ";
	cin >> num3;

	int max_result = num1 > num2 ? num1 > num3 ? num1 : num3 : num2 > num3 ? num2 : num3;
	int min_result = num1 < num2 ? num1 < num3 ? num1 : num3 : num2 < num3 ? num2 : num3;

	int mid1 = max_result != num1 ? min_result != num1 ? num1 : num2 : num2;
	int mid2 = max_result != num2 ? min_result != num2 ? num2 : num3 : num3;
	int mid3 = max_result != num3 ? min_result != num3 ? num3 : num1 : num1;
	
	int mid_result = mid1 != mid2 ? mid3 : mid1;

	cout << "Результат: " << max_result << " " << mid_result << " " << min_result << endl;

	return 0;
}