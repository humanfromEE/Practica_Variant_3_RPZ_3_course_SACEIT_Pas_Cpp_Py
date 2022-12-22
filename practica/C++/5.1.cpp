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

    //ввід матриці через рандом
    cout << "Ввід матриці 4х3 (через рандом):" << "\n";
    for(int i = 0; i < CounterRows; i = i + 1)
    {
        for(int j = 0; j < CounterColumn; j = j + 1)
        {
            Array[i][j] = rand() % 10; 
            cout << "\t" << "елемент №" << i + 1 << "-" << j + 1 << ": " << Array[i][j] << "\n";
        }
    }
    

    //вивід матриці
    cout << "\n\n\n" << "Вивід матриці 4х3:" << "\n";
    
    for(int i = 0; i < CounterRows; i = i + 1)
    {
        cout << "\t";
        
        for(int j = 0; j < CounterColumn; j = j + 1)
        {
            cout << Array[i][j] << " ";  
        }

        cout << "\n";
    }


    //сортування рядків
    for(int i = 0; i < CounterRows; i = i + 1) //цикл cтовпців
    {
        //сортування методом бульбашки
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

    //вивід матриці
    cout << "\n\n\n" << "Вивід сортованої матриці 4х3 за збільшенням рядка: " << "\n";
    
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