#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
#include <algorithm>
#include <string>

class big_integer
{
	std::string integer;

public:
	big_integer() : integer("0") {}
	
    explicit big_integer(const std::string& s)
        : integer(s.rbegin(), s.rend()) 
    {
        if (integer.empty()) integer = "0";
    }

    big_integer(const big_integer&) = default;
    big_integer& operator=(const big_integer&) = default;

	big_integer(big_integer&& other) noexcept  
		: integer(std::move(other.integer)) {}

	big_integer& operator= (big_integer&& other) noexcept 
	{
        if (this != &other)
        {
            integer = std::move(other.integer);
            other.integer = "0";
        }
        return *this;
	}

    big_integer operator+(const big_integer& rhs) const
    {
        std::string res;
        int carry = 0;
        for (std::size_t i = 0; i < std::max(integer.size(), rhs.integer.size()) || carry; ++i)
        {
            int sum = carry;
            if (i < integer.size())     sum += integer[i] - '0';
            if (i < rhs.integer.size()) sum += rhs.integer[i] - '0';
            res.push_back(static_cast<char>('0' + sum % 10));
            carry = sum / 10;
        }
        return big_integer(std::move(res));
    }

    big_integer operator*(int rhs) const
    {
        std::string res;
        int carry = 0;
        for (std::size_t i = 0; i < integer.size() || carry; ++i)
        {
            long long cur = carry;
            if (i < integer.size()) cur += static_cast<long long>(integer[i] - '0') * rhs;
            res.push_back(static_cast<char>('0' + cur % 10));
            carry = static_cast<int>(cur / 10);
        }
        while (res.size() > 1 && res.back() == '0') res.pop_back(); // ведущие нули
        return big_integer(std::move(res));
    }

    friend std::ostream& operator<<(std::ostream& os, const big_integer& x)
    {
        return os << std::string(x.integer.begin(), x.integer.end());
    }

};

int main()
{
    auto number1 = big_integer("114575");
    auto number2 = big_integer("78524");
    auto result = number1 + number2;
    std::cout << result << '\n'; 

    std::cout << number1 * 3 << '\n';   
    std::cout << number2 * 100 << '\n'; 

    return 0;
}