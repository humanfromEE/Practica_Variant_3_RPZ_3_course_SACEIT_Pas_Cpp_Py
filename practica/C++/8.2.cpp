#include <iostream>
#include <string>
#include <set>

#include <windows.h>
#include <conio.h>

using namespace std;

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

//масив копалин для запису у множини
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

//функція заповнення множини
void FuncInputSet
(
    set <string> &SET //множина
);

//функція виводу множини
void FuncOutputSet
(
    string Message, //повідомлення
    set <string> SET //множина
);

//|||||||||||||||||||||||||||||||||||||||||||||||||||||
//|||||||||||||||||||||||||||||||||||||||||||||||||||||
//|||||||||||||||||||||||||||||||||||||||||||||||||||||

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //оголошення множин
        set <string> First;
        set <string> Second;
        set <string> Third;
        set <string> Fourth;
        set <string> Fifth;

    //заповнення множин
        FuncInputSet(First);
        FuncInputSet(Second);
        FuncInputSet(Third);
        FuncInputSet(Fourth);
        FuncInputSet(Fifth);

    //вивід усіх множин
        FuncOutputSet("Вивід першої множини:", First);
        FuncOutputSet("Вивід другої множини:",  Second);
        FuncOutputSet("Вивід третьої множини:", Third);
        FuncOutputSet("Вивід четвертої множини:", Fourth);
        FuncOutputSet("Вивід п'ятої множини:", Fifth);

    //вивід елементів які є у всіх множинах
    cout << "Вивід елементів, які є у всіх множинах:" << "\n";
    
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

    //вивід елементів яких немає у множинах
    cout << "\n\n" << "Вивід елементів, яких немає у множинах множинах:" << "\n";
    
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

    //додаткове завдання - елементи, які є лише у першій множині
    cout << "\n\n" << "Вивід елементів, які є лише у першій множині:" << "\n";
    
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

//функція заповнення множини
void FuncInputSet
(
    set <string> &SET //множина
)
{
    for(int i = 0; i < 10; i = i + 1)
    {
        SET.insert(ArrayKopalin[rand() % 10]);
    }
}

//функція виводу множини
void FuncOutputSet
(
    string Message, //повідомлення
    set <string> SET //множина
)
{
    cout << Message << "\n" << "\t";
    
    for(set <string> :: iterator i = SET.begin(); i != SET.end(); i ++)
    {
        cout << *i << " ";
    }

    cout << "\n\n\n";
}