#include <iostream>
using namespace std;

int main()
{
    double distance, lightspeed, delay, delay_in_min;

    distance = 34000000.0;
    lightspeed = 186000.0;

    delay = distance / lightspeed;

    cout << "Временная задержка при разговоре с Марсом: " << delay << " секунд." << endl;

    delay_in_min = delay / 60;

    cout << "Это составляет " << delay_in_min << " минут." << endl;

    return 0;
}