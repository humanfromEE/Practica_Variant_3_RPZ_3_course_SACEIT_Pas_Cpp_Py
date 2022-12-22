#include <iostream>
#include <string>
#include <set>

#include <windows.h>
#include <conio.h>

using namespace std;

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

//����� ������� ��� ������ � �������
string ArrayKopalin[15] =
    {
        "nafta",
        "zoloto",
        "vugillya",

        "diamanti",
        "gaz",
        "ryda",

        "pisok",
        "zemlya",
        "granit",

        "slanets",
        "aluminiy",
        "bronza",

        "byrshtin",
        "izumrud",
        "svinets"
    };

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

//������� ���������� �������
void FuncInputSet
(
    set <string> &SET //�������
);

//������� ������ �������
void FuncOutputSet
(
    string Message, //�����������
    set <string> SET //�������
);

//|||||||||||||||||||||||||||||||||||||||||||||||||||||
//|||||||||||||||||||||||||||||||||||||||||||||||||||||
//|||||||||||||||||||||||||||||||||||||||||||||||||||||

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //���������� ������
        set <string> First;
        set <string> Second;
        set <string> Third;
        set <string> Fourth;
        set <string> Fifth;

    //���������� ������
        FuncInputSet(First);
        FuncInputSet(Second);
        FuncInputSet(Third);
        FuncInputSet(Fourth);
        FuncInputSet(Fifth);

    //���� ��� ������
        FuncOutputSet("���� ����� �������:", First);
        FuncOutputSet("���� ����� �������:",  Second);
        FuncOutputSet("���� ������ �������:", Third);
        FuncOutputSet("���� �������� �������:", Fourth);
        FuncOutputSet("���� �'��� �������:", Fifth);

    //���� �������� �� � � ��� ��������
    cout << "���� ��������, �� � � ��� ��������:" << "\n";
    
    for(int i = 0; i < 15; i = i + 1)
    {
        if
        (
            First.count(ArrayKopalin[i]) && Second.count(ArrayKopalin[i]) &&
            Third.count(ArrayKopalin[i]) && Fourth.count(ArrayKopalin[i]) &&
            Fifth.count(ArrayKopalin[i])
        )
        {   
            cout << "\t" << ArrayKopalin[i] << "\n";
        }
    }

    //���� �������� ���� ���� � ��������
    cout << "\n\n" << "���� ��������, ���� ���� � �������� ��������:" << "\n";
    
    for(int i = 0; i < 15; i = i + 1)
    {
        if
        ( 
            ( 
                First.count(ArrayKopalin[i]) || Second.count(ArrayKopalin[i]) || Third.count(ArrayKopalin[i]) || 
                Fourth.count(ArrayKopalin[i]) || Fifth.count(ArrayKopalin[i])
            ) == false
        )
        {   
            cout << "\t" << ArrayKopalin[i] << "\n";
        }
    }

    //��������� �������� - ��������, �� � ���� � ������ ������
    cout << "\n\n" << "���� ��������, �� � ���� � ������ ������:" << "\n";
    
    for(set <string> :: iterator i = First.begin(); i != First.end(); i ++)
    {
        if( (
				Second.count(*i) || Third.count(*i) || 
				Fourth.count(*i) || Fifth.count(*i)
			) == false )
        {   
            cout << "\t" << *i << "\n";
        }
    }

    getch();

    return 0;
}

//|||||||||||||||||||||||||||||||||||||||||||||||||||||
//|||||||||||||||||||||||||||||||||||||||||||||||||||||
//|||||||||||||||||||||||||||||||||||||||||||||||||||||

//������� ���������� �������
void FuncInputSet
(
    set <string> &SET //�������
)
{
    for(int i = 0; i < 10; i = i + 1)
    {
        SET.insert(ArrayKopalin[rand() % 10]);
    }
}

//������� ������ �������
void FuncOutputSet
(
    string Message, //�����������
    set <string> SET //�������
)
{
    cout << Message << "\n" << "\t";
    
    for(set <string> :: iterator i = SET.begin(); i != SET.end(); i ++)
    {
        cout << *i << " ";
    }

    cout << "\n\n\n";
}