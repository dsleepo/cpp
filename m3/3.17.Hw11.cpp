#include <iostream>
using namespace std;

int main()
{
    char symbol;
    int changes;
    string input;

    cout << "Введите: ";
    for (;;) {
        cin >> symbol;
        cout << "iter" << endl;

        if (symbol >= 'A' && symbol <= 'Z') {
            symbol += 32;
            changes++;
        }

        if (symbol >= 'a' && symbol <= 'z') {
            symbol -= 32;
            changes++;
        }

        input += symbol;
        if (symbol == '.') {
            break;
        }
    }

    cout << endl << "изменено: " << changes;
  
    return 0;
}
