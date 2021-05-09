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
