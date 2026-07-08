#include "C:\Users\MiAir\source\repos\Базовое программирование\Курсовой проект. Симулятор гонок\Проект\lib\Race.h"
#include "C:\Users\MiAir\source\repos\Базовое программирование\Курсовой проект. Симулятор гонок\Проект\lib\Race_ground.h"
#include "C:\Users\MiAir\source\repos\Базовое программирование\Курсовой проект. Симулятор гонок\Проект\lib\Race_Air.h"

#include <iostream>
#include <iomanip>  

void rega();
std::string obrabotka(int type);
void vozvrat(const Str_Db_Pair& data);

int main()
{
	int go{};//для обработки начала гонки или окончания программы
	int type_race{ };//для выбора типа гонки
	size_t distantion{ };//для хранения дистанции
	int regist{ };//для обработки этапа регистрации
	int type{ };//для хранения типа выбранного транспортного средства после регистрации
	std::string race_t{ "" };//строка для хранения обозначения типа гонки
	int count_for_reg{  };//счетчик колличества регистраций
	int count[7] = { 0 };//массив для хранения номеров ТС, зарегистрированных на гонку

	std::cout << "Добро пожаловать в гоночный симулятор!\n";
	do
	{
	std::cout << "1. Гонка для наземного транспорта\n"
		"2. Гонка для воздушного транспорта\n"
		"3. Гонка для наземного и воздушного транспорта\n"
		"Выберете тип гонки: ";
	std::cin >> type_race;
		do
		{
		if (type_race >= 4)
		{
			std::cout << "Ошибка! Выберите один из трех типов гонок!\n";
			std::cout << "Выберете тип гонки: ";
			std::cin >> type_race;
		}
		switch (type_race)
		{
		case 1: race_t = "Гонка для наземного транспорта. "; break;
		case 2: race_t = "Гонка для воздушного транспорта. "; break;
		case 3: race_t = "Гонка для наземного и воздушного транспорта. "; break;
		default: std::cout << "Ошибка! Выберите один из трех типов гонок!";
		};
	} while (type_race >= 4);

	std::cout << "Укажите длину дистанции (должна быть положительна): ";
	std::cin >> distantion;
	std::cout << "Должно быть зарегистрировано хотя бы 2 транспортных средства\n";

	do
	{
		std::cout << "1. Зарегистрировать транспорт\n"
			<< "2. Начать гонку\n"
			<< "Выберите действие: ";
		std::cin >> regist;

		if (regist == 1)
		{
			++count_for_reg;
		}

		do
		{
			if (regist == 2 && count_for_reg < 2)
			{
				std::cout << "Должно быть зарегистрировано хотя бы 2 транспортных средства\n";
				std::cout << "1. Зарегистрировать транспорт\n"
					<< "2. Начать гонку\n"
					<< "Выберите действие: ";
				std::cin >> regist;
			}
			else
			{
				break;
			}
		} while (regist != 1);

		if (regist == 2)
		{
			break;
		}

		std::cout << race_t << "Расстояние: " << distantion << std::endl;
		rega();
		std::cin >> type;

		do
		{
			if (type > 4 && type_race == 1 || type < 5 && type_race == 2)
			{
				std::cout << "\nНельзя зарегистрировать данный вид траспорта на эту гонку!\n\n";
				break;
			}

			if (type < 8)
			{
				if (count[type - 1] == 1)
				{
					std::cout << "Нельзя регистрировать один и тот же тип ТС на одну гонку!\n\n";
					break;
				}
				if (count[type - 1] != 1)
				{
					++count[type - 1];
					std::cout << obrabotka(type) << " успешно зарегистрирован!";
					std::cout << race_t << "Расстояние: " << distantion << std::endl;
					rega();
					++count_for_reg;
					std::cin >> type;
				}
			}
			else
			{
				std::cout << "\nОшибка! Введен некоректный номер типа ТС!\n\n";
				rega();
				std::cin >> type;
			}

			if (count_for_reg > 1)
			{
				std::cout << "\nЗарегистрированные ТС: ";
				std::string result;
				for (int i = 0; i < 7; ++i)
				{
					if (count[i] == 1)
					{
						result += obrabotka(i + 1) + ", ";
					}
				}
				if (!result.empty())
					result.resize(result.size() - 2);
				std::cout << result << "\n\n";
			}
			else { continue; }
		} while (type != 0);
	} while (true);

	std::cout << "\nРезультаты гонки: \n";

	Race_ground g_race;
	Race_Air a_race;
	Race race;

	switch (type_race)
	{
	case 1:
	{
		Str_Db_Pair res_1 = g_race.all_calc(count, distantion);
		vozvrat(res_1);
		break;
	}
	case 2:
	{
		Str_Db_Pair res_2 = a_race.all_calc(count, distantion);
		vozvrat(res_2);
		break;
	}
	case 3:
	{
		Str_Db_Pair res_3 = race.all_calc(count, distantion);
		vozvrat(res_3);
		break;
	}
	};

	std::cout << "\n1. Провести еще одну гонку\n"
		<< "2. Выйти\n" <<
		"Выберите дейтвие: ";
		std::cin >> go;
} while (go != 2);

std::cout << "\nГонки окончены, все по домам!\n";

	return 0;
}

void rega()
{
	std::cout << "1. Верблюд\n2. Верблюд-быстроход\n";
	std::cout << "3. Кентавр\n4. Ботинки-вездеходы\n";
	std::cout << "5. Ковёр-самолёт\n6. Орёл\n";
	std::cout << "7. Метла\n0. Закончить регистрацию\n";
	std::cout << "Выберите транспорт или 0 для окончания процесса регистрации: ";
}

std::string obrabotka(int type)
{
	std::string type_ts{ "" };
	switch (type)
	{
	case 1: type_ts = "Верблюд"; break;
	case 2: type_ts = "Верблюд-быстроход"; break;
	case 3: type_ts = "Кентавр"; break;
	case 4: type_ts = "Ботинки-вездеходы"; break;
	case 5: type_ts = "Ковёр-самолёт"; break;
	case 6: type_ts = "Орёл"; break;
	case 7: type_ts = "Метла"; break;
	default: std::cout << "Ошибка! Введен некоректный номер типа ТС!";
	}
	return type_ts;
}

void vozvrat(const Str_Db_Pair& data)
{
	for (size_t i = 0; i < data.strings.size(); ++i) {
		// Пропускаем «пустые» записи, если они нужны только как заглушки
		if (data.strings[i].empty() || data.doubles[i] == 0.0) {
			continue;
		}
		std::cout << std::left << std::setw(20) << data.strings[i]
			<< ": " << std::fixed << std::setprecision(2)
			<< data.doubles[i] << "\n";
	}
}
