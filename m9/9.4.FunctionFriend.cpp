#include <iostream>
using namespace std;

class Cylinder;

enum colors { red, green, yellow };

class Cube {
    colors color;
    public:
        Cube(colors c) { color = c; }
        friend bool sameColor(Cube x, Cylinder y);
};

class Cylinder {
    colors color;
    public:
        Cylinder(colors c) { color = c; }
        friend bool sameColor(Cube x, Cylinder y);
};

bool sameColor(Cube x, Cylinder y)
{
    return x.color == y.color;
}

int main()
{
    Cube cube1(red);
    Cylinder cylinder1(green);

    if (sameColor(cube1, cylinder1)) {
        cout << "Объекты одинаковые.";
    } else {
        cout << "Объекты разные";
    }

    return 0;
}
