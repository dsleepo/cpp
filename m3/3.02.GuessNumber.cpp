#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int magic, guess;

    magic = rand();

    cout << "Введите свой вариант магического числа: ";
    cin >> guess;

    if (guess == magic) {
        cout << "** Правильно **" << endl;
        cout << magic << " и есть то самое магическое число" << endl;
    } else {
        cout << "...Очень жаль, но вы ошиблись." << endl;
        if (guess > magic) {
            cout << " Ваш вариант больше магического числа." << endl;
        } else {
            cout << " Ваш вариант меньше магического числа." << endl;
        }
    }

    return 0;
}
