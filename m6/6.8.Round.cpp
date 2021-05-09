#include <iostream>
#include <cmath>
using namespace std;

void round2(double *value)
{
    double integral;
    double fractional = modf(*value, &integral);
    cout << integral << " " << fractional << endl;
    
    if (fractional > 0) {
        *value = fractional >= 0.5 ? integral + 1: integral;
    } else {
        *value = fractional >= -0.5 ? integral : integral - 1;
    }
}

int main()
{
    double a[]{ 
        4.4,   // 4
        4.5,   // 5
        -4.5,  // -4
        -4.51, // -5
    };

    for (int i = 0, j = sizeof(a) / sizeof(a[0]); i < j; i++) {
        double *p = &a[i];
        double o = *p;
        round2(p);
        cout << "o: " << o << ", *p: " << *p << endl;
    }

    return 0;
}
