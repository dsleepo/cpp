#include <iostream>
using namespace std;

int box(int length, int width, int height);

int main() 
{
    cout << "Объем параллепипеда равен: " << box(10, 11, 3);

    return 0;
}

int box(int length, int width, int height)
{
    return length * width * height;
}
