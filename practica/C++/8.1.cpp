#include <iostream>
#include <string>

#include <windows.h>
#include <conio.h>

using namespace std;

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

//���������
struct DataStruct
{
    string Marka; //����� ���������
    string PIB; //�� ��������
    int Year; //�� �������
    int Number; //������������ ����� (5 �������)
};

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

//������� �������� ����
bool FuncCheckYear
(
    int Year //����������� ��
);

//������� �������� ������������� ������
template <typename TypeDataStruct>
bool FuncCheckNumber
(
    TypeDataStruct Array[100], //����� �����
    int CounterArray, //�������� ������
    int Number //����������� ������������ �����
);

//|||||||||||||||||||||||||||||||||||||||||||||||||||||
//|||||||||||||||||||||||||||||||||||||||||||||||||||||
//|||||||||||||||||||||||||||||||||||||||||||||||||||||

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    DataStruct Array[100];
    int CounterArray = 0;

    cout << "��� ������������ (������� ������ ����� 3 �����������):" << "\n";

    //���� ����� ������������
    while(true)
    {
        string M, P;
        int Y, N;

        cout << "\t" << "������ ��� ����������� �" << CounterArray + 1 << "\n";
        cout << "\t\t" << "�����: ";
        getline(cin, M);
        cin.clear();
        cout << "\t\t" << "��: ";
        getline(cin, P);
        cin.clear();
        cout << "\t\t" << "�� �������: ";
        cin >> Y;
        cout << "\t\t" << "������������ �����: ";
        cin >> N;

        cin.ignore();

        //�������� �� ����������� �������� ����� � ��������� ������������
        if( FuncCheckYear(Y) && FuncCheckNumber(Array, CounterArray, N) )
        {
            cout << "\t\t\t" << "���������� ���������!" << "\n";
            
            Array[CounterArray].Marka = M;
            Array[CounterArray].PIB = P;
            Array[CounterArray].Year = Y;
            Array[CounterArray].Number = N;

            CounterArray = CounterArray + 1;
        }

        cout 
            << "\n\n\t" << "-----------"
            << "\n\t\t" << "������ �������� �� �����������? (\"+\" - ���): ";
        
        string Answer;
        getline(cin, Answer);
        cin.clear();

        cout << "\t" << "-----------" << "\n\n";
        
        //����� � �����
        if( (Answer != "+") || (CounterArray == 100) )
        {
            if(CounterArray >= 3)
            {
                break;
            }
            else
            {
                cout << "\t\t" << "����� ����������, � ��� ������� ����� 3 ������������" << "\n";
            }
        }
    }

    cout << "\n\n" << "���� ������������ [��, ��, �����, �����]:" << "\n";
    
    for(int i = 0; i < CounterArray; i = i + 1)
    {
        cout 
            << "\t" << "[" << Array[i].Year << ", \"" 
            << Array[i].PIB << "\", \"" 
            << Array[i].Marka << "\", "
            << Array[i].Number << "]" << "\n";
    }

    //����� 1
    cout << "\n\n" << "������ ����� ��� ������ ������� ��������� ���� �����: ";
    
    string SearchMarka;
    getline(cin, SearchMarka);
    cin.clear();

    int CounterSearchMarka = 0;

    for(int i = 0; i < CounterArray; i = i + 1)
    {
        if(Array[i].Marka == SearchMarka)
        {
            CounterSearchMarka = CounterSearchMarka + 1;
        }
    }

    cout << "\t" << "ʳ������: " << CounterSearchMarka << "\n\n";

    //����� 2
    cout << "\n\n" << "���� ��� ��������� ��������� ����� ������������� �� �� � � ������������ �������: " << "\n";
    
    for(int i = 1; i < CounterArray; i = i + 1)
    {
        for(int j = 0; j < (CounterArray - i); j = j + 1)
        {
            if(Array[j].PIB > Array[j + 1].PIB)
            {
                DataStruct TempVar = Array[j];
                Array[j] = Array[j + 1];
                Array[j + 1] = TempVar;
            }
        }
    }

    for(int i = 0; i < CounterArray; i = i + 1)
    {
        if(CounterSearchMarka != 0)
        {
            if(Array[i].Marka == SearchMarka)
            {
                cout << "\t" << "[" << "\"" << Array[i].PIB << "\", " << Array[i].Number << "]" << "\n";
            }
        }
        else
        {
            cout << "\t" << "����������� ��������� ����� ������!" << "\n";

            break;
        }
    }

    cout << "\n\n";

    //����� 3
    int MinYear, MaxYear;

    while(true) //���� �����
    {
        cout << "���� ���������� ����: ";
        cin >> MinYear;
        cout << "���� ������������� ����: ";
        cin >> MaxYear;
        
        if( FuncCheckYear(MinYear) && FuncCheckYear(MaxYear) )
        {
            if(MaxYear >= MinYear)
            {
                break;
            }
            else
            {
                cout << "\t\t" << "̳�������� �� ������ �� ������������, ����������!" << "\n\n\n";
            }
        }
    }

    cout << "\n" << "���� ����� � ������������ ������ �� �������� ������� ����:" << "\n";

    for(int i = 0; i < CounterArray; i = i + 1)
    {
        if( (Array[i].Year <= MaxYear) && (Array[i].Year >= MinYear) )
        {
            cout << "\t" << "[" << "\"" << Array[i].Marka << "\", " << Array[i].Number << "]" << "\n";
        }
    }

    getch();

    return 0;
}

//|||||||||||||||||||||||||||||||||||||||||||||||||||||
//|||||||||||||||||||||||||||||||||||||||||||||||||||||
//|||||||||||||||||||||||||||||||||||||||||||||||||||||

//������� �������� ���� �������
bool FuncCheckYear
(
    int Year //����������� ��
)
{
    if( (Year <= 2022) && (Year >= 1900) )
    {
        return true;
    }

    cout << "\t\t\t" << "������ �� � ������� [1900; 2022]" << "\n\n";

    return false;
}

//������� �������� ������������� ������
template <typename TypeDataStruct>
bool FuncCheckNumber
(
    TypeDataStruct Array[100], //����� �����
    int CounterArray, //�������� ������
    int Number //����������� ������������ �����
)
{
    if ( !( (Number <= 99999) && (Number >= 10000) ) )
    {
        cout << "\t\t\t" << "������������ ����� �������� ������������� ������� [10000; 99999]" << "\n\n";
        
        return false;
    }

    for(int i = 0; i < CounterArray; i = i + 1)
    {
        if(Array[i].Number == Number)
        {
            cout << "\t\t\t" << "������������ ����� �������� ������ �����������" << "\n\n";
            
            return false;
        }
    }

    return true;
}