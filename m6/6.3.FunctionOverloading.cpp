#include <iostream>
using namespace std;

void f(int i);
void f(int i, int j);
void f(double k);

int main()
{
    f(10);
    f(10, 20);
    f(20.0);

    return 0;
}

void f(int i) 
{
    cout << "В функции f(int), i равно " << i << endl;
}

void f(int i, int j)
{
    cout << "В функции f(int, int), i равно " << i << ", j равно " << j << endl;
}

void f(double k)
{
    cout << "В функции f(double), k равно " << k << endl;
}
