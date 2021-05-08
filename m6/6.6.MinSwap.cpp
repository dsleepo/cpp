#include <iostream>
using namespace std;

int *minSwap(int *a, int *b) 
{
    int temp{ *a };
    *a = *b;
    *b = temp;

    return *a < *b ? a : b;
}

int main()
{
    int a = 2, b = 1;
    int *aa = &a;
    int *bb = &b;
    int *c = minSwap(aa, bb);

    cout << "a " << a << ", b " << b << ", c " << *c << endl;

    return 0;
}
