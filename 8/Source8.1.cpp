#include <iostream>

void counting_function();

int main(int argc, char** argv)
{
    for (int i = 0; i < 15; i++)
    {
        counting_function();
    }
}

void counting_function()
{
    static int counter{};
    std::cout << "Количество вызовов функции: "<< ++counter << std:: endl;
}