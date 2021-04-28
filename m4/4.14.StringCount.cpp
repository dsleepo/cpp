#include <iostream>
#include <cstdio>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    char string1[81];

    cout << "Введите строку: ";
    fgets(string1, 80, stdin);

    unsigned short int uppercaseCount = 0;
    char *c = string1;

    while (*c) {
        if (isupper(*c)) {
            uppercaseCount++;
        }
        c++;
    }
    
    cout << "Uppercase letters - " << uppercaseCount << '\n';

    return 0;
}