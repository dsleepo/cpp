#include <iostream>
using namespace std;

int main()
{
    int x = 128;
    short int y = 0;
    char ch;
    float f = 3.2;

    ch = x; // int -> char 
    cout << "ch = " << static_cast<int>(ch) << endl; // ch = -128

    x = f; // f -> int 
    cout << "x  = " << x << endl; // x = 3

    f = ch; // char -> float 
    cout << "f  = " << f << endl; // f = -128

    f = x; // int -> float 
    cout << "f  = " << f << endl; // f = 3

    cout << "x / 2 = " << (float) x / 2 << endl; // x / 2 = 1.5

    return 0;
}