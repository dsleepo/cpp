#include <iostream>
using namespace std;


void repeat(char *str, char ch = ' ', int spaces = 0)
{
    if (spaces < 0) {
        spaces = 0;
    }

    for (int i = 0; i < spaces; i++) {
        str[i] = ch;
    }
}

void print(bool var, int spaces = 0)
{
    char str[spaces + 1] = "";
    repeat(str, ' ', spaces);
    cout << "bool (" << sizeof(str) - 1 << ") " << str << (var ? "true" : "false");
}

void print(char var, int spaces = 0)
{
    char str[spaces + 1] = "";
    repeat(str, ' ', spaces);
    cout << "char (" << sizeof(str) - 1 << ") " << str << var;
}

void print(int var, int spaces = 0)
{   
    char str[spaces + 1] = "";
    repeat(str, ' ', spaces);
    cout << "int (" << sizeof(str) - 1 << ") " << str << var;
}

void print(long var, int spaces = 0)
{
    char str[spaces + 1] = "";
    repeat(str, ' ', spaces);
    cout << "long (" << sizeof(str) - 1 << ") " << str << var;
}

void print(char *var, int spaces = 0)
{
    char str[spaces + 1] = "";
    repeat(str, ' ', spaces);
    cout << "char* (" << sizeof(str) - 1 << ") " << str << var;
}

void print(double var, int spaces = 0)
{
    char str[spaces + 1] = "";
    repeat(str, ' ', spaces);
    cout << "double (" << sizeof(str) - 1 << ") " << str << var;
}

void printLn(bool var, int spaces = 0)
{
    print(var, spaces);
    cout << '\n';
}

void printLn(char var, int spaces = 0)
{
    print(var, spaces);
    cout << '\n';
}

void printLn(int var, int spaces = 0)
{
    print(var, spaces);
    cout << '\n';
}

void printLn(long var, int spaces = 0)
{
    print(var, spaces);
    cout << '\n';
}

void printLn(char *var, int spaces = 0)
{
    print(*var, spaces);
    cout << '\n';
}

void printLn(double var, int spaces = 0)
{
    print(var, spaces);
    cout << '\n';
}

int main()
{
    printLn(true, 1);
    printLn('1', 2);
    printLn(1, 3);
    printLn(1L, 4);

    char varStr[] = "1234";
    printLn(varStr, 5);
    printLn(1.0, 6);

    return 0;
}
