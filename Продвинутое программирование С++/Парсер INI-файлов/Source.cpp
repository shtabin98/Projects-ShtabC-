#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <type_traits>

class pars_error : public std::runtime_error 
{
public:
	using std::runtime_error::runtime_error;
};

class ini_parser
{
	std::unordered_map<std::string,
		std::unordered_map<std::string, std::string>> Data;

	static void trim(std::string& s)
	{
		while (!s.empty() && (s.front() == ' ' || s.front() == '\t' || s.front() == '\r')) s.erase(0, 1);
		while (!s.empty() && (s.back() == ' ' || s.back() == '\t' || s.back() == '\r'))  s.pop_back();
	}

	static std::string trim_copy(std::string s) 
	{
		trim(s);
		return s;
	}

	template <typename T>
	static T convert(const std::string& value, const std::string& path) {
		if constexpr (std::is_same_v<T, std::string>) {
			return value;
		}
		else if constexpr (std::is_integral_v<T>) {
			return to_number<T>(value, path, [](const std::string& v, std::size_t& pos) {
				return std::stoll(v, &pos);
				});
		}
		else if constexpr (std::is_floating_point_v<T>) {
			return to_number<T>(value, path, [](const std::string& v, std::size_t& pos) {
				return std::stod(v, &pos);
				});
		}
		else {
			static_assert(sizeof(T) == 0,
				"поддерживаются только int, double/float и std::string");
		}
	}

	template <typename T, typename F>
	static T to_number(const std::string& value, const std::string& path, F parse) {
		try {
			std::size_t pos = 0;
			T result = static_cast<T>(parse(value, pos));
			if (pos != value.size())
				throw std::invalid_argument("лишние символы");
			return result;
		}
		catch (const std::exception&) {
			throw pars_error("значение \"" + value + "\" для \"" + path +
				"\" нельзя преобразовать в число");
		}
	}

public:
	explicit ini_parser(const std::string& filename)
	{
		std::fstream file(filename);
		if (!file.is_open())
		{
			throw pars_error("неудачная попытка открыть файл \"" + filename + "\"");
		}

		std::string current_section;
		std::string line;
		std::size_t line_num = 0;
		bool in_section = false;

		while (std::getline(file, line))
		{
			++line_num;

			if (auto pos = line.find(';'); pos != std::string::npos)
			{
				line.erase(pos);
			}

			trim(line);

			if (line.empty())
			{
				continue;
			}

			if (line.front() == '[')
			{
				if (line.back() != ']')
					throw pars_error("строка " + std::to_string(line_num) + ": некорректный формат \"" + line + "\"");

				current_section = trim_copy(line.substr(1, line.size() - 2));
				if (current_section.empty())
					throw pars_error("строка " + std::to_string(line_num) + ": пустое имя секции");

				in_section = true;
				continue;
			}

			auto eq = line.find('=');
			if (eq == std::string::npos || !in_section)
			{
				throw pars_error("строка " + std::to_string(line_num) + ": некорректный формат \"" + line + "\"");
			}

			std::string key = trim_copy(line.substr(0, eq));
			std::string value = trim_copy(line.substr(eq + 1));

			if (key.empty())
			{
				throw pars_error("строка " + std::to_string(line_num) + ": пустое имя переменной");
			}

			Data[current_section][key] = value;
		}

		if (file.bad())
		{
			throw pars_error("ошибка чтения файла \"" + filename + "\"");
		}
	}
		template <typename T>
		T get_value(const std::string& path) const
		{
			auto dot = path.find('.');
			if (dot == std::string::npos || dot == 0 || dot + 1 == path.size())
			{
				throw pars_error("некорректный ключ \"" + path + "\", ожидается формат \"секция.переменная\"");
			}

			const std::string section = path.substr(0, dot);
			const std::string key = path.substr(dot + 1);

			auto sec_it = Data.find(section);
			if (sec_it == Data.end())
			{
				throw pars_error("секция \"" + section + "\" не найдена");
			}

			auto key_it = sec_it ->second.find(key);
			if (key_it == sec_it ->second.end())
			{
				throw pars_error("переменная \"" + key + "\" не найдена в секции \"" + section + "\"");
			}
			return convert<T>(key_it->second, path);
		}
};

int main()
{
	try 
	{
		ini_parser parser("pars.ini");
		double v1 = parser.get_value<double>("Section1.var1");
		std::cout << v1 << "\n";
		std::string v2 = parser.get_value<std::string>("Section1.var2");
		std::cout << v2 << "\n";
		int m = parser.get_value<int>("Section1.var1");
		std::cout << m << "\n";
		double re = parser.get_value<double>("Section1.var1");
		std::cout << re << "\n";
	}
	catch (const pars_error& e)
	{
		std::cerr << "Ошибка INI: " << e.what() << '\n';
		return 1;
	}
}