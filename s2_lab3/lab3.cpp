#include <iostream>
#include <cmath>
using namespace std;

void task1()
{
    int number;
    cout << "Введите число: ";
    cin >> number;
    int i{ 0 };

    if (number < 1 || (number != 1 && number % 2 != 0)) {
        cout << "Не степень двойки." << endl;
        return;
    } 

    while (number / 2) {
        number /= 2;
        i++;
    }

    cout << i << endl;
}

void task2_1()
{
    int n;
    cout << "Введите число: ";
    cin >> n;

    if (n < 0) {
        cout << "n >= 0";
        return;
    }

    double s{ 0 };
    for (int i = 1; i <= n; i++) {
        s += 1.0 / i;
    }

    cout << "Сумма " << n << " членов ряда: " << s << endl;
}

void task2_2()
{
    int n;
    cout << "Введите число: ";
    cin >> n;

    if (n < 0) {
        cout << "n >= 0";
        return;
    }

    double s{ 0 };
    for (int i = 1; i <= n; i++) {
        s += 1.0 / pow(i, 2);
    }

    cout << "Сумма " << n << " членов ряда: " << s << endl;
}

void task3()
{
    int a{ 0 }, b { 0 };

    cout << "Введите а: ";
    cin >> a;
    
    cout << "Введите b: ";
    cin >> b;

    a = abs(a);
    b = abs(b);

    if (a != 0 && b != 0) {
        while (a != b) {
            if (a > b) {
                a -= b;
            } else {
                b -= a;
            }
        }
    }

    cout << a << endl; 
}

int main()
{
    // -2 - Не степень двойки
    // 0  - Не степень двойки
    // 1  - 0
    // 2  - 1
    // 3  - Не степень двойки
    // 4  - 2 
    task1();  

    // -2 - n >= 0
    // 0  - 0
    // 1  - 1
    // 2  - 1.5
    // 3  - 1.83333
    task2_1();

    // -2 - n >= 0
    // 0  - 0
    // 1  - 1
    // 2  - 1.25
    // 3  - 1.36111
    task2_2();

    // 5,   5 - 5
    // 5,  10 - 5
    // 10,  5 - 5
    // 2,   7 - 1
    // 0,   0 - 0
    // 0,  -2 - 0
    // -3, -6 - 3 
    task3();

    return 0;
}
