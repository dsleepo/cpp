#include <iostream>

using namespace std;

int main()
{
    cout << 2 << endl;

    for (int i = 3; i < 100; i += 2) {
        bool isSimple = true;

        for (int j = 3; (j * j) <= i; j++) {
            if (i % j == 0) {
                isSimple = false;
                break;
            }
        }

        if (isSimple) cout << i << endl;
    }

    return 0;
}
