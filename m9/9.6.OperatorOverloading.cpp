#include <iostream>
using namespace std;

class ThreeD {
    int x, y, z;

    public:
        ThreeD() { x = y = z = 0; }

        ThreeD(int i, int j, int k) { x = i; y = j; z = k; }

        ThreeD operator+(ThreeD op2);

        ThreeD operator=(ThreeD op2);

        void show();
};

ThreeD ThreeD::operator+(ThreeD op2)
{
    ThreeD temp;
    temp.x = x + op2.x;
    temp.y = y + op2.y;
    temp.z = z + op2.z;

    return temp;
}

ThreeD ThreeD::operator=(ThreeD op2)
{
    x = op2.x;
    y = op2.y;
    z = op2.z;

    return *this;
}

void ThreeD::show()
{
    cout << x << ", " << y << ", " << z << "\n";
}

int main()
{
    ThreeD a(1, 2, 3), b(10, 10, 10), c;

    cout << "Исходнын значения коррдинат a: ";
    a.show();

    cout << "Исходное значение координат b: ";
    b.show();

    cout << "\n";

    c = a + b;
    cout << "Значение координат объекта c после c = a + b: ";
    c.show();

    cout << "\n";
    c = b = a;
    cout << "Значение координта c после c = b = a: ";
    c.show();

    cout << "Значение координта b после c = b = a: ";
    b.show();
    
    
    return 0;
}