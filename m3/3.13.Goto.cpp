#include <iostream>
using namespace std;

int main()
{
    int x = 1;
    
    loop1:
        cout << x << " ";
        x++;
        if (x < 100) goto loop1;

    return 0;
}
