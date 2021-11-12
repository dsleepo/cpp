#include <iostream>
using namespace std;

class Sample {
    public:
    int x, y;

    Sample() {
        x = y = 0;
    }

    Sample(int x, int y) {
        this->x = x;
        this->y = y;
    }
};


int main()
{
    Sample t;
    Sample t1(1, 2);

    cout << "t.x: "  << t.x << ", t.y: " << t.y << "\n";
    cout << "t1.x: "  << t1.x << ", t1.y: " << t1.y << "\n";

    return 0;
}
