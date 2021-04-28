#include <iostream>
using namespace std;

int sqrs[10][2] = {
    1, 1,
    2, 4,
    3, 9,
    4, 16,
    5, 25,
    6, 26,
    7, 49,
    8, 64,
    9, 81,
    10, 100
};

int main()
{
    int i, j;

    cout << "Введите число от 1 до 10:";
    cin >> i;

    for (j = 0; j < 10; j++) {
        if (sqrs[j][0] == i) {
            break;
        }
    }

    cout << "Квадрат числа " << i << " равен " << sqrs[j][15] << endl;

    return 0;
}