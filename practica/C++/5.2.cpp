#include <iostream>
#include <string>

#include <windows.h>
#include <conio.h>

using namespace std;

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

//����������� �������
void FuncGenerateArray
(
    int CounterArray, //�������� ������
    int Array[10][10] //�����
);

//���� �������
void FuncOutputArray
(
    int CounterArray, //�������� ������
    int Array[10][10], //�����
    string Message //�����������
);

//��������� ������
void FuncCopyArray
(
    int CounterArray, //�������� ������
    int Array[10][10], //�����
    int CopyArray[10 * 10] //����� ����
);

//���� ������������ ������
void FuncOutputCopyArray
(
    int CounterArray, //�������� ������
    int CopyArray[10 * 10], //����� ����
    string Message //�����������
);

//���������� ������ ������� ������
void FuncSortArray
(
    int CounterArray, //�������� ������
    int CopyArray[10 * 10] //����� ����
);

//������� ��������� ������� ������� � ��������
void FuncCreateTrueMatrix
(
    int CounterArray, //�������� ������
    int Array[10][10], //�����
    int CopyArray[10 * 10] //����� ����
);

//|||||||||||||||||||||||||||||||||||||||||||||||||||||
//|||||||||||||||||||||||||||||||||||||||||||||||||||||
//|||||||||||||||||||||||||||||||||||||||||||||||||||||

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int CounterArray; //�������� ������

    while(true) //���� ����� ��������� �������
    {
        cout << "������ ��������� �������: ";
        cin >> CounterArray;
        
        if( (CounterArray <= 10) && (CounterArray > 1) )
        {
            break;
        }
        else
        {
            cout << "\t" << "��������� ������� ���� � ������ [2; 10]" << "\n\n\n\n";
        }
    }

    int Array[10][10]; //�������� �����
    int CopyArray[10 * 10]; //��������� ����� � ���� ����������

    FuncGenerateArray(CounterArray, Array);
    FuncOutputArray(CounterArray, Array, "���� ������� ���� �����������");
    FuncCopyArray(CounterArray, Array, CopyArray);
    FuncOutputCopyArray(CounterArray, CopyArray, "���� ������ � ���������� �������");
    FuncSortArray(CounterArray, CopyArray);
    FuncOutputCopyArray(CounterArray, CopyArray, "���� ������ � ���������� ������� � ������������� ������");
    FuncCreateTrueMatrix(CounterArray, Array, CopyArray);
    FuncOutputArray(CounterArray, Array, "���� ������� � �������");

    getch();

    return 0;
}

//|||||||||||||||||||||||||||||||||||||||||||||||||||||
//|||||||||||||||||||||||||||||||||||||||||||||||||||||
//|||||||||||||||||||||||||||||||||||||||||||||||||||||

//����������� �������
void FuncGenerateArray
(
    int CounterArray, //�������� ������
    int Array[10][10] //�����
)
{
    cout << "���������� ������ ����������� �������:" << "\n" << "\t";
    
    for(int i = 0; i < CounterArray; i = i + 1)
    {
        for(int j = 0; j < CounterArray; j = j + 1)
        {
            Array[i][j] = rand() % 9;

            cout << "������� �" << i + 1 << "-" << j + 1 << ": " << Array[i][j] << "\n" << "\t";
        }
    }

    cout << "\n\n\n";
}

//���� �������
void FuncOutputArray
(
    int CounterArray, //�������� ������
    int Array[10][10], //�����
    string Message //�����������
)
{
    cout << Message << ":" << "\n";
    
    for(int i = 0; i < CounterArray; i = i + 1)
    {
        cout << "\t";
        
        for(int j = 0; j < CounterArray; j = j + 1)
        {
            cout << Array[i][j] << " ";
        }

        cout << "\n";
    }

    cout << "\n\n\n";
}

//��������� ������
void FuncCopyArray
(
    int CounterArray, //�������� ������
    int Array[10][10], //�����
    int CopyArray[10 * 10] //����� ����
)
{
    int CounterCopyArray = 0; //�������� ������ ��ﳿ

    for(int i = 0; i < CounterArray; i = i + 1)
    {
        for(int j = 0; j < CounterArray; j = j + 1)
        {
            CopyArray[CounterCopyArray] = Array[i][j];

            CounterCopyArray = CounterCopyArray + 1;
        }
    }
}

//���� ������������ ������
void FuncOutputCopyArray
(
    int CounterArray, //�������� ������
    int CopyArray[10 * 10], //����� ����
    string Message //�����������
)
{
    cout << Message << ":" << "\n" << "\t";

    for(int i = 0; i < (CounterArray * CounterArray); i = i + 1)
    {
        if(((i + 1) % 25 ) == 0)
        {
            cout << CopyArray[i] << "\n" << "\t";
        }
        else
        {
            cout << CopyArray[i] << " ";
        }
    }

    cout << "\n\n\n";
}

//���������� ������ ������� ������
void FuncSortArray
(
    int CounterArray, //�������� ������
    int CopyArray[10 * 10] //����� ����
)
{
    for(int i = 0; i < (CounterArray * CounterArray - 1); i = i + 1)
    {
        for(int j = i + 1; j < (CounterArray * CounterArray); j = j + 1)
        {
            if(CopyArray[i] > CopyArray[j])
            {
                int TempVar = CopyArray[i];
                CopyArray[i] = CopyArray[j];
                CopyArray[j] = TempVar;
            }
        }
    }
}

//������� ��������� ������� ������� � ��������
void FuncCreateTrueMatrix
(
    int CounterArray, //�������� ������
    int Array[10][10], //�����
    int CopyArray[10 * 10] //����� ����
)
{
    int CounterCopyArray = 0; //�������� ������ ��ﳿ

    for(int i = 0; i < CounterArray; i = i + 1)
    {
        if(((i + 1) % 2) != 0) //�������� ����� ���� �� ���������
        {
            for(int j = CounterArray - 1; j >= 0; j = j - 1)
            {
                Array[i][j] = CopyArray[CounterCopyArray];

                CounterCopyArray = CounterCopyArray + 1;
            }
        }
        else //������ ����� ���� �� ����������
        {
            for(int j = 0; j < CounterArray; j = j + 1)
            {
                Array[i][j] = CopyArray[CounterCopyArray];

                CounterCopyArray = CounterCopyArray + 1;
            }
        }
    }
}