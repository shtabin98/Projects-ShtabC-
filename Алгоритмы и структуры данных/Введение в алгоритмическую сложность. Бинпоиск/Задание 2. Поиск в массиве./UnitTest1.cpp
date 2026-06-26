#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\MiAir\source\repos\Алгоритмы и структуры данных\Введение в алгоритмическую сложность. Бинпоиск\Задание 2. Поиск в массиве\Project1\Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(CountGreaterTests)
{
public:

    // tchk меньше минимального элемента: все элементы больше
    TEST_METHOD(TestAllElementsGreater) {
        int arr[] = { 10, 20, 30, 40, 50 };
        Assert::AreEqual(5, countGreater(arr, 5, 5));
    }

    // tchk в середине диапазона: часть элементов больше
    TEST_METHOD(TestMiddleValue) {
        int arr[] = { 10, 20, 30, 40, 50 };
        // больше 30: это 40 и 50 → 2 элемента
        Assert::AreEqual(2, countGreater(arr, 5, 30));
    }

    // tchk больше максимального элемента: ни один элемент не больше
    TEST_METHOD(TestNoElementsGreater) {
        int arr[] = { 10, 20, 30, 40, 50 };
        Assert::AreEqual(0, countGreater(arr, 5, 100));
    }

    // все элементы одинаковые, tchk равен этому значению: больше нет
    TEST_METHOD(TestAllEqual_EqualCheck) {
        int arr[] = { 7, 7, 7, 7 };
        Assert::AreEqual(0, countGreater(arr, 4, 7));
    }

    // все элементы одинаковые, tchk меньше: все больше
    TEST_METHOD(TestAllEqual_LessCheck) {
        int arr[] = { 7, 7, 7, 7 };
        Assert::AreEqual(4, countGreater(arr, 4, 6));
    }

    // все элементы одинаковые, tchk больше: ни один не больше
    TEST_METHOD(TestAllEqual_GreaterCheck) {
        int arr[] = { 7, 7, 7, 7 };
        Assert::AreEqual(0, countGreater(arr, 4, 8));
    }

    // массив из одного элемента: больше
    TEST_METHOD(TestSingleElement_Greater) {
        int arr[] = { 10 };
        Assert::AreEqual(1, countGreater(arr, 1, 5));
    }

    // массив из одного элемента: не больше
    TEST_METHOD(TestSingleElement_NotGreater) {
        int arr[] = { 10 };
        Assert::AreEqual(0, countGreater(arr, 1, 15));
    }

    // массив из одного элемента: равно (не считается как «больше»)
    TEST_METHOD(TestSingleElement_Equal) {
        int arr[] = { 10 };
        Assert::AreEqual(0, countGreater(arr, 1, 10));
    }

    // пустой массив (size = 0): корректно возвращаем 0
    TEST_METHOD(TestEmptyArray) {
        int* arr = nullptr;
        Assert::AreEqual(0, countGreater(arr, 0, 10));
    }

    // size = 0 при не-null указателе — тоже 0 (граничный случай)
    TEST_METHOD(TestZeroSizeWithNonNullPointer) {
        int arr[] = { 1, 2, 3 };
        Assert::AreEqual(0, countGreater(arr, 0, 2));
    }
};
