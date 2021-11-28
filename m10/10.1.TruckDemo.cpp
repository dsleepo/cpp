#include <iostream>

class Vehicle {
    int passengers;
    int fuelcap;
    int mpg;

    public:
        Vehicle(int p, int f, int m) {
            passengers = p;
            fuelcap = f;
            mpg = m;
        }

        int range() { return mpg * fuelcap; }

        int getPassengers() { return passengers; }

        int getFuelcap() { return fuelcap; }

        int getMpg() { return mpg; }
};

class Truck : public Vehicle {
    int cargocap;

    public:
        Truck(int p, int f, int m, int c) : Vehicle(p, f, m) {
            cargocap = c;
        }

        int getCargocap() { return cargocap; }
};

int main()
{
    Truck semi(2, 200, 7, 44000);
    Truck pickup(3, 28, 15, 2000);
    int dist = 252;

    std::cout << "Полуторка может перевезти " << semi.getCargocap() << " фунтов груза.\n";
    std::cout << "После заправки она может проехать максимум " << semi.range() << " километров.\n";
    std::cout << "ЧТобы проехть " << dist << " километра, полуторке необходимо " << dist / semi.getMpg() << " литров топлива.\n\n";

    std::cout << "Пикап может перевезти " << pickup.getCargocap() << " фунтов груза.\n";
    std::cout << "После заправки он может проехать максимум " << pickup.range() << " километров.\n\n";
    std::cout << "Чтобы проехать " << dist << " километра, пикапу необходимо " << dist / pickup.getMpg() << " литров топлива.\n\n";

    return 0;
}
