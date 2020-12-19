#include <iostream>
using namespace std;

int main()
{
    int num;

    cout << "Введите число от 1 до 3: ";
    cin >> num;

    switch (num) {
        case 1:
            cout << "Один пирог два раза не съешь." << endl;
        break;

        case 2:
            cout << "Двум головом на одних плечах тесно." << endl;
        break;
        
        case 3:
            cout << "Три раза прости, а в четвертый прихворости." << endl;
        break;
        
        default:
            cout << "Вы должны ввести число 1, 2 или 3." << endl;
    }

    return 0;
}
