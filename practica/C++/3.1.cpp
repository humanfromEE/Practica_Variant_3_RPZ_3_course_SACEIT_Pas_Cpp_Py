#include <iostream>
#include <cmath>

#include <windows.h>
#include <conio.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //� ������� �� ��������� ��� ��� �������� ��������, � ������� ��� ���������� �� ����� ��������� ������
    
    double Xmin = 7.5, Xmax = 10, Xstep = 0.5, x = Xmin, y;

    //������������ if (�� ��������� goto)
    cout << "������������ if (�� ��������� goto):" << "\n";
    IF:
        if(x <= Xmax)
        {
            y = log10(  fabs( (1 - x) / (1 + x) ) );
            cout << "\t" << "x: " << x << " => " << "y: " << y << "\n";

            x = x + Xstep;

            goto IF;
        }
        

    //������������ ����� while
    cout << "\n\n" << "������������ ����� while:" << "\n";

    x = Xmin;
    
    while(x <= Xmax)
    {
        y = log10(  fabs( (1 - x) / (1 + x) ) );
        cout << "\t" << "x: " << x << " => " << "y: " << y << "\n";

        x = x + Xstep;
    }

    
    //������������ ����� do - while
    cout << "\n\n" <<  "������������ ����� do - while:" << "\n";

    x = Xmin;
    
    do
    {
        y = log10(  fabs( (1 - x) / (1 + x) ) );
        cout << "\t" << "x: " << x << " => " << "y: " << y << "\n";

        x = x + Xstep;
    }
    while(x <= Xmax);

    //������������ ����� for
    cout << "\n\n" << "������������ ����� for:" << "\n";

    for(x = Xmin; x <= Xmax; x = x + Xstep)
    {
        y = log10(  fabs( (1 - x) / (1 + x) ) );
        cout << "\t" << "x: " << x << " => " << "y: " << y << "\n";
    }

    getch();

    return 0;
}