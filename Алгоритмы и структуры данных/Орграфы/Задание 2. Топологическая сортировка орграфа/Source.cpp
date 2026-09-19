#include <iostream>
#include <fstream>
#include <vector>

void dfs(std::vector<std::vector<int>>& graph, int vershina,
	std::vector<bool>& visited, std::vector<int>& order);

int main()
{
	std::ifstream fin("in2.txt");

	if (fin.is_open())
	{
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
		std::vector<int> order;

		for (int v = 0; v < size; ++v)
		{
			if (!visited[v])
			{
				dfs(graph, v, visited, order);
			}
		}

		std::cout << "Топологический порядок вершин: ";
		for (int i = static_cast<int>(order.size()) - 1; i >= 0; --i)
		{
			std::cout << order[i] << " ";
		}
		std::cout << std::endl;
	}

	fin.close();
	return 0;
}

void dfs(std::vector<std::vector<int>>& graph, int vershina,
	std::vector<bool>& visited, std::vector<int>& order)
{
	visited[vershina] = true;

	for (int i = 0; i < static_cast<int>(graph.size()); ++i)
	{
		if (graph[vershina][i] == 1 && !visited[i])
		{
			dfs(graph, i, visited, order);
		}
	}

	order.push_back(vershina + 1);
}