#include <iostream>
using namespace std;

int * byThrees();

void reset();

void printNumbers(int size, int *numbers);

int c = -3;
int numbers[3];

int main() 
{
    int *numbers;
    numbers = byThrees(); // 0, 3, 6
    printNumbers(3, numbers);
    numbers = byThrees(); // 9, 12, 15
    printNumbers(3 ,numbers);
    reset();
    numbers = byThrees(); // 0, 3, 6
    printNumbers(3, numbers);

    return 0;
}

int * byThrees()
{
    int size = sizeof(numbers) / sizeof(numbers[0]);

    for (int i = 0; i < size; i++) {
        c += 3;
        numbers[i] = c;
    }

    return numbers;
}

void reset()
{
    c = -3;
    return;
}

void printNumbers(int size, int *numbers) 
{
    for (int i = 0; i < size; i++) {
        if (i != 0) {
            cout << ", ";
        } 
        cout << *numbers;
        numbers++;
    }

    cout << '\n';
}
