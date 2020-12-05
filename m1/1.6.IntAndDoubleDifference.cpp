#include <iostream>
using namespace std;

int main()
{
   int ivar = 100;
   double dvar = 100.0;

    cout << "Исходное значение переменной ivar: " << ivar << "\n";

    cout << "Исходное значение переменной dvar: " << dvar << "\n\n";
    
    ivar = ivar / 3;
    dvar = dvar / 3;

    cout << "Значение ivar после деления: " << ivar << "\n";
    cout << "Значение dvar после деления: " << dvar << "\n";

    return 0;
}