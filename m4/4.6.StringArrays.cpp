#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int i;
    char str[80];
    char numbers[][80] = {
        "Том", "555-3322",
        "Мария", "555-8976",
        "Джон",  "555-1037",
        "Раиса", "555-1400",
        "Шура", "555-8873",
    };

    cout << "Введите имя: ";
    cin >> str;

    for (i = 0; i < 10; i+2) {
        if (!strcmp(str, numbers[i])) {
            cout << "Телефонный номер: " << numbers[i+1] << endl;
            break; 
        }
    }

    if (i == 10) {
        cout << "Отсутствует в каталоге.\n";
    }

    return 0;
}