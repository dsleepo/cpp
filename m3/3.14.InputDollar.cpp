#include <iostream>
using namespace std;

int main()
{
    string input;

    for (;;) {
        cout << "Введите: ";
        cin >> input;

        bool dollarFound = false;
        int dotsCount = 0;

        for (int i = 0; i < input.size(); i++) {
            if (input[i] == '$') {
                dollarFound = true;
            }
            if (input[i] == '.') {
                dotsCount++;
            }
        }

        if (dollarFound) {
            cout << "$ найден. точек - " << dotsCount << endl;
            break;
        }

        cout << "$ не найден. точек - " << dotsCount << endl;
    }

    return 0;
}
