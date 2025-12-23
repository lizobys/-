#include <iostream>
using namespace std;

class ElementFinder {
private:
    int* array;      // указатель на массив
    int size;        // размер массива
    bool isSet;      // флаг: установлен ли массив

public:
    // Конструктор
    ElementFinder() : array(nullptr), size(0), isSet(false) {}

    // Деструктор
    ~ElementFinder() {
        delete[] array;
    }

    // Установить массив (копирует данные)
    void setArray(const int arr[], int size) {
        if (size <= 0) {
            cerr << "Ошибка: размер массива должен быть положительным." << endl;
            return;
        }

        // Освобождаем старую память, если была
        delete[] array;

        // Выделяем новую память и копируем данные
        this->size = size;
        this->array = new int[size];
        for (int i = 0; i < size; ++i) {
            this->array[i] = arr[i];
        }
        isSet = true;
    }

    // Найти элемент, вернуть индекс (или -1, если не найден)
    int findElement(int target) const {
        if (!isSet) {
            cerr << "Ошибка: массив не установлен." << endl;
            return -1;
        }

        for (int i = 0; i < size; ++i) {
            if (array[i] == target) {
                return i;  // возвращаем первый найденный индекс
            }
        }
        return -1;  // не найден
    }

    // Посчитать количество вхождений элемента
    int countOccurrences(int target) const {
        if (!isSet) {
            cerr << "Ошибка: массив не установлен." << endl;
            return 0;
        }

        int count = 0;
        for (int i = 0; i < size; ++i) {
            if (array[i] == target) {
                ++count;
            }
        }
        return count;
    }

    // Проверить наличие элемента (возвращает true/false)
    bool contains(int target) const {
        return findElement(target) != -1;
    }

    // Дополнительный метод: вывести массив (для отладки)
    void printArray() const {
        if (!isSet) {
            cout << "Массив не установлен." << endl;
            return;
        }
        cout << "Массив: ";
        for (int i = 0; i < size; ++i) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
};

// Пример использования
int main() {
    setlocale(0, "");
    ElementFinder finder;

    int data[] = { 10, 20, 30, 20, 40, 20 };
    int size = 6;

    finder.setArray(data, size);
    finder.printArray();

    cout << "Индекс элемента 20: " << finder.findElement(20) << endl;
    cout << "Количество вхождений 20: " << finder.countOccurrences(20) << endl;
    cout << "Содержит ли массив 30? " << (finder.contains(30) ? "Да" : "Нет") << endl;
    cout << "Содержит ли массив 50? " << (finder.contains(50) ? "Да" : "Нет") << endl;

    system("pause");
    return 0;
}

