#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\MiAir\source\repos\Базовое программирование\Unit - тестирование\Задание 2\Project1\extended_array.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(ExtendedArrayTest)
	{
	public:
		
		TEST_METHOD(Mean)
		{
			ExtArray<int> arr({ 1,5,5,5,5 });
			Assert::AreEqual(5.0, arr.mean());
		}
		TEST_METHOD(Mean_beg_end)
		{
			ExtArray<int> arr({ 1,4,8,1,1 });
			Assert::AreEqual(5.0, arr.mean(2,3));
		}
	};
}
