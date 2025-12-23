#include <iostream>
#include <stdexcept>
using namespace std;

struct PerimeterCalculator {
    // Периметр квадрата: P = 4 * a
    static double squarePerimeter(double side) {
        if (side <= 0) {
            throw invalid_argument("side must be positive");
        }
        return 4.0 * side;
    }

    // Периметр прямоугольника: P = 2 * (a + b)
    static double rectanglePerimeter(double width, double height) {
        if (width <= 0 || height <= 0) {
            throw invalid_argument("side must be positivee");
        }
        return 2.0 * (width + height);
    }

    // Периметр треугольника: P = a + b + c
    static double trianglePerimeter(double a, double b, double c) {
        if (a <= 0 || b <= 0 || c <= 0) {
            throw invalid_argument("side must be positive");
        }
        // Проверка неравенства треугольника
        if (a + b <= c || a + c <= b || b + c <= a) {
            throw invalid_argument("invalid triangle: sides do not satisfy triangle inequality");
        }
        return a + b + c;
    }

    // Длина окружности: C = 2 * π * r
    static double circleCircumference(double radius) {
        if (radius <= 0) {
            throw invalid_argument("radius must be positive");
        }
        const double PI = 3.14;
        return 2.0 * PI * radius;
    }
};
int main() {
    setlocale(0, "");
    try {
        // Тест 1: Периметр квадрата
        double squareP = PerimeterCalculator::squarePerimeter(5.0);
        cout << "Периметр квадрата: " << squareP << endl;

        // Тест 2: Периметр прямоугольника
        double rectP = PerimeterCalculator::rectanglePerimeter(4.0, 6.0);
        cout << "Периметр прямоугольника: " << rectP << endl;

        // Тест 3: Периметр треугольника
        double triP = PerimeterCalculator::trianglePerimeter(3.0, 4.0, 5.0);
        cout << "Периметр треугольника: " << triP << endl;

        // Тест 4: Длина окружности
        double circC = PerimeterCalculator::circleCircumference(2.0);
        cout << "Длина окружности: " << circC << endl;

    }
    catch (const exception& e) {
        cerr << "Ошибка: " << e.what() << endl;
    }

    return 0;
}

