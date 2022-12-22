#include <iostream>

#include <windows.h>
#include <conio.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    double y = 0;
    int i, j;
    long long int factorial;

    //використання if (за допомогою goto)
    cout << "Використання if (за допомогою goto):" << "\n";

    i = 1;

    IF: //розрахунок ряду
        factorial = 1;
        j = 1;

        FACTORIAL: //розрахунок факторіалу
            if(j <= i) 
            {
                factorial = factorial * j;
                j = j + 1;

                goto FACTORIAL;
            }

        if(i <= 10)
        {
            y = y + 1.0 / factorial;
            cout << "\t" << "i: " << i << " => " << "факторіал: " << factorial << " => " << "y: " << y << "\n";
            i = i + 1;

            goto IF;
        }


    //використання циклу while
    cout << "\n\n" << "Використання циклу while:" << "\n";

    i = 1;
    y = 0;

    while(i <= 10) //розрахунок ряду
    {
        factorial = 1;
        j = 1;

        while(j <= i) //розрахунок факторіалу
        {
            factorial = factorial * j;
            j = j + 1;
        }

        y = y + 1.0 / factorial;
        cout << "\t" << "i: " << i << " => " << "факторіал: " << factorial << " => " << "y: " << y << "\n";
        i = i + 1;
    }


    //використання циклу do - while
    cout << "\n\n" << "Використання циклу do - while:" << "\n";

    i = 1;
    y = 0;

    do //розрахунок ряду
    {
        factorial = 1;
        j = 1;

        do //розрахунок факторіалу
        {
            factorial = factorial * j;
            j = j + 1;
        }
        while(j <= i);

        y = y + 1.0 / factorial;
        cout << "\t" << "i: " << i << " => " << "факторіал: " << factorial << " => " << "y: " << y << "\n";
        i = i + 1;
    }
    while(i <= 10);


    //використання циклу for
    cout << "\n\n" << "Використання циклу for:"<< "\n";

    y = 0;
    
    for(i = 1; i <= 10; i = i + 1) //розрахунок ряду
    {
        factorial = 1;

        for(j = 1; j <= i; j = j + 1) //розрахунок факторіалу
        {
            factorial = factorial * j;
        }

        y = y + 1.0 / factorial;
        cout << "\t" << "i: " << i << " => " << "факторіал: " << factorial << " => " << "y: " << y << "\n";
    }

    getch();

    return 0;
}