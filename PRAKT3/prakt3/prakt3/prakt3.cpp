#include <iostream>
#include <cmath>
double calculateTrianglePerimetr(double a, double b, double c);
/// <summary>
/// Вычисляет периметр треугольника
/// </summary>
/// <param name="a">Длина первой стороны треугольника</param>
/// <param name="b">Длина второй стороны треугольника</param>
/// <param name="c">Длина третьей стороны треугольника</param>
/// <returns>Периметр треугольника</returns>
/// <remarks>Если треугольник не существует, возвращает -1</remarks>
/// <param name="perimetr">Периметр</param>
double calculateTrianglePerimetr(double a, double b, double c)
{
    if (a <= 0 || b <= 0 || c <= 0 || a + b <= c || a + c <= b || b + c <= a)
    {
        return -1; // несуществующий треугольник
    }

    return a + b + c; //периметр
}

int main()
{
    setlocale(0, "");
    // Здесь будет видна подсказка с комментарием
    double perimetr = calculateTrianglePerimetr(10, 7, 2);

    if (perimetr == -1) {
        std::cout << "такого треугольника не существует" << std::endl;
    }
    else {
        std::cout << "Периметр треугольника: " << perimetr << std::endl;
    }
   
    return 0;
}



