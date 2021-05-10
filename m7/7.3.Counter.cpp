#include <iostream>
using namespace std;

int counter()
{
    static int i{ 0 };
    return ++i;
}

int main()
{
    cout << counter() << '\n';
    cout << counter() << endl;

    return 0;
}
