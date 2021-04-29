#include <iostream>
using namespace std;

char *getSubstr(char *sub, char *str);

int main()
{
    char *substr;
    char string1[] = "three";
    char string2[] = "one two three four";
    
    substr = getSubstr(string1, string2);
    cout << "Заданная строка найдена: " << substr;

    return 0;
}

char *getSubstr(char *sub, char *str)
{
    int t;
    char *p, *p2, *start;

    for (t = 0; str[t]; t++) {
        p = &str[t];
        start = p;
        p2 = sub;
        while (*p2 && *p == *p2) {
            p++;
            p2++;
        }

        if (!*p2) {
            return start;
        }
    }

    return 0;
}
