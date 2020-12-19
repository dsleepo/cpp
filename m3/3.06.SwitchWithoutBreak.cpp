#include <iostream>
using namespace std;

int main()
{
    int i;

    for (int i = 0; i < 5; i++) {
        switch (i) {
            case 0:
                cout << "меньше 1" << endl;
            
            case 1:
                cout << "меньше 2" << endl;

            case 2:
                cout << "меньше 3" << endl;

            case 3:
                cout << "меньше 4" << endl;

            case 5:
                cout << "меньше 5" << endl;
        }

        cout << endl;
    }

    return 0;
}
