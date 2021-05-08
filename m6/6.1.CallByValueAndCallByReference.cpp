#include <iostream>
using namespace std;

void swap(int *a, int *b);

int main()
{
    int i{ 1 }, j{ 2 };

    swap(&i, &j);

    cout << "Значение переменных i и j после обмена " << i << " " << j << endl;

    return 0;
}

void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
