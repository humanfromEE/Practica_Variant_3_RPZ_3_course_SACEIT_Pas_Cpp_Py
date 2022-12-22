#include <iostream>

#include <windows.h>
#include <conio.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int NumberMonth;
    cout << "Введіть номер місяця: ";
    cin >> NumberMonth;

    //case
    cout << "Конструкція case:" << "\n" << "\t";
    switch (NumberMonth)
    {
        case 12:
        case 1:
        case 2:
            cout << "Зима" << "\n";
            break;
            
        case 3:
        case 4:
        case 5:
            cout << "Весна" << "\n";
            break;

        case 6:
        case 7:
        case 8:
            cout << "Літо" << "\n";
            break;

        case 9:
        case 10:
        case 11:
            cout << "Осінь" << "\n";
            break;

        default:
            cout << "Задане число не є місяцем" << "\n";
            break;
    }

    //if
    cout << "Конструкція if:" << "\n" << "\t";
    if( (NumberMonth == 12) || (NumberMonth == 1) || (NumberMonth == 2) ) 
    {
        cout << "Зима" << "\n";
    }
    else if( (NumberMonth >= 3) && (NumberMonth <= 5) )
    {
        cout << "Весна" << "\n";
    }
    else if ( (NumberMonth >= 6) && (NumberMonth <= 8) )
    {
        cout << "Літо" << "\n";    
    }
    else if( (NumberMonth >= 9) && (NumberMonth <= 11) )
    {
        cout << "Осінь" << "\n";
    }
    else
    {
        cout << "Задане число не є місяцем" << "\n";
    }

    getch();

    return 0;
}