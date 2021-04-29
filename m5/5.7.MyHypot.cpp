#include <iostream>
#include <cmath>
using namespace std;

double myHypot(double a, double b);

int main()
{
    cout << hypot(4, 3) << '\n';

    return 0;
}

double myHypot(double a, double b)
{
    return sqrt(a * a + b * b);
}
