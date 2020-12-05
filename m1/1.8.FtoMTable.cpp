#include <iostream>
using namespace std;

int main()
{
    double f, m;
    int counter = 0;

    int count = 0;
    
    for (f = 1.0; f <= 100.0; f++) {
        m = f / 3.28;
        cout << f << " футов равно " << m << " метра.\n";
        counter++;
        if (counter == 10) {
            cout << "\n";
            counter = 0;
        }
    }

    return 0;
}