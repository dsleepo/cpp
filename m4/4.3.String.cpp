#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    char s1[80], s2[80];

    strcpy(s1, "C++");
    strcpy(s2, " - это мощный язык");

    cout << "Длины строк: " << strlen(s1);
    cout << " " << strlen(s2) << endl;

    if (!strcmp(s1, s2)) {
        cout << "Эти строки равны." << endl;
    } else {
        cout << "Эти строки не равны." << endl;
    }

    strcat(s1, s2);
    cout << s1 << endl;

    strcpy(s2, s1);
    cout << s1 << " и " << s2 << endl;

    if (!strcmp(s1, s2)) {
        cout << "Строки s1 и s2 теперь одинаковы.\n"; 
    }

    return 0;
}