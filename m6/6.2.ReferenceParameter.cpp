#include <iostream>
using namespace std;

void swap(int &a, int &b);

int main()
{
    int a{ 1 }, b{ 2 };

    swap(a, b);

    cout << "Значение переменных a и b после обмена " << a << " " << b << endl;

    return 0;
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
