#include <iostream>
#include <cmath>

#include <windows.h>
#include <conio.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Введіть х: ";
    double x;
    cin >> x;

    const double pi = 3.14; //число пі

    //розрахунок параметрів
    double a = pow( (3 * log(7)), 1.0 / 2), b = tan(pi / 3), c = exp(-2);
    cout 
        << "\n" << "Значення параметрів:" << "\n"
        << "\t" << "a = " << a << "\n"
        << "\t" << "b = " << b << "\n"
        << "\t" << "c = " << c << "\n\n";

    double y;
        
    if(x > a) //умови завдання
    {
        y = atan( pow(2, x) ) + a * log(b * c);
        cout << "Розрахунок формули х > a, y: " << y << "\n";
    }
    else if(x == a)
    {
        y = exp(x - b) + log( pow( (a * c), 1.0 / 2) );
        cout << "Розрахунок формули х == a, y: " << y << "\n";
    }
    else
    {
        y = pow( ( pow(a, 2) + pow(b, 2) ), 1.0 / 3) + exp(x - c) * log(x);
        cout << "Розрахунок формули х < a, y: " << y << "\n";
    }

    getch();

    return 0;
}