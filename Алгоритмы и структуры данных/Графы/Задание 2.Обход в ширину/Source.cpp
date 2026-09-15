#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

void bfs(std::vector<std::vector<int>>& graph, int vertex, std::vector<bool>& visited);

int main()
{
	std::ifstream fin("in.txt");

	if (fin.is_open())
	{
		int vershina{};
		int size{};
		fin >> size;

		std::vector<std::vector<int>> graph(size, std::vector<int>(size));

		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < size; ++j)
			{
				fin >> graph[i][j];
			}
		}

		std::vector<bool> visited(size, false);

		std::cout << "В графе " << size << " вершин. Введите номер вершины, с которой начнется обход: ";
		std::cin >> vershina;
		std::cout << "Порядок обхода вершин: ";
		bfs(graph, vershina - 1, visited);
	}

	fin.close();
	return 0;
}

void bfs(std::vector<std::vector<int>>& graph, int vershina, std::vector<bool>& visited)
{
	std::queue<int> queue;
	int vertex{};
	visited[vershina] = true;

	queue.push(vershina);

	while (!queue.empty())
	{
		vertex = queue.front();
		queue.pop();
		std::cout << vertex + 1 << " ";

		for (int i = 0; i < static_cast<int>(graph.size()); ++i)
		{
			if (graph[vertex][i] == 1 && !visited[i])
			{
				visited[i] = true;
				queue.push(i);
			}
		}
	}
}
