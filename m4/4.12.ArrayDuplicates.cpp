#include <iostream>
using namespace std;

void arraySolution()
{
    int numbers[] = { 1, 2, 3, 4, 5, 6, 7, 1, 2, 3 };
    int size = sizeof(numbers) / sizeof(numbers[0]);

    for (auto i = 0, maxI = size / 2; i < maxI; i++) {
        for (auto j = maxI; j < size; j++) {
            if (numbers[i] == numbers[j]) {
                cout << numbers[i] << '\n';
            }
        }
    }
}

void pointerSolution()
{
    int numbers[] = { 1, 2, 3, 4, 5, 6, 7, 1, 2, 3 };
    int *ip = numbers;
    int size = sizeof(numbers) / sizeof(numbers[0]);

    for (auto i = 0, maxI = size / 2; i < maxI; i++, ip++) {
        for (auto j = maxI; j < size; j++) {
            int *jp = &numbers[j];
            if (*jp == *ip) {
                cout << *jp << '\n';
            }
        }
    }
}

int main()
{
    cout << "array:\n";
    arraySolution();
    cout << "pointer:\n";
    pointerSolution();

    return 0;
}

