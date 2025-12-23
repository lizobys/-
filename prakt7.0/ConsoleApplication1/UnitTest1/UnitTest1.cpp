#include "pch.h"
#include "CppUnitTest.h"

#include "..\ConsoleApplication1\ConsoleApplication1.cpp"
#include <cmath>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

TEST_CLASS(PerimeterCalculatorTests)
{
public:

    TEST_METHOD(TestSquarePerimeter_Valid)
    {
        // Arrange: задаём корректные данные
        double side = 3.0;

        // Act: вызываем метод
        double result = PerimeterCalculator::squarePerimeter(side);


        // Assert: проверяем ожидаемый результат
        Assert::AreEqual(12.0, result, 1e-10);  // 4 * 3 = 12
    }

    TEST_METHOD(TestTrianglePerimeter_Valid)
    {
        // Arrange: стороны треугольника (3, 4, 5)
        double a = 3.0, b = 4.0, c = 5.0;


        // Act
        double result = PerimeterCalculator::trianglePerimeter(a, b, c);

        // Assert: 3 + 4 + 5 = 12
        Assert::AreEqual(12.0, result, 1e-10);
    } TEST_METHOD(TestSquarePerimeter_NegativeSide)
    {
        // Arrange: отрицательная сторона
        double side = -1.0;

        // Act & Assert: ожидаем исключение invalid_argument
        Assert::ExpectException<invalid_argument>([&]() {
            PerimeterCalculator::squarePerimeter(side);
            });
    }

    TEST_METHOD(TestTrianglePerimeter_InvalidSides)
    {
        // Arrange: стороны (1, 1, 3) — не образуют треугольник
        double a = 1.0, b = 1.0, c = 3.0;

        // Act & Assert: ожидаем исключение
        Assert::ExpectException<invalid_argument>([&]() {
            PerimeterCalculator::trianglePerimeter(a, b, c);
            });
    }
};