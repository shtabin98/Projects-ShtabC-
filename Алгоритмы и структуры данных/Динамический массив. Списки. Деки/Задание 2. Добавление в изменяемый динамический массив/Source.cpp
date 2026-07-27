
#include <iostream>

void print_dynamic_array(int* arr, int size_fact, int size_logic);
int* append_to_dynamic_array(int* arr, int& size_fact, int& size_logic, int el);

int main() {
    int size_fact{}, size_logic{};

    std::cout << "Введите фактический размер массива: ";
    std::cin >> size_fact;
    std::cout << "Введите логический размер массива: ";
    std::cin >> size_logic;

    if (size_fact < size_logic || size_fact <= 0 || size_logic < 0) {
        std::cout << "Ошибка! Логический размер массива не может превышать фактический!\n";
        return 0;
    }

    int* arr = new int[size_fact];

    for (int i = 0; i < size_fact; ++i) {
        arr[i] = 0;
    }

    for (int i = 0; i < size_logic; ++i) {
        std::cout << "Введите arr[" << i << "]: ";
        std::cin >> arr[i];
    }

    print_dynamic_array(arr, size_fact, size_logic);

    while (true) {
        int el{};
        std::cout << "Введите элемент для добавления: ";
        std::cin >> el;
        if (el == 0)
        {
            std::cout << "Спасибо! Ваш массив: ";
            for (int i = 0; i < size_fact; ++i) {
                if (i < size_logic) {
                    std::cout << arr[i] << " ";
                }
                else {
                    std::cout << "_ ";
                }
            }
            break;
        }

        arr = append_to_dynamic_array(arr, size_fact, size_logic, el);
        print_dynamic_array(arr, size_fact, size_logic);
    }

    delete[] arr;
    return 0;
}

void print_dynamic_array(int* arr, int size_fact, int size_logic) {
    std::cout << "Динамический массив: ";
    for (int i = 0; i < size_fact; ++i) {
        if (i < size_logic) {
            std::cout << arr[i] << " ";
        }
        else {
            std::cout << "_ ";
        }
    }
    std::cout << "\n";
}

int* append_to_dynamic_array(int* arr, int& size_fact, int& size_logic, int el) {
    if (size_logic >= size_fact) {
        int new_size = size_fact * 2;
        if (new_size == 0) new_size = 1;

        int* new_arr = new int[new_size];

        for (int i = 0; i < size_fact; ++i) {
            new_arr[i] = arr[i];
        }
        
        for (int i = size_fact; i < new_size; ++i) {
            new_arr[i] = 0;
        }

        delete[] arr; 
        arr = new_arr;
        size_fact = new_size;
    }

    arr[size_logic] = el;
    ++size_logic;
    return arr;
}