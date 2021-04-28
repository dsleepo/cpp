#include <iostream>
#include <cstdio>
using namespace std;


int main() 
{
    char string1[80];
    char string2[80];

    cout << "String 1: ";
    fgets(string1, 80, stdin);

    cout << "String 2: ";
    fgets(string2, 80, stdin);

    char *i = string1;
    char *j = string2;

    bool equals = true;
    while (*i || *j) {
        if (tolower(*i) != tolower(*j)) {
            equals = false;
            break;
        }
        i++;
        j++;
    }

    cout << (equals ? "Equals" : "Not equals");
    
    return 0;
}
