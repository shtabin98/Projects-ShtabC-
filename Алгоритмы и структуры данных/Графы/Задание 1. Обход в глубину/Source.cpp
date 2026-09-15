#include <iostream>
#include <fstream>
#include <vector>

void dfs(std::vector<std::vector<int>>& graph,int vertex, std::vector<bool>& visited);

int main()
{
	std::ifstream fin("in.txt");

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
		std::cout << "Порядок обхода вершин: ";
		dfs(graph, 0, visited);
	}

	fin.close();
	return 0;
}

void dfs(std::vector<std::vector<int>>& graph, int vertex, std::vector<bool>& visited)
{
	visited[vertex] = true;
	std::cout << vertex + 1 << " ";
	for (int i = 0; i < static_cast<int>(graph.size()); ++i)
	{
		if (graph[vertex][i] == 1 && !visited[i])
		{
			dfs(graph, i, visited);
		}
	}
}