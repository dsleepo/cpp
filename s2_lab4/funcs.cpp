#include <iostream>
#include "funcs.h"

int min(int a, int b, int c, int d)
{
    int numbers[] = { a, b, c, d };
    int min{ a };

    for (int i = 1; i < 4; i++) {
        if (min > numbers[i]) {
            min = numbers[i];
        }
    }

    return min;
}

int even(int a, int b, int c, int d)
{
    int even{ 0 };

    if (a % 2 == 0) even++;
    if (b % 2 == 0) even++;
    if (c % 2 == 0) even++;
    if (d % 2 == 0) even++;

    return even;
}

double average(int a, int b, int c, int d)
{
    return static_cast<double>(a + b + c + d) / 4;
}

void fibonacci(int num, int nBegin)
{
    if (num < 0 || nBegin < 0) {
        return;
    }

    int f{ 0 }, fp{ 0 };
    for (int i = 1, j = nBegin + num; i <= j; i++) {
        if (i == 1 || i == 2) {
            f = 1; 
            fp = i - 1;
        } else {
            int temp = f;
            f = f + fp;
            fp = temp;
        }

        if (i >= nBegin) {
            std::cout << i << " " << f << std::endl;
        }
    }
}

void bitPrint(int i) 
{
    char *ip{ (char *) &i } ;
    for (int byte = sizeof(i) - 1; byte >= 0; byte--) {
        for (int bit = 7; bit >= 0; bit--) {
            std::cout << (((ip[byte]) >> bit) & 1);
        }
        std::cout << " ";
    }
    std::cout << std::endl;
}

void bitPrint(double i)
{
    char *ip{ (char *) &i } ;
    for (int byte = sizeof(i) - 1; byte >= 0; byte--) {
        for (int bit = 7; bit >= 0; bit--) {
            std::cout << (((ip[byte]) >> bit) & 1);
        }
        std::cout << " ";
    }
    std::cout << std::endl;
}
