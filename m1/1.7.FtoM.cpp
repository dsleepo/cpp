#include <iostream>
using namespace std;

int main()
{
    double f, m;

    cout << "Введите длину в футах: ";
    cin >> f;

    m = f / 3.28;

    cout << f << " футов равно " << m << " метрам.\n";

    return 0;
}