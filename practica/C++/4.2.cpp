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
       
    int FirstIndex; //індекс відкриваючої дужки
    int SecondIndex; //індекс закриваючої дужки
    int CounterFirstIndex; //кількість відкриваючих дужок
    int CounterSecondIndex; //кількість закриваючиї дужок

    while(true)
    {   
        //ввід тексту
        cout << "Введіть текст:" << "\n\t";
        getline(cin, UserText);
        cin.clear();

        FirstIndex = -1; //значення "-1" для визначння, якщо не буде дужок у тексті
        SecondIndex = -1; //значення "-1" для визначння, якщо не буде дужок у тексті
        CounterFirstIndex = 0;
        CounterSecondIndex = 0;

        //цикл пошуку дужок і їх індекс у строці тексту
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

        if( (FirstIndex == -1) && (SecondIndex == -1) ) //якщо у тексті немає дужок
        {
            cout << "\n\t\t" << "У тексті відсутні дужки" << "\n\n";
        }
        else if(FirstIndex == -1) //якщо немає дужки "("
        {
            cout << "\n\t\t" << "У тексті немає дужки: \"(\"" << "\n\n";
        }
        else if(SecondIndex == -1) //якщо немає дужки ")"
        {
            cout << "\n\t\t" << "У тексті немає дужки: \")\"" << "\n\n";
        }
        else if(CounterFirstIndex != 1) //якщо є кілька дужок "(" 
        {
            cout << "\n\t\t" << "У тексті є декілька дужок: \"(\"" << "\n\n";
        }
        else if(CounterSecondIndex != 1) //якщо є кілька дужок ")" 
        {
            cout << "\n\t\t" << "У тексті є декілька дужок: \")\"" << "\n\n";
        }
        else if(FirstIndex > SecondIndex) //якщо дужки стоять ") текст ("
        {
            cout << "\n\t\t" << "У тексті введено фраграгмент: \"текст ) текст ( текст\"" << "\n\n";
        }
        else //вихід з циклу
        {
            break;
        }
    }

    string CorrectText = "";

    for(int i = 0; i < FirstIndex; i = i + 1) //копіювання першої частини
    {
        CorrectText = CorrectText + UserText[i];
    }

    for(int i = SecondIndex + 1; i < UserText.length(); i = i + 1) //копіювання другої частини
    {
        CorrectText = CorrectText + UserText[i];
    }

    cout << "\n\n" << "Текст без дужок:" << "\n\t" << CorrectText << "\n";

    getch();

    return 0;
}