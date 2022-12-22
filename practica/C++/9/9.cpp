#include <iostream>
#include <fstream>
#include <string>

#include <windows.h>
#include <conio.h>

using namespace std;

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

/*
    //перевірка наявності файлів і цілісність даних - void FuncCheckFiles

    //табуляція - string FuncCoutTab
    //вивід лінії - void FuncCoutLine

    //перевірка на долучення даних, якщо номер авіарейсу відсутній у БД - bool FuncCheckCommandOne
    //перевірка на видалення редагування на існування номеру авіарейсу для подальших дій - bool FuncCheckCommandTwoThree 
    //кількість записів у БД - int FuncCheckVoidBaseData
    //долучення записів у кінець файлів - void FuncAppendDataInEndFile
    //видалення записів за номером строки - void FuncDeleteDataInFile
    //редагування записів за номером строки - void FuncEditDataInFile
    //вивід даних за номером строки - void FuncOutputDataInFile

    //команда 1 (долучення даних у БД) - void FuncCommandOne
    //команда 2 (редагування даних у БД) - void FuncCommandTwo
    //команда 3 (видалення даних у БД) - void FuncCommandThree
    //команда 4 (вивід даних БД) - void FuncCommandFour
    //команда 5 (вивід даних БД за вказаним типом літака) - void FuncCommandFive

    //перевірка введеної команди - bool FuncCheckInputCommand
    //створення звіту - void FuncCreateReport
*/

//назви файлів
    string NameFileReport = "звіт.txt";
    string NameFileNumber = "номер авіарейсу.txt";
    string NameFileMarshut = "маршрут.txt";
    string NameFileType = "тип літака.txt";
    string NameFileStancia = "станція.txt";
    string NameFilePrice = "ціна квітка.txt";

//довжина ліній
    int LengthLineProgram = 125; 

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

//перевірка наявності файлів і цілісність даних 
void FuncCheckFiles();

//табуляція
string FuncCoutTab
(
    int CountTab //кількість tab
);

//вивід лінії
void FuncCoutLine
(
    int CountTab, //кількість tab
    int LengthLine, //довжина лінії
    char SymbolLine //символ лінії
);

//перевірка на долучення даних, якщо номер авіарейсу відсутній у БД
bool FuncCheckCommandOne
(
    int CountTab, //кількість tab
    string Number // номер авіарейсу
);

//перевірка на видалення редагування на існування номеру авіарейсу для подальших дій
bool FuncCheckCommandTwoThree
(
    int CountTab, //кількість tab
    string Number // номер авіарейсу
);

//кількість записів у БД
int FuncCheckVoidBaseData();

//долучення записів у кінець файлів
void FuncAppendDataInEndFile
(
    string NameFile, //ім'я файлу
    string Value //долучаєме значення
);

//видалення записів за номером строки
void FuncDeleteDataInFile
(
    string NameFile, //ім'я файлу
    int SaveLine //збережена строка
);

//редагування записів за номером строки
void FuncEditDataInFile
(
    string NameFile, //ім'я файлу
    int SaveLine, //збережена строка
    string Value //нове значення
);

//вивід даних за номером строки
void FuncOutputDataInFile
(
    string Message, //повідомлення щодо вивводу величини строки
    int CountTab, //кількість tab
    string NameFile, //ім'я файлу
    int SaveLine //збережена строка
);

//команда 1 (долучення даних у БД)
void FuncCommandOne
(
    int CountTab //кількість tab
);

//команда 2 (редагування даних у БД)
void FuncCommandTwo
(
    int CountTab //кількість tab
);

//команда 3 (видалення даних у БД)
void FuncCommandThree
(
    int CountTab //кількість tab
);

//команда 4 (вивід даних БД)
void FuncCommandFour
(
    int CountTab //кількість tab
);

//команда 5 (вивід даних БД за вказаним типом літака)
void FuncCommandFive
(
    int CountTab //кількість tab
);

//перевірка введеної команди 
bool FuncCheckInputCommand
(
    int CountTab, //кількість tab
    string Command //команда
);

//створення звіту 
void FuncCreateReport();

//|||||||||||||||||||||||||||||||||||||||||||||||||||||
//|||||||||||||||||||||||||||||||||||||||||||||||||||||
//|||||||||||||||||||||||||||||||||||||||||||||||||||||
//|||||||||||||||||||||||||||||||||||||||||||||||||||||
//|||||||||||||||||||||||||||||||||||||||||||||||||||||
//|||||||||||||||||||||||||||||||||||||||||||||||||||||
//|||||||||||||||||||||||||||||||||||||||||||||||||||||
//|||||||||||||||||||||||||||||||||||||||||||||||||||||
//|||||||||||||||||||||||||||||||||||||||||||||||||||||

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    FuncCheckFiles();

    FuncCoutLine(0, LengthLineProgram, '`');

    while (true)
    {
        cout
            << "МЕНЮ:" << "\n"
            << "\t" << "1 - долучити запис" << "\n"
            << "\t" << "2 - редагувати запис" << "\n"
            << "\t" << "3 - видалити запис" << "\n"
            << "\t" << "4 - вивести записи" << "\n"
            << "\t" << "5 - вивести літаки за вказаним типом" << "\n"
            << "\t" << "0 - вихід з програми" << "\n"
            << "\t\t\t" << "кількість записів у БД: " << FuncCheckVoidBaseData() << "\n";
        
        cout << "\t\t" << "ваш вибір: ";
        string Command;
        getline(cin, Command);
        cin.clear();

        if(FuncCheckInputCommand(3, Command))
        {
            if(Command == "1")
            {
                FuncCommandOne(3);
            }
            else if((Command == "2") && (FuncCheckVoidBaseData() > 0))
            {
                FuncCommandTwo(3);
            }
            else if((Command == "3") && (FuncCheckVoidBaseData() > 0))
            {
                FuncCommandThree(3);
            }
            else if((Command == "4") && (FuncCheckVoidBaseData() > 0))
            {
                FuncCommandFour(3);
            }
            else if((Command == "5") && (FuncCheckVoidBaseData() > 0))
            {
                FuncCommandFive(3);
            }
            else if(Command != "0") //вивід повідомлення, що для виконання команди потрібен хоча б 1 запис
            {
                cout << FuncCoutTab(3) << "для цієї комнади потрібен хочаб 1 запис у БД, долучіть запис" << "\n";
            }
            else
            {
                cout << FuncCoutTab(3) << "ВИХІД З ПРОГРАМИ" << "\n"
                     << FuncCoutTab(4) << "Не видаляйте файли для повторного перезапуску" << "\n"
                     << FuncCoutTab(4) << "Бажаєте створити звіт? (\"+\" - так): ";
                string Answer;
                getline(cin, Answer);
                cin.clear();

                if(Answer == "+")
                {
                    FuncCreateReport();
                    cout << FuncCoutTab(5) << "Назва файлу: \"" << NameFileReport << "\"" << "\n";
                }

                FuncCoutLine(0, LengthLineProgram, '`');

                break;
            }

            FuncCoutLine(0, LengthLineProgram, '`');
        }
    }

    cout << "\n\n\n\n" << "Для закриття вікна натисність будь-яку клавішу" << "\n";
    getch();

    return 0;
}

//|||||||||||||||||||||||||||||||||||||||||||||||||||||
//|||||||||||||||||||||||||||||||||||||||||||||||||||||
//|||||||||||||||||||||||||||||||||||||||||||||||||||||
//|||||||||||||||||||||||||||||||||||||||||||||||||||||
//|||||||||||||||||||||||||||||||||||||||||||||||||||||
//|||||||||||||||||||||||||||||||||||||||||||||||||||||
//|||||||||||||||||||||||||||||||||||||||||||||||||||||
//|||||||||||||||||||||||||||||||||||||||||||||||||||||
//|||||||||||||||||||||||||||||||||||||||||||||||||||||

//перевірка наявності файлів і цілісність даних
void FuncCheckFiles()
{
    bool CreateAllFiles = false; //змінна, яка відповідає за створення усіх файлів

    ifstream File1, File2, File3, File4, File5;

    File1.open(NameFileMarshut);
    File2.open(NameFileNumber);
    File3.open(NameFilePrice);
    File4.open(NameFileStancia);
    File5.open(NameFileType);

    //перевірка існування усіх файлів
    if( File1.is_open() && File2.is_open() && File3.is_open() && File4.is_open() && File5.is_open())
    {
        //рахування кількості рядків для кожного файлу
        int ArrayCountersLine[5] = {0, 0, 0, 0, 0};

        while(!(File1.eof()))
        {
            string String;
            getline(File1, String, '\n');
            ArrayCountersLine[0] = ArrayCountersLine[0] + 1;
        }

        while(!(File2.eof()))
        {
            string String;
            getline(File2, String, '\n');
            ArrayCountersLine[1] = ArrayCountersLine[1] + 1;
        }

        while(!(File3.eof()))
        {
            string String;
            getline(File3, String, '\n');
            ArrayCountersLine[2] = ArrayCountersLine[2] + 1;
        }

        while(!(File4.eof()))
        {
            string String;
            getline(File4, String, '\n');
            ArrayCountersLine[3] = ArrayCountersLine[3] + 1;
        }

        while(!(File5.eof()))
        {
            string String;
            getline(File5, String, '\n');
            ArrayCountersLine[4] = ArrayCountersLine[4] + 1;
        }

        //порівняння кількості рядків
        for(int i = 1; i < 5; i = i + 1)
        {
            if(ArrayCountersLine[0] != ArrayCountersLine[i])
            {
                CreateAllFiles = true;

                break;
            }
        }

        File1.close();
        File2.close();
        File3.close();
        File4.close();
        File5.close();
    }
    else
    {
        CreateAllFiles = true;
    }

    cout << "ПОВІДОМЛЕННЯ!" << "\n";

    //перевірка на створення файлів
    if(CreateAllFiles)
    {
        ofstream File;
        File.open(NameFileMarshut);
        File.close();
        File.open(NameFileNumber);
        File.close();
        File.open(NameFilePrice);
        File.close();
        File.open(NameFileStancia);
        File.close();
        File.open(NameFileType);
        File.close();

        cout << "\t" << "Файли БД не були знайдені (чи була нецілісність даних) і створююється нова БД" << "\n";
    }
    else
    {
        cout << "\t" << "БД була перевірена і відкрита!" << "\n";
    }
}

//табуляція
string FuncCoutTab
(
    int CountTab //кількість tab
)
{
    string ReturnString = "";

    for(int i = 0; i < CountTab; i = i + 1)
    {
        ReturnString = ReturnString + "\t";
    }

    return ReturnString;
}

//вивід лінії
void FuncCoutLine
(
    int CountTab, //кількість tab
    int LengthLine, //довжина лінії
    char SymbolLine //символ лінії
)
{
    cout << "\n" << FuncCoutTab(CountTab);

    for(int i = CountTab * 8 + 1; i <= LengthLine; i = i + 1)
    {
        cout << SymbolLine;
    }

    cout << "\n\n";
}

//перевірка на долучення даних, якщо номер авіарейсу відсутній у БД
bool FuncCheckCommandOne
(
    int CountTab, //кількість tab
    string Number // номер авіарейсу
)
{
    ifstream File;
    File.open(NameFileNumber);

    while(!(File.eof()))
    {
        string RecordNumber;
        getline(File, RecordNumber, '\n');

        if(RecordNumber == Number)
        {
            File.close();

            FuncCoutLine(CountTab, LengthLineProgram, '!');

            cout << FuncCoutTab(CountTab) << "Цей номер авіарейсу існує у БД, долучення даних неможливе, операцію скасовано!" << "\n";

            FuncCoutLine(CountTab, LengthLineProgram, '!');

            return false;
        }
    }

    File.close();

    return true;
}

//перевірка на видалення редагування на існування номеру авіарейсу для подальших дій
bool FuncCheckCommandTwoThree
(
    int CountTab, //кількість tab
    string Number // номер авіарейсу
)
{
    ifstream File;
    File.open(NameFileNumber);

    while(!(File.eof()))
    {
        string RecordNumber;
        getline(File, RecordNumber, '\n');

        if(RecordNumber == Number)
        {
            File.close();

            return true;
        }
    }

    File.close();

    FuncCoutLine(CountTab, LengthLineProgram, '!');

    cout << FuncCoutTab(CountTab) << "Цей номер авіарейсу не знайдено у БД, дії з даними неможливі, операцію скасовано!" << "\n";

    FuncCoutLine(CountTab, LengthLineProgram, '!');

    return false;
}

//кількість записів у БД
int FuncCheckVoidBaseData()
{
    int CounterLines = -1; //значення "-1" присвоєно через те, що у передостанньому записі є перехід на нову строку 

    ifstream File;

    File.open(NameFileNumber);

    while(!(File.eof()))
    {
        string RecordLine;
        getline(File, RecordLine, '\n');
        
        CounterLines = CounterLines + 1;
    }

    File.close();

    return CounterLines;
}

//долучення записів у кінець файлів
void FuncAppendDataInEndFile
(
    string NameFile, //ім'я файлу
    string Value //долучаєме значення
)
{
    if(Value != "")
    {
        ofstream File;
        File.open(NameFile, ios :: app);
        File << Value << "\n";
        File.close();
    }
}

//видалення записів за номером строки
void FuncDeleteDataInFile
(
    string NameFile, //ім'я файлу
    int SaveLine //збережена строка
)
{
    //створення тимачасового файлу для збереження даних
    ofstream TempFile;
    TempFile.open("tempdata.txt");
    TempFile.close();


    //запис даних у тимчасовий файл
    ifstream File;
    File.open(NameFile);

    int CounterLines = 0;

    while(!(File.eof()))
    {
        string RecordString;
        getline(File, RecordString, '\n');

        if(CounterLines != SaveLine)
        {
            FuncAppendDataInEndFile("tempdata.txt", RecordString);
        }

        CounterLines = CounterLines + 1;
    }

    File.close();

    //перезапис даних
    TempFile.open(NameFile);
    TempFile.close();

    File.open("tempdata.txt");


    while(!(File.eof()))
    {
        string RecordString;
        getline(File, RecordString, '\n');
        FuncAppendDataInEndFile(NameFile, RecordString);
    }

    File.close();

    remove("tempdata.txt"); //видалення тимчасового файлу
}

//редагування записів за номером строки
void FuncEditDataInFile
(
    string NameFile, //ім'я файлу
    int SaveLine, //збережена строка
    string Value //нове значення
)
{
    //створення тимачасового файлу для збереження даних
    ofstream TempFile;
    TempFile.open("tempdata.txt");
    TempFile.close();


    //запис даних у тимчасовий файл
    ifstream File;
    File.open(NameFile);

    int CounterLines = 0;

    while(!(File.eof()))
    {
        string RecordString;
        getline(File, RecordString, '\n');

        if(CounterLines != SaveLine)
        {
            FuncAppendDataInEndFile("tempdata.txt", RecordString);
        }
        else
        {
            FuncAppendDataInEndFile("tempdata.txt", Value);
        }

        CounterLines = CounterLines + 1;
    }

    File.close();

    //перезапис даних
    TempFile.open(NameFile);
    TempFile.close();

    File.open("tempdata.txt");


    while(!(File.eof()))
    {
        string RecordString;
        getline(File, RecordString, '\n');
        FuncAppendDataInEndFile(NameFile, RecordString);
    }

    File.close();

    remove("tempdata.txt"); //видалення тимчасового файлу
}

//вивід даних за номером строки
void FuncOutputDataInFile
(
    string Message, //повідомлення щодо вивводу величини строки
    int CountTab, //кількість tab
    string NameFile, //ім'я файлу
    int SaveLine //збережена строка
)
{
    int CounterLines = 0; 

    ifstream File;
    File.open(NameFile);

    while(!(File.eof()))
    {
        string RecordString;
        getline(File, RecordString, '\n');

        if((SaveLine == CounterLines) && (RecordString != ""))
        {
            File.close();

            cout << FuncCoutTab(CountTab) << Message << ": " << RecordString << "\n";

            break;
        }

        CounterLines = CounterLines + 1;
    }
}

//команда 1 (долучення даних у БД)
void FuncCommandOne
(
    int CountTab //кількість tab
)
{
    FuncCoutLine(CountTab, LengthLineProgram, '+');

    cout 
        << FuncCoutTab(CountTab) << "ДОЛУЧЕННЯ ЗАПИСУ" << "\n"
        << FuncCoutTab(CountTab + 1) << "введіть номер авіарейсу: ";
    
    string Number;
    getline(cin, Number);
    cin.clear();

    if(FuncCheckCommandOne(CountTab + 2, Number))
    {
        string Marshut, Type, Stancia, Price;

        cout << FuncCoutTab(CountTab + 1) << "введіть маршут: ";
        getline(cin, Marshut);
        cin.clear();

        cout << FuncCoutTab(CountTab + 1) << "введіть тип: ";
        getline(cin, Type);
        cin.clear();

        cout << FuncCoutTab(CountTab + 1) << "введіть станцію: ";
        getline(cin, Stancia);
        cin.clear();

        cout << FuncCoutTab(CountTab + 1) << "введіть ціну квитка: ";
        getline(cin, Price);
        cin.clear();

        //долучення даних у файл
        FuncAppendDataInEndFile(NameFileMarshut, Marshut);
        FuncAppendDataInEndFile(NameFileType, Type);
        FuncAppendDataInEndFile(NameFileStancia, Stancia);
        FuncAppendDataInEndFile(NameFilePrice, Price);
        FuncAppendDataInEndFile(NameFileNumber, Number);
    }

    FuncCoutLine(CountTab, LengthLineProgram, '+');
}

//команда 2 (редагування даних у БД)
void FuncCommandTwo
(
    int CountTab //кількість tab
)
{
    FuncCoutLine(CountTab, LengthLineProgram, '@');

    cout 
        << FuncCoutTab(CountTab) << "РЕДАГУВАННЯ ЗАПИСУ" << "\n"
        << FuncCoutTab(CountTab + 1) << "введіть номер авіарейсу (його не можна редагувати): ";
    
    string Number;
    getline(cin, Number);
    cin.clear();

    if(FuncCheckCommandTwoThree(CountTab + 2, Number))
    {
        //пошук строки редагування
        int CounterLines = 0; 

        ifstream File;
        File.open(NameFileNumber);

        while(!(File.eof()))
        {
            string RecordString;
            getline(File, RecordString, '\n');

            if(Number == RecordString)
            {
                File.close();

                string Marshut, Type, Stancia, Price;

                cout << FuncCoutTab(CountTab + 1) << "введіть маршут: ";
                getline(cin, Marshut);
                cin.clear();

                cout << FuncCoutTab(CountTab + 1) << "введіть тип: ";
                getline(cin, Type);
                cin.clear();

                cout << FuncCoutTab(CountTab + 1) << "введіть станцію: ";
                getline(cin, Stancia);
                cin.clear();

                cout << FuncCoutTab(CountTab + 1) << "введіть ціну квитка: ";
                getline(cin, Price);
                cin.clear();

                //зміна даних
                FuncEditDataInFile(NameFileMarshut, CounterLines, Marshut);
                FuncEditDataInFile(NameFileType, CounterLines, Type);
                FuncEditDataInFile(NameFileStancia, CounterLines, Stancia);
                FuncEditDataInFile(NameFilePrice, CounterLines, Price);

                break;
            }

            CounterLines = CounterLines + 1;
        }
    }

    FuncCoutLine(CountTab, LengthLineProgram, '@');
}

//команда 3 (видалення даних у БД)
void FuncCommandThree
(
    int CountTab //кількість tab
)
{
    FuncCoutLine(CountTab, LengthLineProgram, '-');

    cout 
        << FuncCoutTab(CountTab) << "ВИДАЛЕННЯ ЗАПИСУ" << "\n"
        << FuncCoutTab(CountTab + 1) << "введіть номер авіарейсу: ";
    
    string Number;
    getline(cin, Number);
    cin.clear();

    if(FuncCheckCommandTwoThree(CountTab + 2, Number))
    {
        //пошук строки видалення
        int CounterLines = 0;

        ifstream File;
        File.open(NameFileNumber);

        while(!(File.eof()))
        {
            string RecordString;
            getline(File, RecordString, '\n');

            if(Number == RecordString)
            {
                File.close();
                
                FuncDeleteDataInFile(NameFileNumber, CounterLines);
                FuncDeleteDataInFile(NameFileMarshut, CounterLines);
                FuncDeleteDataInFile(NameFilePrice, CounterLines);
                FuncDeleteDataInFile(NameFileStancia, CounterLines);
                FuncDeleteDataInFile(NameFileType, CounterLines);

                break;
            }

            CounterLines = CounterLines + 1;
        }
    }

    FuncCoutLine(CountTab, LengthLineProgram, '-');
}

//команда 4 (вивід даних БД)
void FuncCommandFour
(
    int CountTab //кількість tab
)
{
    FuncCoutLine(CountTab, LengthLineProgram, '=');

    cout << FuncCoutTab(CountTab) << "ВИВІД ЗАПИСІВ" << "\n";

    //пошук вивід
    int CounterLines = 0, CountLines = FuncCheckVoidBaseData();

    while(CounterLines < CountLines)
    {
        FuncCoutLine(CountTab + 1, LengthLineProgram, '*');

        cout << FuncCoutTab(CountTab + 1) << "запис №" << CounterLines + 1 << ":" << "\n";

        FuncOutputDataInFile("номер авіарейсу", CountTab + 2, NameFileNumber, CounterLines);
        FuncOutputDataInFile("маршут", CountTab + 2, NameFileMarshut, CounterLines);
        FuncOutputDataInFile("тип літака", CountTab + 2, NameFileType, CounterLines);
        FuncOutputDataInFile("ціна квитка", CountTab + 2, NameFilePrice, CounterLines);
        FuncOutputDataInFile("станція", CountTab + 2, NameFileStancia, CounterLines);

        FuncCoutLine(CountTab + 1, LengthLineProgram, '*');

        CounterLines = CounterLines + 1;
    }

    FuncCoutLine(CountTab, LengthLineProgram, '=');
}

//команда 5 (вивід даних БД за вказаним типом літака)
void FuncCommandFive
(
    int CountTab //кількість tab
)
{
    FuncCoutLine(CountTab, LengthLineProgram, '?');

    cout 
        << FuncCoutTab(CountTab) << "ПОШУК ЗАПИСІВ ЗА ТИПОМ ЛІТАКА" << "\n"
        << FuncCoutTab(CountTab + 1) << "введіть тип: ";
    
    string Type;
    getline(cin, Type);
    cin.clear();

    bool NotFind = true; //для виводу повідомлення, якщо не буде знайдено результатів

    //пошук строки
    int CounterLines = 0; 

    ifstream File;
    File.open(NameFileType);

    while(!(File.eof()))
    {
        string RecordString;
        getline(File, RecordString, '\n');

        if(Type == RecordString)
        {
            FuncCoutLine(CountTab + 2, LengthLineProgram, '*');

            cout << FuncCoutTab(CountTab + 2) << "запис №" << CounterLines + 1 << ":" << "\n";

            FuncOutputDataInFile("номер авіарейсу", CountTab + 3, NameFileNumber, CounterLines);
            FuncOutputDataInFile("маршут", CountTab + 3, NameFileMarshut, CounterLines);
            FuncOutputDataInFile("тип літака", CountTab + 3, NameFileType, CounterLines);
            FuncOutputDataInFile("ціна квитка", CountTab + 3, NameFilePrice, CounterLines);
            FuncOutputDataInFile("станція", CountTab + 3, NameFileStancia, CounterLines);

            FuncCoutLine(CountTab + 2, LengthLineProgram, '*');

            NotFind = false;
        }

        CounterLines = CounterLines + 1;
    }

    File.close();

    if(NotFind)
    {
        cout << FuncCoutTab(CountTab + 2) << "дані для такого типу літака не знайдені" << "\n";
    }

    FuncCoutLine(CountTab, LengthLineProgram, '?');
}

//перевірка введеної команди 
bool FuncCheckInputCommand
(
    int CountTab, //кількість tab
    string Command //команда
)
{
    for(int i = 0; i <= 5; i = i + 1)
    {
        if(Command == to_string(i))
        {
            return true;
        }
    }

    cout << FuncCoutTab(CountTab) << "команда введена неправильно!" << "\n";

    return false;
}

//створення звіту 
void FuncCreateReport()
{
    ofstream FileReport;
    FileReport.open(NameFileReport);

    int CounterIteration = FuncCheckVoidBaseData();

    ifstream File1, File2, File3, File4, File5;

    File1.open(NameFileMarshut);
    File2.open(NameFileNumber);
    File3.open(NameFilePrice);
    File4.open(NameFileStancia);
    File5.open(NameFileType);

    int CounterLineFiles = 0;

    while(CounterLineFiles < CounterIteration)
    {
        string Str1, Str2, Str3, Str4, Str5;
        getline(File1, Str1);
        getline(File2, Str2);
        getline(File3, Str3);
        getline(File4, Str4);
        getline(File5, Str5);

        FileReport 
            << "запис №" << CounterLineFiles + 1 << ":" << "\n"
            << "\t" << "маршут: " << Str1 << "\n"
            << "\t" << "номер авіарейсу: " << Str2 << "\n"
            << "\t" << "ціна квитка: " << Str3 << "\n"
            << "\t" << "станція: " << Str4 << "\n"
            << "\t" << "тип літака: " << Str5 << "\n\n";

        CounterLineFiles = CounterLineFiles + 1;
    }

    File1.close();
    File2.close();
    File3.close();
    File4.close();
    File5.close();

    FileReport.close();
}