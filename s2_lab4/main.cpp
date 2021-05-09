#include <iostream>
#include "funcs.h"
using namespace std;

void promt(int &a, int &b, int &c, int &d)
{
    cout << "Введите число a: " << endl;
    cin >> a;
    cout << "Введите число b: " << endl;
    cin >> b;
    cout << "Введите число c: " << endl;
    cin >> c;
    cout << "Введите число d: " << endl;
    cin >> d;
}

// Вариант 3
int main()
{
    // g++ funcs.cpp main.cpp -o main.out
    int choice{ 0 };
    int a{ 0 }, b{ 0 }, c{ 0 }, d{ 0 };
    double r{ 0 };

    while (!cin.fail()) {
        cout << "Выберите функцию:\n"
            << "1) min\n"
            << "2) even\n"
            << "3) average\n"
            << "4) fibonacci\n"
            << "5) bitPrint int\n"
            << "6) bitPrint double"
            << endl;

        cin >> choice;
        switch (choice) {
            case 1:
            // 1, 2, 3, 4     -  1
            // 4, 3, 2, 1     -  1
            // -4, -4, -2, -1 - -1
            promt(a, b, c, d);
            r = min(a, b, c, d); 
            cout << "min: " << r << endl;
            break;

            case 2:
            // 1, 1,  1, 1 - 0
            // 2, 0, -2, 4 - 4
            promt(a, b, c, d);
            r = even(a, b, c, d);
            cout << "even: " << r << endl;
            break;

            case 3: 
            // 1, 2, 3, 4 - 2.5
            promt(a, b, c, d);
            r = average(a, b, c, d);
            cout << "average: " << r << endl;
            break;

            case 4: {
                int n{ 0 }, nBegin{ 0 };
                cout << "Введите n: ";
                cin >> n;
                cout << "Введите nBegin: ";
                cin >> nBegin;
                fibonacci(n, nBegin);
            } break;

            case 5: {
                int a{ 0 };
                cout << "Введите число: ";
                cin >> a;
                bitPrint(a);
            } break;

            case 6: {
                double a{ 0 };
                cout << "Введите число: ";
                cin >> a;
                bitPrint(a);
            } break;

            default:
                choice = 0;
                cout << "Неверное значение.\n" << endl;
            break;
        }

        if (choice) {
            break;
        }
    }

    return 0;
}
