#include <iostream>
#include <string>

#include <windows.h>
#include <conio.h>

using namespace std;

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

//структура
struct DataStruct
{
    string Marka; //марка автомобіля
    string PIB; //піб власника
    int Year; //рік випуску
    int Number; //реєстраційний номер (5 символів)
};

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

//функція перевірки року
bool FuncCheckYear
(
    int Year //перевіряємий рік
);

//функція перевірки реєстраційного номеру
template <typename TypeDataStruct>
bool FuncCheckNumber
(
    TypeDataStruct Array[100], //масив даних
    int CounterArray, //лічильник масиву
    int Number //перевіряємий реєстраційний номер
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

    cout << "Ввід користувачів (потрібно ввести мінімум 3 користувачі):" << "\n";

    //цикл вводу користувачів
    while(true)
    {
        string M, P;
        int Y, N;

        cout << "\t" << "Введіть дані користувача №" << CounterArray + 1 << "\n";
        cout << "\t\t" << "марка: ";
        getline(cin, M);
        cin.clear();
        cout << "\t\t" << "піб: ";
        getline(cin, P);
        cin.clear();
        cout << "\t\t" << "рік випуску: ";
        cin >> Y;
        cout << "\t\t" << "реєстраційний номер: ";
        cin >> N;

        cin.ignore();

        //перевірка на правильність введення даних і долучення користвувача
        if( FuncCheckYear(Y) && FuncCheckNumber(Array, CounterArray, N) )
        {
            cout << "\t\t\t" << "Користувач долучений!" << "\n";
            
            Array[CounterArray].Marka = M;
            Array[CounterArray].PIB = P;
            Array[CounterArray].Year = Y;
            Array[CounterArray].Number = N;

            CounterArray = CounterArray + 1;
        }

        cout 
            << "\n\n\t" << "-----------"
            << "\n\t\t" << "Бажаєте долучити ще користувача? (\"+\" - так): ";
        
        string Answer;
        getline(cin, Answer);
        cin.clear();

        cout << "\t" << "-----------" << "\n\n";
        
        //вихід з циклу
        if( (Answer != "+") || (CounterArray == 100) )
        {
            if(CounterArray >= 3)
            {
                break;
            }
            else
            {
                cout << "\t\t" << "Вихід неможливий, у вас введено менше 3 користувачів" << "\n";
            }
        }
    }

    cout << "\n\n" << "Вивід користувачів [рік, піб, марка, номер]:" << "\n";
    
    for(int i = 0; i < CounterArray; i = i + 1)
    {
        cout 
            << "\t" << "[" << Array[i].Year << ", \"" 
            << Array[i].PIB << "\", \"" 
            << Array[i].Marka << "\", "
            << Array[i].Number << "]" << "\n";
    }

    //пункт 1
    cout << "\n\n" << "Введіть марку для пошуку кількості автомобілів цієї марки: ";
    
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

    cout << "\t" << "Кількість: " << CounterSearchMarka << "\n\n";

    //пункт 2
    cout << "\n\n" << "Вивід цих автомобілів зазначеної марки впорядкованим за піб і з реєстраційним номером: " << "\n";
    
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
            cout << "\t" << "користувачі зазначеної марки відсутні!" << "\n";

            break;
        }
    }

    cout << "\n\n";

    //пункт 3
    int MinYear, MaxYear;

    while(true) //цикл вводу
    {
        cout << "Вивід мінімального року: ";
        cin >> MinYear;
        cout << "Вивід максимального року: ";
        cin >> MaxYear;
        
        if( FuncCheckYear(MinYear) && FuncCheckYear(MaxYear) )
        {
            if(MaxYear >= MinYear)
            {
                break;
            }
            else
            {
                cout << "\t\t" << "Мінімальний рік більший за максимальний, перевведіть!" << "\n\n\n";
            }
        }
    }

    cout << "\n" << "Вивід марок і реєстраційних номерів за вказаним діапазон років:" << "\n";

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

//функція перевірки року випуску
bool FuncCheckYear
(
    int Year //перевіряємий рік
)
{
    if( (Year <= 2022) && (Year >= 1900) )
    {
        return true;
    }

    cout << "\t\t\t" << "Введіть рік в діапазоні [1900; 2022]" << "\n\n";

    return false;
}

//функція перевірки реєстраційного номеру
template <typename TypeDataStruct>
bool FuncCheckNumber
(
    TypeDataStruct Array[100], //масив даних
    int CounterArray, //лічильник масиву
    int Number //перевіряємий реєстраційний номер
)
{
    if ( !( (Number <= 99999) && (Number >= 10000) ) )
    {
        cout << "\t\t\t" << "Реєстраційний номер введений неправильному діапазоні [10000; 99999]" << "\n\n";
        
        return false;
    }

    for(int i = 0; i < CounterArray; i = i + 1)
    {
        if(Array[i].Number == Number)
        {
            cout << "\t\t\t" << "Реєстраційний номер належить іншому користувачу" << "\n\n";
            
            return false;
        }
    }

    return true;
}