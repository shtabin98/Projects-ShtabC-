#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\MiAir\source\repos\Базовое программирование\Unit - тестирование\Задание 2\Project1\extended_array.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(ExtendedArrayTest)
	{
	public:
		//Тесты для корректного 

		TEST_METHOD(Mean) //Среднее для диапазона
		{
			ExtArray<int> arr({ 2,3,4 });
			Assert::AreEqual(2.5, arr.mean(0, 2));
		}

		TEST_METHOD(Mean_all) //Среднее для всего массива
		{
			ExtArray<int> arr({ 2,3,4 });
			Assert::AreEqual(3.0, arr.mean());
		}

		//Тесты для некорректного 

		TEST_METHOD(Mean_beg_end) //Для диапазона 
		{
			ExtArray<int> arr({ 1,4,8,1,1 });
			Assert::AreEqual(5.0, arr.mean(2, 3));
		}

		TEST_METHOD(Mean_beg_end_all) //Для всего массива
		{
			ExtArray<int> arr({ 2,3,4 });
			Assert::AreEqual(8.0, arr.mean());
		}
	};
}
