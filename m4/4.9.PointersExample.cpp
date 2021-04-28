#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    char *p;
    char str[80] = "This Is A Test";

    cout << "Исходная строка: " << str << endl;
    p = str;

    while (*p) {
        if (isupper(*p)) {
            *p = tolower(*p);
        } else if (islower(*p)) {
            *p = toupper(*p);
        }
        p++;
    }

    cout << "Строка с инвертированным регистром букв: " << str;

    return 0;
}