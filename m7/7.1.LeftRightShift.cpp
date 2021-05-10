#include <iostream>
using namespace std;

void showBinary(unsigned int u);

int main()
{
    int i{ 255 }, t;
    
    for (t = 0; t < 8; t++) {
        showBinary(i);
        i = i << 1;
    }
    cout << '\n';

    for (t = 0; t < 8; t++) {
        i = i >> 1;
        showBinary(i);
    }

    cout << sizeof(i) << endl;

    return 0;
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
