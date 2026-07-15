#include <iostream>

void quick_sort(int* arr, int size);
int part(int* arr, int left, int right);
void quick_sort_impl(int* arr, int low, int high);
void print_array(const int* arr, int size);

int main()
{
	int arr_a[10] = { 3, 43, 38, 29, 18, 72, 57, 61, 2, 33 };
	int arr_b[15] = { 88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74 };
	int arr_c[18] = { 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };

	std::cout << "Исходный массив: ";
	print_array(arr_a, std::size(arr_a));
	quick_sort(arr_a, std::size(arr_a));
	std::cout << "Отсортированный массив: ";
	print_array(arr_a, std::size(arr_a));
	std::cout << "\n";

	std::cout << "Исходный массив: ";
	print_array(arr_b, std::size(arr_b));
	quick_sort(arr_b, std::size(arr_b));
	std::cout << "Отсортированный массив: ";
	print_array(arr_b, std::size(arr_b));
	std::cout << "\n";

	std::cout << "Исходный массив: ";
	print_array(arr_c, std::size(arr_c));
	quick_sort(arr_c, std::size(arr_c));
	std::cout << "Отсортированный массив: ";
	print_array(arr_c, std::size(arr_c));
	std::cout << "\n";

	return 0;
}

int part(int* arr, int left, int right)
{
	int pivot = arr[right];
	int i = left - 1;

	for (int j = left; j < right; ++j) 
	{
		if (arr[j] <= pivot) {
			++i;
			std::swap(arr[i], arr[j]);
		}
	}
	std::swap(arr[i + 1], arr[right]);
	return i + 1;
}

void quick_sort_impl(int* arr, int low, int high)
{
	if (low < high) {
		int pi = part(arr, low, high);
		quick_sort_impl(arr, low, pi - 1);
		quick_sort_impl(arr, pi + 1, high);
	}
}

void quick_sort(int* arr, int size)
{
	if (size <= 1) return;
	quick_sort_impl(arr, 0, size - 1);
}

void print_array(const int* arr, int size)
{
	for (int i = 0; i < size; ++i) {
		std::cout << arr[i];
		if (i != size - 1) std::cout << " ";
	}
	std::cout << "\n";
}