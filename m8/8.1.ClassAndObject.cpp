#include <iostream>
using namespace std;

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
        int getPassengers() { return passengers; }
        int getFuelcap() { return fuelcap; }
        int getMpg() { return mpg; }
        int range() { return fuelcap * mpg; }
};

int main()
{
    Vehicle minivan(7, 14, 12);
    Vehicle sportscar(2, 14, 12);

    cout << "Минифургон может перевезти " << minivan.getPassengers() 
         << " пассажиров на расстояиние " << minivan.range()
         << " километров." << "\n";

    cout << "Спортивный автомобиль может перевезти " <<  sportscar.getPassengers() 
         << " пассажиров на расстояиние " << sportscar.range() 
         << " километров." << "\n";

    return 0;
}
