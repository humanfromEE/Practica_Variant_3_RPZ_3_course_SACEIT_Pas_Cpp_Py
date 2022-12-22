#include <iostream>
#include <string>

#include <windows.h>
#include <conio.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string UserText;
       
    int FirstIndex; //������ ���������� �����
    int SecondIndex; //������ ���������� �����
    int CounterFirstIndex; //������� ����������� �����
    int CounterSecondIndex; //������� ���������� �����

    while(true)
    {   
        //��� ������
        cout << "������ �����:" << "\n\t";
        getline(cin, UserText);
        cin.clear();

        FirstIndex = -1; //�������� "-1" ��� ���������, ���� �� ���� ����� � �����
        SecondIndex = -1; //�������� "-1" ��� ���������, ���� �� ���� ����� � �����
        CounterFirstIndex = 0;
        CounterSecondIndex = 0;

        //���� ������ ����� � �� ������ � ������ ������
        for(int i = 0; i < UserText.length(); i = i + 1)
        {
            if(UserText[i] == '(')
            {
                FirstIndex = i;
                CounterFirstIndex = CounterFirstIndex + 1;
            }
            
            if(UserText[i] == ')')
            {
                SecondIndex = i;
                CounterSecondIndex = CounterSecondIndex + 1;
            }
        }

        if( (FirstIndex == -1) && (SecondIndex == -1) ) //���� � ����� ���� �����
        {
            cout << "\n\t\t" << "� ����� ������ �����" << "\n\n";
        }
        else if(FirstIndex == -1) //���� ���� ����� "("
        {
            cout << "\n\t\t" << "� ����� ���� �����: \"(\"" << "\n\n";
        }
        else if(SecondIndex == -1) //���� ���� ����� ")"
        {
            cout << "\n\t\t" << "� ����� ���� �����: \")\"" << "\n\n";
        }
        else if(CounterFirstIndex != 1) //���� � ����� ����� "(" 
        {
            cout << "\n\t\t" << "� ����� � ������� �����: \"(\"" << "\n\n";
        }
        else if(CounterSecondIndex != 1) //���� � ����� ����� ")" 
        {
            cout << "\n\t\t" << "� ����� � ������� �����: \")\"" << "\n\n";
        }
        else if(FirstIndex > SecondIndex) //���� ����� ������ ") ����� ("
        {
            cout << "\n\t\t" << "� ����� ������� �����������: \"����� ) ����� ( �����\"" << "\n\n";
        }
        else //����� � �����
        {
            break;
        }
    }

    string CorrectText = "";

    for(int i = 0; i < FirstIndex; i = i + 1) //��������� ����� �������
    {
        CorrectText = CorrectText + UserText[i];
    }

    for(int i = SecondIndex + 1; i < UserText.length(); i = i + 1) //��������� ����� �������
    {
        CorrectText = CorrectText + UserText[i];
    }

    cout << "\n\n" << "����� ��� �����:" << "\n\t" << CorrectText << "\n";

    getch();

    return 0;
}