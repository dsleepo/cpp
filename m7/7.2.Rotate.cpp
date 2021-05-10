#include <iostream>
using namespace std;

unsigned char lrorate(unsigned char val, int n)
{
    unsigned int t{ val };

    for (int i = 0; i < n; i++) {
        t = t << 1;

        if (t & 256) {
            t = t | 1;
        }
    }

    return t;
}

unsigned char rrotate(unsigned char val, int n)
{
    unsigned int t { val };

    t = val;

    t = t << 8;

    for (int i = 0; i < n; i++) {
        t = t >> 1;
        if (t & 128) {
            t = t | 32768;
        }
    }

    t = t >> 8;

    return t;
}

void showBinary(unsigned int u)
{
    int t;

    for (t = 128; t > 0; t /= 2) {
        if (u & t) {
            cout << "1 ";
        } else {
            cout << "0 ";
        }
    }

    cout << '\n';
}

int main()
{
    char ch = 'T';

    cout << "Исходное значение в двоичном коде:\n";
    showBinary(ch);

    cout << "Результат 8-кратного циклического сдвига вправо:\n";
    for (int i = 0; i < 8; i++) {
        ch = rrotate(ch, 1);
        showBinary(ch);
    }

    cout << "Результат 8-кратного циклического сдвига влево:\n";
    for (int i = 0; i < 8; i++) {
        ch = rrotate(ch, 1);
        showBinary(ch);
    }

    return 0;
}
