#include <iostream>
using namespace std;

union u_type {
    u_type(short int a) { i = a; }
    u_type(char x, char y) { 
        ch[0] = x;
        ch[1] = y;
    }

    void showChars() {
        cout << ch[0] << " " << ch[1] << "\n";
    }

    short int i;
    char ch[2];
};

int main()
{
    u_type u(1000);
    u_type u2('X', 'Y');

    cout << "Объединение u в качестве целого числа: " << u.i << "\n";
    cout << "Объединение u в качестве двух символов: ";
    u.showChars();
    cout << "\n";

    cout << "Объединение u2 в качестве целого числа: " << u2.i << "\n";
    cout << "Объединение u2 в качестве двух символов: ";
    u2.showChars();
    cout << "\n";

    return 0;
}