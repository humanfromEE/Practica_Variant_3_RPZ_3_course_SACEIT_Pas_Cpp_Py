#include <iostream>
#include <cmath>

#include <windows.h>
#include <conio.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //у прикладі не задовільне ОДЗ для заданого діапазону, я долучив для наглядності до числа логарифму модуль
    
    double Xmin = 7.5, Xmax = 10, Xstep = 0.5, x = Xmin, y;

    //використання if (за допомогою goto)
    cout << "Використання if (за допомогою goto):" << "\n";
    IF:
        if(x <= Xmax)
        {
            y = log10(  fabs( (1 - x) / (1 + x) ) );
            cout << "\t" << "x: " << x << " => " << "y: " << y << "\n";

            x = x + Xstep;

            goto IF;
        }
        

    //використання циклу while
    cout << "\n\n" << "Використання циклу while:" << "\n";

    x = Xmin;
    
    while(x <= Xmax)
    {
        y = log10(  fabs( (1 - x) / (1 + x) ) );
        cout << "\t" << "x: " << x << " => " << "y: " << y << "\n";

        x = x + Xstep;
    }

    
    //використання циклу do - while
    cout << "\n\n" <<  "Використання циклу do - while:" << "\n";

    x = Xmin;
    
    do
    {
        y = log10(  fabs( (1 - x) / (1 + x) ) );
        cout << "\t" << "x: " << x << " => " << "y: " << y << "\n";

        x = x + Xstep;
    }
    while(x <= Xmax);

    //використання циклу for
    cout << "\n\n" << "Використання циклу for:" << "\n";

    for(x = Xmin; x <= Xmax; x = x + Xstep)
    {
        y = log10(  fabs( (1 - x) / (1 + x) ) );
        cout << "\t" << "x: " << x << " => " << "y: " << y << "\n";
    }

    getch();

    return 0;
}