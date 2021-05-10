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

void stringChiper(char *str, int n) 
{
    char *c = str;

    while (*str) {
        *str = lrorate(*str, n);
        cout << *str;
        str++;
    }

    cout << '\n';

    while (*c) {
        *c = rrotate(*c, n);
        cout << *c;
        c++;
    }
}

int main()
{
    char str[] = "abcdef";
    stringChiper(str, 2);

    return 0;
}
