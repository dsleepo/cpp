#include <iostream>
using namespace std;

void printNumber(int number, int max);

int main()
{
    printNumber(1, 10);

    return 0;
}

void printNumber(int number, int max)
{
    if (number <= max) {
        cout << number << '\n';
        printNumber(number + 1, max);
    }

    return;
}
