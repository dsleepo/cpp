#include <iostream>
#include <cmath>

using namespace std;

int main() 
{
    double Principal;
    double IntRate;
    double PayPerYear;
    double NumYears;
    double Payment;
    double numer, denom;
    double b, e;

    cout << "Введите исходную сумма займа: ";
    cin >> Principal;

    cout << "Введите процентную ставка (например, 0.075): ";
    cin >> IntRate;

    cout << "Введите количество выплат в год: ";
    cin >> PayPerYear;

    cout << "Введите срок займа (в годах): ";
    cin >> NumYears;

    numer = IntRate * Principal / PayPerYear;
    e = -(PayPerYear * NumYears);
    b = (IntRate / PayPerYear) + 1;

    denom = 1 - pow(b, e);

    Payment = numer / denom;

    cout << "Размер платежа по займу составляет " << Payment << endl;
    cout << "Всего выплачено " << Payment * PayPerYear * NumYears << endl;

    return 0;
}