#include <iostream>
#include <cmath>
using namespace std;

void showBinary(unsigned int i)
{
    long int t;
    int k;

    for (t = pow(2, 31), k = 0; t > 0; t /= 2, k++) {
        cout << (i & t ? '1' : '0');
        if ((k + 1) % 8 == 0) {
            cout << " ";
        }
    }
}

int main()
{   
    showBinary(256);

    return 0;
}
