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

    //������������ if (�� ��������� goto)
    cout << "������������ if (�� ��������� goto):" << "\n";

    i = 1;

    IF: //���������� ����
        factorial = 1;
        j = 1;

        FACTORIAL: //���������� ���������
            if(j <= i) 
            {
                factorial = factorial * j;
                j = j + 1;

                goto FACTORIAL;
            }

        if(i <= 10)
        {
            y = y + 1.0 / factorial;
            cout << "\t" << "i: " << i << " => " << "��������: " << factorial << " => " << "y: " << y << "\n";
            i = i + 1;

            goto IF;
        }


    //������������ ����� while
    cout << "\n\n" << "������������ ����� while:" << "\n";

    i = 1;
    y = 0;

    while(i <= 10) //���������� ����
    {
        factorial = 1;
        j = 1;

        while(j <= i) //���������� ���������
        {
            factorial = factorial * j;
            j = j + 1;
        }

        y = y + 1.0 / factorial;
        cout << "\t" << "i: " << i << " => " << "��������: " << factorial << " => " << "y: " << y << "\n";
        i = i + 1;
    }


    //������������ ����� do - while
    cout << "\n\n" << "������������ ����� do - while:" << "\n";

    i = 1;
    y = 0;

    do //���������� ����
    {
        factorial = 1;
        j = 1;

        do //���������� ���������
        {
            factorial = factorial * j;
            j = j + 1;
        }
        while(j <= i);

        y = y + 1.0 / factorial;
        cout << "\t" << "i: " << i << " => " << "��������: " << factorial << " => " << "y: " << y << "\n";
        i = i + 1;
    }
    while(i <= 10);


    //������������ ����� for
    cout << "\n\n" << "������������ ����� for:"<< "\n";

    y = 0;
    
    for(i = 1; i <= 10; i = i + 1) //���������� ����
    {
        factorial = 1;

        for(j = 1; j <= i; j = j + 1) //���������� ���������
        {
            factorial = factorial * j;
        }

        y = y + 1.0 / factorial;
        cout << "\t" << "i: " << i << " => " << "��������: " << factorial << " => " << "y: " << y << "\n";
    }

    getch();

    return 0;
}