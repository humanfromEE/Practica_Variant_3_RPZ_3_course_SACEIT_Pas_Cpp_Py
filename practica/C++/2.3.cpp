#include <iostream>

#include <windows.h>
#include <conio.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int NumberMonth;
    cout << "������ ����� �����: ";
    cin >> NumberMonth;

    //case
    cout << "����������� case:" << "\n" << "\t";
    switch (NumberMonth)
    {
        case 12:
        case 1:
        case 2:
            cout << "����" << "\n";
            break;
            
        case 3:
        case 4:
        case 5:
            cout << "�����" << "\n";
            break;

        case 6:
        case 7:
        case 8:
            cout << "˳��" << "\n";
            break;

        case 9:
        case 10:
        case 11:
            cout << "����" << "\n";
            break;

        default:
            cout << "������ ����� �� � ������" << "\n";
            break;
    }

    //if
    cout << "����������� if:" << "\n" << "\t";
    if( (NumberMonth == 12) || (NumberMonth == 1) || (NumberMonth == 2) ) 
    {
        cout << "����" << "\n";
    }
    else if( (NumberMonth >= 3) && (NumberMonth <= 5) )
    {
        cout << "�����" << "\n";
    }
    else if ( (NumberMonth >= 6) && (NumberMonth <= 8) )
    {
        cout << "˳��" << "\n";    
    }
    else if( (NumberMonth >= 9) && (NumberMonth <= 11) )
    {
        cout << "����" << "\n";
    }
    else
    {
        cout << "������ ����� �� � ������" << "\n";
    }

    getch();

    return 0;
}