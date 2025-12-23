
#include <iostream>
#include <cmath>
#include <stdexcept>


using namespace std;
struct Fraction {
    int numerator;
    int denominator;

    Fraction(int num = 0, int den = 1) : numerator(num), denominator(den) {
        if (denominator == 0) {
            throw invalid_argument("Знаменатель не может быть равен нулю!");
        }
        numerator = num;
        denominator = den;
    }

    static void simplifyFraction(Fraction& frac) {
        int a = abs(frac.numerator);
        int b = abs(frac.denominator);
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        int gcd = a;

        frac.numerator /= gcd;
        frac.denominator /= gcd;

        if (frac.denominator < 0) {
            frac.numerator = -frac.numerator;
            frac.denominator = -frac.denominator;
        }
    }

    static void addFractions(const Fraction& f1, const Fraction& f2, Fraction& result) {
        result.numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
        result.denominator = f1.denominator * f2.denominator;
        simplifyFraction(result);
    }

    static void multiplyFractions(const Fraction& f1, const Fraction& f2, Fraction& result) {
        result.numerator = f1.numerator * f2.numerator;
        result.denominator = f1.denominator * f2.denominator;
        simplifyFraction(result);
    }

    static double toDecimal(const Fraction& frac) {
        return static_cast<double>(frac.numerator) / frac.denominator;
    }

    void print() const {
        cout << numerator << "/" << denominator;
    }
};

int main() {
    setlocale(0, "");
    try {
        Fraction f1(5, 10);
        Fraction f2(5, 10);
        Fraction result;

        cout << "Дробь 1: ";
        f1.print();
        cout << endl;

        cout << "Дробь 2: ";
        f2.print();
        cout << endl;

        Fraction::addFractions(f1, f2, result);
        cout << "Сумма: ";
        result.print();

        Fraction::multiplyFractions(f1, f2, result);
        cout << endl << "Произведение: ";
        result.print();

        Fraction f3(1, 1);
        Fraction::simplifyFraction(f3);
        cout << endl << "Упрощенние дроби 4/15: ";
        f3.print();
        cout << endl << "Дробь 8/12 в десятичное число: " << Fraction::toDecimal(f3) << endl;
    }
    catch (const invalid_argument& e) {
        cerr << "Ошибка аргумента: " << e.what() << endl;
    }
    catch (const overflow_error& e) {
        cerr << "Ошибка переполнения: " << e.what() << endl;
    }
    catch (const exception& e) {
        cerr << "Неизвестная ошибка: " << e.what() << endl;
    }

    system("pause");
    return 0;
}