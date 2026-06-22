#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\MiAir\source\repos\Базовое программирование\Unit - тестирование\Задание 3\Project1\extended_array.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(ExtArrayTest)
{
public:
    // Тест для метода mean() — среднее всего массива
    TEST_METHOD(Mean_EntireArray)
    {
        ExtArray<int> arr = { 1, 2, 3, 4, 5 };
        double result = arr.mean();
        Assert::AreEqual(3.0, result, 0.0001);
    }

    // Тест для mean() с пустым массивом
    TEST_METHOD(Mean_EmptyArray)
    {
        ExtArray<int> arr(0);
        double result = arr.mean();
        Assert::AreEqual(0.0, result, 0.0001);
    }

    // Тест для mean(begin, end) — корректный диапазон
    TEST_METHOD(MeanRange_ValidRange)
    {
        ExtArray<int> arr = { 1, 2, 3, 4, 5 };

        // Диапазон [1, 4) → элементы [2, 3, 4], среднее = 3.0
        double result1 = arr.mean(1, 4);
        Assert::AreEqual(3.0, result1, 0.0001);

        // Весь массив [0, 5) → среднее = 3.0
        double result2 = arr.mean(0, 5);
        Assert::AreEqual(3.0, result2, 0.0001);

        // Один элемент [2, 3) → элемент [3], среднее = 3.0
        double result3 = arr.mean(2, 3);
        Assert::AreEqual(3.0, result3, 0.0001);
    }

    // Тест для mean(begin, end) — begin >= end (ошибочный диапазон)
    TEST_METHOD(MeanRange_InvalidRange_BeginGreaterThanEnd)
    {
        ExtArray<int> arr = { 1, 2, 3 };

        try
        {
            arr.mean(2, 1);
            Assert::Fail(L"Expected std::invalid_argument exception when begin >= end");
        }
        catch (const std::invalid_argument&)
        {
            // Ожидаемое исключение — тест пройден
        }
    }

    TEST_METHOD(MeanRange_InvalidRange_BeginEqualToEnd)
    {
        ExtArray<int> arr = { 1, 2, 3 };

        try
        {
            arr.mean(3, 3);
            Assert::Fail(L"Expected std::invalid_argument exception when begin == end");
        }
        catch (const std::invalid_argument&)
        {
            // Ожидаемое исключение — тест пройден
        }
    }

    // Тест для mean(begin, end) — пустой массив
    TEST_METHOD(MeanRange_EmptyArray)
    {
        ExtArray<int> arr(0); // Пустой массив

        try
        {
            arr.mean(0, 1);
            Assert::Fail(L"Expected std::invalid_argument exception for empty array");
        }
        catch (const std::invalid_argument&)
        {
            // Ожидаемое исключение — тест пройден
        }
    }

    // Тест для median() — нечётный размер
    TEST_METHOD(Median_OddSize)
    {
        ExtArray<int> arr = { 3, 1, 4, 2, 5 }; // После сортировки: [1,2,3,4,5]
        double result = arr.median();
        Assert::AreEqual(3.0, result, 0.0001);
    }

    // Тест для median() — чётный размер
    TEST_METHOD(Median_EvenSize)
    {
        ExtArray<int> arr = { 4, 1, 3, 2 }; // После сортировки: [1,2,3,4]
        double result = arr.median();
        Assert::AreEqual(2.5, result, 0.0001);
    }

    // Тест для mode() — один режим
    TEST_METHOD(Mode_SingleMode)
    {
        ExtArray<int> arr = { 1, 2, 2, 3, 2 };
        auto result = arr.mode();
        Assert::AreEqual(2, result.first);
        Assert::AreEqual(3, result.second);
    }

    // Тест для mode() — пустой массив
    TEST_METHOD(Mode_EmptyArray)
    {
        ExtArray<int> arr(0);
        auto result = arr.mode();
        Assert::AreEqual(0, result.first);
        Assert::AreEqual(0, result.second);
    }

    // Тест для checkSum() — массив bool
    TEST_METHOD(CheckSum_BoolArray)
    {
        ExtArray<bool> arr = { true, false, true, true };
        int result = arr.checkSum();
        Assert::AreEqual(3, result);
    }

    // Тест для checkSum() — массив int с 0 и 1
    TEST_METHOD(CheckSum_IntArrayWithZeroAndOne)
    {
        ExtArray<int> arr = { 0, 1, 0, 1, 1 };
        int result = arr.checkSum();
        Assert::AreEqual(3, result);
    }

    // Тест для checkSum() — int массив с недопустимыми значениями (выброс исключения)
    TEST_METHOD(CheckSum_IntArrayWithInvalidValues)
    {
        ExtArray<int> arr = { 0, 1, 2, 1 }; // Содержит 2 — недопустимое значение

        try
        {
            int result = arr.checkSum();
            Assert::Fail(L"Expected std::logic_error exception for invalid values in int array");
        }
        catch (const std::logic_error&)
        {
            // Ожидаемое исключение — тест пройден
        }
    }

    // Тест для checkSum() — неподдерживаемый тип (выброс исключения)
    TEST_METHOD(CheckSum_UnsupportedType)
    {
        ExtArray<double> arr = { 1.0, 2.0, 3.0 };

        try
        {
            int result = arr.checkSum();
            Assert::Fail(L"Expected std::bad_typeid exception for unsupported type");
        }
        catch (const std::bad_typeid&)
        {
            // Ожидаемое исключение — тест пройден
        }
    }
};
