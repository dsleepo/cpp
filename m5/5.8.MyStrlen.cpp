#include <iostream>
using namespace std;

int myStrlen(char *str);

int main()
{
    char strs[][16] = {
        "first string",  // 12
        "second string", // 13
        "third string",  // 12
    };

    int size = sizeof(strs) / sizeof(strs[0]);
    for (int i = 0; i < size; i++) {
        cout << myStrlen(strs[i]) << '\n';
    }

    return 0;
}

int myStrlen(char *str)
{
    int i = 0;
    while (*str) {
        i++;
        str++;
    }
    
    return i;
}
