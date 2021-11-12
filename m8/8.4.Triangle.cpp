#include <iostream>
using namespace std;

class Triangle {
    double base, height;
    public:
        Triangle(double b, double h) {
            base = b;
            height = h;
        }
        double hypot() {
            return 0; 
        }
        double area() {
            return base * height / 2;
        }
};

int main()
{
    Triangle triangles[2] = {
        Triangle(1, 2),
        Triangle(2, 4)
    };

    Triangle *t = &triangles[0];

    for (int i = 0; i < 2; i++) {
        cout << t->area() << endl;
        t++;
    }

    return 0;
}