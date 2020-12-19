#include <iostream>
using namespace std;

int main()
{
    for (int x = 0; x < 6; x++) {
        if (x == 1) {
            cout << "x равен единице." << endl;
        } else if (x == 2) {
            cout << "x равен двум." << endl;
        } else if (x == 3) {
            cout << "x равент трем." << endl;
        } else if (x == 4) {
            cout << "x равен четырем." << endl;
        } else {
            cout << "x не попадает в диапазон от 1 до 4." << endl;
        }
    }

    return 0;
}
