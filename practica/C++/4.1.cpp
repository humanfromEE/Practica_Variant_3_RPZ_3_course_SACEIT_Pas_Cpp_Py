#include <iostream>
#include <cmath>

#include <windows.h>
#include <conio.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int CounterArray;

    double Array[100];

    while(true) //���� ����� ������� �������� ������
    {
        cout << "������ ������� �������� � �����, ������� [5; 100]: ";
        cin >> CounterArray;

        if( (CounterArray >= 5) && (CounterArray <= 100) )
        {
            break; //����� � �����
        }
        else
        {
            cout << "\t" << "������ ������� [5; 100]" << "\n\n\n";
        }
    }

    //��� �������� ������
    cout << "\n\n" << "��� ������:" << "\n";

    for(int i = 0; i < CounterArray; i = i + 1)
    {
        cout << "\t" << "������� �" << i + 1 << ": ";
        cin >> Array[i];
    }

    double SummPlus = 0.0, SummMinus = 0.0;

    for(int i = 0; i < CounterArray; i = i + 1) //���� ������
    {
        if(Array[i] > 0)
        {
            SummPlus = SummPlus + Array[i];
        }
        else
        {
            SummMinus = SummMinus + Array[i];
        }
    }

    cout 
        << "\n\n" << "����������:" << "\n\t"
        << "���� ������� �����: " << SummPlus << "\n\t"
        << "���� ��'����� �����: " << SummMinus << "\n\t"
        << "������(������) - ������(��'���): " << fabs(SummPlus) - fabs(SummMinus) << "\n";

    getch();

    return 0;
}