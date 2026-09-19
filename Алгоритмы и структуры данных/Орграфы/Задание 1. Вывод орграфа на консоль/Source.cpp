
#include <iostream>
#include <fstream>
#include <vector>

int main() {
    std::ifstream fin("in.txt");
   
    int size;
    fin >> size;

    std::vector<std::vector<int>> graph(size, std::vector<int>(size));
    
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            fin >> graph[i][j];
        }
    }

    fin.close();

    for (int i = 0; i < size; ++i)
    {
        std::cout << i + 1 << ": ";

        bool has_edge = false;
        
        for (int j = 0; j < size; ++j)
        {
            if (graph[i][j] == 1)
            {
                if (has_edge) 
                {
                    std::cout << " ";  
                }
                std::cout << j + 1;
                has_edge = true;
            }
        }

        if (!has_edge) 
        {
            std::cout << "нет";
        }
        std::cout << '\n';
    }

    return 0;
}