#include <iostream>
using namespace std;

int main()
{
    int total;
    int *ptr;
    int val;

    total = 3200;
    ptr = &total;
    val = *ptr;

    cout << "Значение переменной val: " << val << endl;

    return 0;
}