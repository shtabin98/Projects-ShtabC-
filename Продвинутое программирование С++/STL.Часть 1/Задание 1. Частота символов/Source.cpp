#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

int main()
{
	std::string text;
	std::cout << "Введите ваш текст: ";
	std::getline(std::cin, text);
	std::unordered_map <char, int> freq;

	for (char c : text)
	{
		++freq[c];
	}

	std::vector<std::pair<char, int>> items(freq.begin(), freq.end());

	std::sort(items.begin(), items.end(), [](const auto& a, const auto& b) {
		if (a.second != b.second) {
			return a.second > b.second; 
		}
		return a.first < b.first; 
		});

	for (const auto& [ch, count] : items)
	{
		std::cout << ch << ": " << count << "\n";
	}

	return 0;
}