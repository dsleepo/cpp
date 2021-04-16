#include <iostream>
#include <cmath>
using namespace std;

int task1(double x)
{
    double y = 0;

    if (x >= -9 && x < -6) {
        // 1) -9 =< x < -6
        // -9 0
        // -6 3
        y = sqrt(9 - pow(x + 6, 2)) * -1;
    } else if (x >= -6 && x < -3) {
        // 2) -6 =< x < -3
        // -6 -3
        // -3 0
        y = x + 3;
    } else if (x >= -3 && x < 0) {
        // 3) -3 =< x < 0
        // -3 0
        // 0 -3
        y = sqrt(9 - pow(x, 2));
    } else if (x >= 0 && x < 3) {
        // 4) 0 =< x < 3
        // 0 3
        // 3 0
        y = -x + 3;
    } else if (x >= 3 && x <= 9) {
        // 5) 3 =< x < 9
        // 3 0
        // 9 3
        y = (x - 3) / 2;
    }

    cout << "x = " << x << '\t' << "y = " << y << '\n';

    return 0;
}

int task2(double r, double x, double y)
{
    double rx = x, ry = rx; // y = x

    bool hitCircle = pow(x, 2) + pow(y, 2) <= pow(r, 2);
    bool hitTopRight = y >= 0 && y >= ry && x >= 0;
    bool hitBottomLeft = y <= 0 && y <= ry && x <= 0;
    
    if (hitCircle && (hitTopRight || hitBottomLeft)) {
        cout << "Попадание" << endl;
    } else {
        cout << "Мимо" << endl;
    }

    return 0;
}

int main()
{
    // task1(-10); //  0
    // task1(-9);  //  0
    // task1(-6);  // -3
    // task1(-3);  //  0
    // task1(0);   //  3
    // task1(3);   //  0
    // task1(9);   //  3

    double x;
    cout << "Введите x:"; 
    cin >> x;
    task1(x);

    // task2(5, 0, 0); // Попадание
    // task2(5, 0, 5); // Попадание
    // task2(5, 1, 4); // Попадание
    // task2(5, 5, 5); // Мимо
    // task2(5, 0, -5);  // Попадание
    // task2(5, -1, -4); // Попадание
    // task2(5, -5, -5); // Мимо

    double r, x, y;
    cout << "Введите r, координаты x y:"; 
    cin >> r >> x >> y;
    task2(r, x, y);

    return 0;
}