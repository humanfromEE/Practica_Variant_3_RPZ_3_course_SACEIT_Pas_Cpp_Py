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

    while(true) //цикл вводу к≥лькост≥ елемент≥в масиву
    {
        cout << "¬вед≥ть к≥льк≥сть елемент≥в у масив≥, д≥апазон [5; 100]: ";
        cin >> CounterArray;

        if( (CounterArray >= 5) && (CounterArray <= 100) )
        {
            break; //вих≥д з циклу
        }
        else
        {
            cout << "\t" << "¬вед≥ть д≥апазон [5; 100]" << "\n\n\n";
        }
    }

    //вв≥д елемент≥в масиву
    cout << "\n\n" << "¬в≥д масиву:" << "\n";

    for(int i = 0; i < CounterArray; i = i + 1)
    {
        cout << "\t" << "елемент є" << i + 1 << ": ";
        cin >> Array[i];
    }

    double SummPlus = 0.0, SummMinus = 0.0;

    for(int i = 0; i < CounterArray; i = i + 1) //цикл пошуку
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
        << "\n\n" << "–езультати:" << "\n\t"
        << "—ума додатн≥х чисел: " << SummPlus << "\n\t"
        << "—ума в≥д'Їмних чисел: " << SummMinus << "\n\t"
        << "ћодуль(додатн≥) - модуль(в≥д'Їмн≥): " << fabs(SummPlus) - fabs(SummMinus) << "\n";

    getch();

    return 0;
}