#include <iostream>

int countGreater(int* arr,int size, int tchk)
{
    int ans = 0;
    int left = 0;
    int right = size - 1;

    while (left < right) 
    {
        int middle = left + (right - left) / 2; 
        if (arr[middle] <= tchk)
        {
            left = middle + 1;
        }
        else
        {
            right = middle;
        }
    }
    return size - left;
}

int main()
{
    int arr[] = {14, 16, 19, 32, 32, 32, 56, 69, 72};
    int size = sizeof(arr) / sizeof(arr[0]);
    int tchk{};

    std::cout << "Введите точку отсчета: ";
    std::cin >> tchk;
    std::cout << "Количество элементов в массиве больших, чем " << tchk << ": " << countGreater(arr, size, tchk);

    return 0;
}