#include <fstream>
#include <string>
#include <iostream>
using namespace std;

void setConsoleColor(const string& color) {
    if (color == "red") {
        system("color 4F"); // красный фон + белый текст
    }
    else if (color == "blue") {
        system("color 1F"); // синий фон + белый текст
    }
    else if (color == "green") {
        system("color 2F"); // зелёный фон + белый текст
    }
    else if (color == "yellow") {
        system("color 6F"); // жёлтый фон + белый текст
    }
    else if (color == "white") {
        system("color 7F"); // белый фон + чёрный текст
    }
    else {
        system("color 0F"); // по умолчанию: чёрный фон + белый текст
    }
}

void writeFood()
{
    setlocale(0, "");
    string food;

    ifstream fin("food.txt");
    if (fin.is_open()) {
        fin >> food;
        fin.close();
        cout << "Любимая еда: " << food << endl;

        char choice;
        cout << "\nХотите изменить любимую еду? (y/n): ";
        cin >> choice;

        if (choice == 'y' || choice == 'Y') {
            cout << "Введите любимую еду заново: ";
            cin >> food;

            ofstream fout("food.txt");
            fout << food << " ";
            fout.close();

            cout << "Любимая еда обновлена!" << endl;
        }
    }
    else {
        // файла нет – вводим новые настройки
        cout << "Введите любимую еду: ";
        cin >> food;

        ofstream fout("food.txt");
        fout << food << " ";
        fout.close();

        cout << "Любимая еда обновлена!" << endl;
    }
}
void writeColor()
{
    setlocale(0, "");
    string color;

    ifstream fin("color.txt");
    if (fin.is_open()) {
        fin >> color;
        fin.close();
        cout << "Цвет консоли: " << color << endl;

        char choice;
        cout << "\nХотите изменить цвет консоли? (y/n): ";
        cin >> choice;

        if (choice == 'y' || choice == 'Y') {
            cout << "Введите новый цвет консоли: ";
            cin >> color;

            ofstream fout("color.txt");
            fout << color << " ";
            fout.close();

            cout << "Цвет консоли обновлен!" << endl;
        }
    }
    else {
        // файла нет – вводим новые настройки
        cout << "Введите новый цвет консоли: ";
        cin >> color;

        ofstream fout("color.txt");
        fout << color << " ";
        fout.close();

        cout << "Цвет консоли обновлен!" << endl;
    }
}

int main() {
    string color;

    ifstream fin("color.txt");
    fin >> color;
    fin.close();
    setConsoleColor(color);

    writeColor();
    writeFood();

    return 0;
}
