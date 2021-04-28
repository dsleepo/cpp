#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char str[] = "Это простой тест";
    char *start, *end;
    int len;
    char t;

    cout << "Исходная строка: " << str << endl;

    len = strlen(str);
    start = str;
    end = &str[len-1];

    while (start < end) {
        t = *start;
        *start = *end;
        *end = t;

        start++;
        end--;
    }

    cout << "Строка после реверсирования: " << str << endl;

    return 0;
}