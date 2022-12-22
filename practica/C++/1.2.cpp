#include <iostream>
#include <cmath>

#include <windows.h>
#include <conio.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Введіть координати точки M1:" << "\n";
    double x1, y1;
    cout << "\t" << "x1: ";
    cin >> x1;
    cout << "\t" << "y1: ";
    cin >> y1;
    
    cout << "Введіть координати точки M2:" << "\n";
    double x2, y2;
    cout << "\t" << "x2: ";
    cin >> x2;
    cout << "\t" << "y1: ";
    cin >> y2;

    //розрахунок відстані
    double d = pow( ( pow( (x2 - x1), 2) + pow( (y2 - y1), 2) ), 1.0 / 2);
    cout << "Відстань між точками рівна d: " << d << "\n";

    //розрахунок формули
    double y = ( pow( sin(x2 + x1), 2) + cos( fabs(x2 - y2) ) ) / ( cos(d) + pow( ( 4.75 + 3.2 * pow(d, 2) ), 1.0 / 2) ); 
    cout << "Розрахунок формули рівний y: " << y << "\n";

    getch();

    return 0;
}