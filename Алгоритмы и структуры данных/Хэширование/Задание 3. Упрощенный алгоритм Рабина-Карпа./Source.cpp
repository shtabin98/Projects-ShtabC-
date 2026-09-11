#include <iostream>
#include <string>
#include <cmath>

int find_substring_light_rabin_karp(std::string s, std::string pods);

int main()
{
	std::string str;
	std::string podstr;

    std::cout << "Введите строку, в которой будет осуществляться поиск: ";
    std::cin >> str;

	do {
		std::cout << "Введите подстроку, которую нужно найти: ";
		std::cin >> podstr;

		int ans = find_substring_light_rabin_karp(str, podstr);

		if (ans != -1)
		{
			std::cout << "Подстрока " << podstr << " найдена по индексу " << ans << std::endl;
		}
		else
		{
			std::cout << "Подстрока " << podstr << " не найдена " << std::endl;
		}
	} while (podstr != "exit");
	return 0;
}

int find_substring_light_rabin_karp(std::string s, std::string pods) 
{
    const uint64_t p = 29;                
    const uint64_t mod = 1'000'000'007;  

    size_t m = pods.length();
    uint64_t h_pow = 1;
    for (size_t i = 0; i < m - 1; ++i) {
        h_pow = (h_pow * p) % mod;
    }

    uint64_t hash_pods = 0;
    for (char c : pods) {
        hash_pods = (hash_pods * p + static_cast<unsigned char>(c)) % mod;
    }

    uint64_t hash = 0;
    for (size_t i = 0; i < m; ++i) {
        hash = (hash * p + static_cast<unsigned char>(s[i])) % mod;
    }

    for (size_t i = 0; i <= s.length() - m; ++i) {
        if (hash == hash_pods) {
            bool match = true;
            for (size_t j = 0; j < m; ++j) {
                if (s[i + j] != pods[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                return static_cast<int>(i);
            }
        }

        if (i + m < s.length()) {
            unsigned char old_char = static_cast<unsigned char>(s[i]);
            unsigned char new_char = static_cast<unsigned char>(s[i + m]);

            hash = (hash + mod - (old_char * h_pow) % mod) % mod; 
            hash = (hash * p + new_char) % mod;
        }
    }

    return -1;
}
	


