#include <iostream>
#include <string>

#include <windows.h>
#include <conio.h>

using namespace std;

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

//генерування матриці
void FuncGenerateArray
(
    int CounterArray, //лічильник масиву
    int Array[10][10] //масив
);

//вивід матриці
void FuncOutputArray
(
    int CounterArray, //лічильник масиву
    int Array[10][10], //масив
    string Message //повідомлення
);

//копіювання масиву
void FuncCopyArray
(
    int CounterArray, //лічильник масиву
    int Array[10][10], //масив
    int CopyArray[10 * 10] //масив копія
);

//вивід копіювального масиву
void FuncOutputCopyArray
(
    int CounterArray, //лічильник масиву
    int CopyArray[10 * 10], //масив копія
    string Message //повідомлення
);

//сортування масиву методом вибору
void FuncSortArray
(
    int CounterArray, //лічильник масиву
    int CopyArray[10 * 10] //масив копія
);

//функція створення потрібної матриці зі завдання
void FuncCreateTrueMatrix
(
    int CounterArray, //лічильник масиву
    int Array[10][10], //масив
    int CopyArray[10 * 10] //масив копія
);

//|||||||||||||||||||||||||||||||||||||||||||||||||||||
//|||||||||||||||||||||||||||||||||||||||||||||||||||||
//|||||||||||||||||||||||||||||||||||||||||||||||||||||

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int CounterArray; //лічильник масиву

    while(true) //цикл вводу розмірності матриці
    {
        cout << "Введіть розмірність матриці: ";
        cin >> CounterArray;
        
        if( (CounterArray <= 10) && (CounterArray > 1) )
        {
            break;
        }
        else
        {
            cout << "\t" << "Розмірність повинна бути в діпазоні [2; 10]" << "\n\n\n\n";
        }
    }

    int Array[10][10]; //головний масив
    int CopyArray[10 * 10]; //одномірний масив з усіма елементами

    FuncGenerateArray(CounterArray, Array);
    FuncOutputArray(CounterArray, Array, "Вивід матриці після генерування");
    FuncCopyArray(CounterArray, Array, CopyArray);
    FuncOutputCopyArray(CounterArray, CopyArray, "Вивід масиву зі значеннями матриці");
    FuncSortArray(CounterArray, CopyArray);
    FuncOutputCopyArray(CounterArray, CopyArray, "Вивід масиву зі значеннями матриці у сортувальному вигляді");
    FuncCreateTrueMatrix(CounterArray, Array, CopyArray);
    FuncOutputArray(CounterArray, Array, "Вивід матриці у завданні");

    getch();

    return 0;
}

//|||||||||||||||||||||||||||||||||||||||||||||||||||||
//|||||||||||||||||||||||||||||||||||||||||||||||||||||
//|||||||||||||||||||||||||||||||||||||||||||||||||||||

//генерування матриці
void FuncGenerateArray
(
    int CounterArray, //лічильник масиву
    int Array[10][10] //масив
)
{
    cout << "Заповнення масиву випадковими числами:" << "\n" << "\t";
    
    for(int i = 0; i < CounterArray; i = i + 1)
    {
        for(int j = 0; j < CounterArray; j = j + 1)
        {
            Array[i][j] = rand() % 9;

            cout << "елемент №" << i + 1 << "-" << j + 1 << ": " << Array[i][j] << "\n" << "\t";
        }
    }

    cout << "\n\n\n";
}

//вивід матриці
void FuncOutputArray
(
    int CounterArray, //лічильник масиву
    int Array[10][10], //масив
    string Message //повідомлення
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

//копіювання масиву
void FuncCopyArray
(
    int CounterArray, //лічильник масиву
    int Array[10][10], //масив
    int CopyArray[10 * 10] //масив копія
)
{
    int CounterCopyArray = 0; //лічильник масиву копії

    for(int i = 0; i < CounterArray; i = i + 1)
    {
        for(int j = 0; j < CounterArray; j = j + 1)
        {
            CopyArray[CounterCopyArray] = Array[i][j];

            CounterCopyArray = CounterCopyArray + 1;
        }
    }
}

//вивід копіювального масиву
void FuncOutputCopyArray
(
    int CounterArray, //лічильник масиву
    int CopyArray[10 * 10], //масив копія
    string Message //повідомлення
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

//сортування масиву методом вибору
void FuncSortArray
(
    int CounterArray, //лічильник масиву
    int CopyArray[10 * 10] //масив копія
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

//функція створення потрібної матриці зі завдання
void FuncCreateTrueMatrix
(
    int CounterArray, //лічильник масиву
    int Array[10][10], //масив
    int CopyArray[10 * 10] //масив копія
)
{
    int CounterCopyArray = 0; //лічильник масиву копії

    for(int i = 0; i < CounterArray; i = i + 1)
    {
        if(((i + 1) % 2) != 0) //непарний рядок буде за спаданням
        {
            for(int j = CounterArray - 1; j >= 0; j = j - 1)
            {
                Array[i][j] = CopyArray[CounterCopyArray];

                CounterCopyArray = CounterCopyArray + 1;
            }
        }
        else //парний рядок буде за зростанням
        {
            for(int j = 0; j < CounterArray; j = j + 1)
            {
                Array[i][j] = CopyArray[CounterCopyArray];

                CounterCopyArray = CounterCopyArray + 1;
            }
        }
    }
}