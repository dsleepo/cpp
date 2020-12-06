#include <iostream>
#include <cmath>
using namespace std;

int main() 
{
    double x, y, z;

    x = 5;
    y = 4;
    z = sqrt(x*x + y*y);

    cout << "Гипотенуза равна " << z;

    return 0;
}