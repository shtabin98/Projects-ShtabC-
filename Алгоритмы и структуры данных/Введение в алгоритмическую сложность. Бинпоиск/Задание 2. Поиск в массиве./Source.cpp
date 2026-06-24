#include <iostream>

int calc(int* arr,int size, int tchk)
{
    int ans = 0;
    
    for (int i = 0; i < size; ++i)
    {
        if (arr[i] > tchk)
        {
            ++ans;
        }
    }
    return ans;
}

int main()
{
    int arr[] = {14, 16, 19, 32, 32, 32, 56, 69, 72};
    int size = sizeof(arr) / sizeof(arr[0]);
    int tchk{};

    std::cout << "Введите точку отсчета: ";
    std::cin >> tchk;
    std::cout << "Количество элементов в массиве больших, чем " << tchk << ": " << calc(arr, size, tchk);

    return 0;
}