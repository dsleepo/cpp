#include <iostream>
using namespace std;

int main()
{
    int length, width; 

    cout << "Введите длину прямоугольника: ";
    cin >> length;

    cout << "Введите ширину прямоугольника: ";
    cin >> width;

    cout << "Площадь прямоугольника равна " << length * width;

    return 0;
}