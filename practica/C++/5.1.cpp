#include <iostream>

#include <windows.h>
#include <conio.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int CounterRows = 4, CounterColumn = 3;
    int Array[CounterRows][CounterColumn];

    //��� ������� ����� ������
    cout << "��� ������� 4�3 (����� ������):" << "\n";
    for(int i = 0; i < CounterRows; i = i + 1)
    {
        for(int j = 0; j < CounterColumn; j = j + 1)
        {
            Array[i][j] = rand() % 10; 
            cout << "\t" << "������� �" << i + 1 << "-" << j + 1 << ": " << Array[i][j] << "\n";
        }
    }
    

    //���� �������
    cout << "\n\n\n" << "���� ������� 4�3:" << "\n";
    
    for(int i = 0; i < CounterRows; i = i + 1)
    {
        cout << "\t";
        
        for(int j = 0; j < CounterColumn; j = j + 1)
        {
            cout << Array[i][j] << " ";  
        }

        cout << "\n";
    }


    //���������� �����
    for(int i = 0; i < CounterRows; i = i + 1) //���� c�������
    {
        //���������� ������� ���������
        for(int j = 1; j < CounterColumn; j = j + 1)
        {
            for(int k = 0; k < (CounterColumn - j); k = k + 1)
            {
                if(Array[i][k] > Array[i][k + 1])
                {
                    int TempVar = Array[i][k];
                    Array[i][k] = Array[i][k + 1];
                    Array[i][k + 1] = TempVar;
                }
            }
        }
    }

    //���� �������
    cout << "\n\n\n" << "���� ��������� ������� 4�3 �� ���������� �����: " << "\n";
    
    for(int i = 0; i < CounterRows; i = i + 1)
    {
        cout << "\t";
        
        for(int j = 0; j < CounterColumn; j = j + 1)
        {
            cout << Array[i][j] << " ";  
        }

        cout << "\n";
    }

    getch();

    return 0;
}