#include <iostream>
using namespace std;

void a(short a)
{
    cout << "a1";
}

void a(short a, int b = 10)
{
    cout << "a2";
}

int main()
{
    a(static_cast<short>(10));

    return 0;
}
