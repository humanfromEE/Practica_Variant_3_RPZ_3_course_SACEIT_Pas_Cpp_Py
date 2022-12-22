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
    //�������� �������� ����� � �������� ����� - void FuncCheckFiles

    //��������� - string FuncCoutTab
    //���� �� - void FuncCoutLine

    //�������� �� ��������� �����, ���� ����� �������� ������� � �� - bool FuncCheckCommandOne
    //�������� �� ��������� ����������� �� ��������� ������ �������� ��� ��������� �� - bool FuncCheckCommandTwoThree 
    //������� ������ � �� - int FuncCheckVoidBaseData
    //��������� ������ � ����� ����� - void FuncAppendDataInEndFile
    //��������� ������ �� ������� ������ - void FuncDeleteDataInFile
    //����������� ������ �� ������� ������ - void FuncEditDataInFile
    //���� ����� �� ������� ������ - void FuncOutputDataInFile

    //������� 1 (��������� ����� � ��) - void FuncCommandOne
    //������� 2 (����������� ����� � ��) - void FuncCommandTwo
    //������� 3 (��������� ����� � ��) - void FuncCommandThree
    //������� 4 (���� ����� ��) - void FuncCommandFour
    //������� 5 (���� ����� �� �� �������� ����� �����) - void FuncCommandFive

    //�������� ������� ������� - bool FuncCheckInputCommand
    //��������� ���� - void FuncCreateReport
*/

//����� �����
    string NameFileReport = "���.txt";
    string NameFileNumber = "����� ��������.txt";
    string NameFileMarshut = "�������.txt";
    string NameFileType = "��� �����.txt";
    string NameFileStancia = "�������.txt";
    string NameFilePrice = "���� �����.txt";

//������� ���
    int LengthLineProgram = 125; 

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

//�������� �������� ����� � �������� ����� 
void FuncCheckFiles();

//���������
string FuncCoutTab
(
    int CountTab //������� tab
);

//���� ��
void FuncCoutLine
(
    int CountTab, //������� tab
    int LengthLine, //������� ��
    char SymbolLine //������ ��
);

//�������� �� ��������� �����, ���� ����� �������� ������� � ��
bool FuncCheckCommandOne
(
    int CountTab, //������� tab
    string Number // ����� ��������
);

//�������� �� ��������� ����������� �� ��������� ������ �������� ��� ��������� ��
bool FuncCheckCommandTwoThree
(
    int CountTab, //������� tab
    string Number // ����� ��������
);

//������� ������ � ��
int FuncCheckVoidBaseData();

//��������� ������ � ����� �����
void FuncAppendDataInEndFile
(
    string NameFile, //��'� �����
    string Value //�������� ��������
);

//��������� ������ �� ������� ������
void FuncDeleteDataInFile
(
    string NameFile, //��'� �����
    int SaveLine //��������� ������
);

//����������� ������ �� ������� ������
void FuncEditDataInFile
(
    string NameFile, //��'� �����
    int SaveLine, //��������� ������
    string Value //���� ��������
);

//���� ����� �� ������� ������
void FuncOutputDataInFile
(
    string Message, //����������� ���� ������� �������� ������
    int CountTab, //������� tab
    string NameFile, //��'� �����
    int SaveLine //��������� ������
);

//������� 1 (��������� ����� � ��)
void FuncCommandOne
(
    int CountTab //������� tab
);

//������� 2 (����������� ����� � ��)
void FuncCommandTwo
(
    int CountTab //������� tab
);

//������� 3 (��������� ����� � ��)
void FuncCommandThree
(
    int CountTab //������� tab
);

//������� 4 (���� ����� ��)
void FuncCommandFour
(
    int CountTab //������� tab
);

//������� 5 (���� ����� �� �� �������� ����� �����)
void FuncCommandFive
(
    int CountTab //������� tab
);

//�������� ������� ������� 
bool FuncCheckInputCommand
(
    int CountTab, //������� tab
    string Command //�������
);

//��������� ���� 
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
            << "����:" << "\n"
            << "\t" << "1 - �������� �����" << "\n"
            << "\t" << "2 - ���������� �����" << "\n"
            << "\t" << "3 - �������� �����" << "\n"
            << "\t" << "4 - ������� ������" << "\n"
            << "\t" << "5 - ������� ����� �� �������� �����" << "\n"
            << "\t" << "0 - ����� � ��������" << "\n"
            << "\t\t\t" << "������� ������ � ��: " << FuncCheckVoidBaseData() << "\n";
        
        cout << "\t\t" << "��� ����: ";
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
            else if(Command != "0") //���� �����������, �� ��� ��������� ������� ������� ���� � 1 �����
            {
                cout << FuncCoutTab(3) << "��� ���� ������� ������� ����� 1 ����� � ��, �������� �����" << "\n";
            }
            else
            {
                cout << FuncCoutTab(3) << "��ղ� � ��������" << "\n"
                     << FuncCoutTab(4) << "�� ��������� ����� ��� ���������� �����������" << "\n"
                     << FuncCoutTab(4) << "������ �������� ���? (\"+\" - ���): ";
                string Answer;
                getline(cin, Answer);
                cin.clear();

                if(Answer == "+")
                {
                    FuncCreateReport();
                    cout << FuncCoutTab(5) << "����� �����: \"" << NameFileReport << "\"" << "\n";
                }

                FuncCoutLine(0, LengthLineProgram, '`');

                break;
            }

            FuncCoutLine(0, LengthLineProgram, '`');
        }
    }

    cout << "\n\n\n\n" << "��� �������� ���� ��������� ����-��� ������" << "\n";
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

//�������� �������� ����� � �������� �����
void FuncCheckFiles()
{
    bool CreateAllFiles = false; //�����, ��� ������� �� ��������� ��� �����

    ifstream File1, File2, File3, File4, File5;

    File1.open(NameFileMarshut);
    File2.open(NameFileNumber);
    File3.open(NameFilePrice);
    File4.open(NameFileStancia);
    File5.open(NameFileType);

    //�������� ��������� ��� �����
    if( File1.is_open() && File2.is_open() && File3.is_open() && File4.is_open() && File5.is_open())
    {
        //��������� ������� ����� ��� ������� �����
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

        //��������� ������� �����
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

    cout << "��²��������!" << "\n";

    //�������� �� ��������� �����
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

        cout << "\t" << "����� �� �� ���� ������� (�� ���� ���������� �����) � ������������ ���� ��" << "\n";
    }
    else
    {
        cout << "\t" << "�� ���� ��������� � �������!" << "\n";
    }
}

//���������
string FuncCoutTab
(
    int CountTab //������� tab
)
{
    string ReturnString = "";

    for(int i = 0; i < CountTab; i = i + 1)
    {
        ReturnString = ReturnString + "\t";
    }

    return ReturnString;
}

//���� ��
void FuncCoutLine
(
    int CountTab, //������� tab
    int LengthLine, //������� ��
    char SymbolLine //������ ��
)
{
    cout << "\n" << FuncCoutTab(CountTab);

    for(int i = CountTab * 8 + 1; i <= LengthLine; i = i + 1)
    {
        cout << SymbolLine;
    }

    cout << "\n\n";
}

//�������� �� ��������� �����, ���� ����� �������� ������� � ��
bool FuncCheckCommandOne
(
    int CountTab, //������� tab
    string Number // ����� ��������
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

            cout << FuncCoutTab(CountTab) << "��� ����� �������� ���� � ��, ��������� ����� ���������, �������� ���������!" << "\n";

            FuncCoutLine(CountTab, LengthLineProgram, '!');

            return false;
        }
    }

    File.close();

    return true;
}

//�������� �� ��������� ����������� �� ��������� ������ �������� ��� ��������� ��
bool FuncCheckCommandTwoThree
(
    int CountTab, //������� tab
    string Number // ����� ��������
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

    cout << FuncCoutTab(CountTab) << "��� ����� �������� �� �������� � ��, 䳿 � ������ ��������, �������� ���������!" << "\n";

    FuncCoutLine(CountTab, LengthLineProgram, '!');

    return false;
}

//������� ������ � ��
int FuncCheckVoidBaseData()
{
    int CounterLines = -1; //�������� "-1" �������� ����� ��, �� � ��������������� ����� � ������� �� ���� ������ 

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

//��������� ������ � ����� �����
void FuncAppendDataInEndFile
(
    string NameFile, //��'� �����
    string Value //�������� ��������
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

//��������� ������ �� ������� ������
void FuncDeleteDataInFile
(
    string NameFile, //��'� �����
    int SaveLine //��������� ������
)
{
    //��������� ������������ ����� ��� ���������� �����
    ofstream TempFile;
    TempFile.open("tempdata.txt");
    TempFile.close();


    //����� ����� � ���������� ����
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

    //��������� �����
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

    remove("tempdata.txt"); //��������� ����������� �����
}

//����������� ������ �� ������� ������
void FuncEditDataInFile
(
    string NameFile, //��'� �����
    int SaveLine, //��������� ������
    string Value //���� ��������
)
{
    //��������� ������������ ����� ��� ���������� �����
    ofstream TempFile;
    TempFile.open("tempdata.txt");
    TempFile.close();


    //����� ����� � ���������� ����
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

    //��������� �����
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

    remove("tempdata.txt"); //��������� ����������� �����
}

//���� ����� �� ������� ������
void FuncOutputDataInFile
(
    string Message, //����������� ���� ������� �������� ������
    int CountTab, //������� tab
    string NameFile, //��'� �����
    int SaveLine //��������� ������
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

//������� 1 (��������� ����� � ��)
void FuncCommandOne
(
    int CountTab //������� tab
)
{
    FuncCoutLine(CountTab, LengthLineProgram, '+');

    cout 
        << FuncCoutTab(CountTab) << "��������� ������" << "\n"
        << FuncCoutTab(CountTab + 1) << "������ ����� ��������: ";
    
    string Number;
    getline(cin, Number);
    cin.clear();

    if(FuncCheckCommandOne(CountTab + 2, Number))
    {
        string Marshut, Type, Stancia, Price;

        cout << FuncCoutTab(CountTab + 1) << "������ ������: ";
        getline(cin, Marshut);
        cin.clear();

        cout << FuncCoutTab(CountTab + 1) << "������ ���: ";
        getline(cin, Type);
        cin.clear();

        cout << FuncCoutTab(CountTab + 1) << "������ �������: ";
        getline(cin, Stancia);
        cin.clear();

        cout << FuncCoutTab(CountTab + 1) << "������ ���� ������: ";
        getline(cin, Price);
        cin.clear();

        //��������� ����� � ����
        FuncAppendDataInEndFile(NameFileMarshut, Marshut);
        FuncAppendDataInEndFile(NameFileType, Type);
        FuncAppendDataInEndFile(NameFileStancia, Stancia);
        FuncAppendDataInEndFile(NameFilePrice, Price);
        FuncAppendDataInEndFile(NameFileNumber, Number);
    }

    FuncCoutLine(CountTab, LengthLineProgram, '+');
}

//������� 2 (����������� ����� � ��)
void FuncCommandTwo
(
    int CountTab //������� tab
)
{
    FuncCoutLine(CountTab, LengthLineProgram, '@');

    cout 
        << FuncCoutTab(CountTab) << "����������� ������" << "\n"
        << FuncCoutTab(CountTab + 1) << "������ ����� �������� (���� �� ����� ����������): ";
    
    string Number;
    getline(cin, Number);
    cin.clear();

    if(FuncCheckCommandTwoThree(CountTab + 2, Number))
    {
        //����� ������ �����������
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

                cout << FuncCoutTab(CountTab + 1) << "������ ������: ";
                getline(cin, Marshut);
                cin.clear();

                cout << FuncCoutTab(CountTab + 1) << "������ ���: ";
                getline(cin, Type);
                cin.clear();

                cout << FuncCoutTab(CountTab + 1) << "������ �������: ";
                getline(cin, Stancia);
                cin.clear();

                cout << FuncCoutTab(CountTab + 1) << "������ ���� ������: ";
                getline(cin, Price);
                cin.clear();

                //���� �����
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

//������� 3 (��������� ����� � ��)
void FuncCommandThree
(
    int CountTab //������� tab
)
{
    FuncCoutLine(CountTab, LengthLineProgram, '-');

    cout 
        << FuncCoutTab(CountTab) << "��������� ������" << "\n"
        << FuncCoutTab(CountTab + 1) << "������ ����� ��������: ";
    
    string Number;
    getline(cin, Number);
    cin.clear();

    if(FuncCheckCommandTwoThree(CountTab + 2, Number))
    {
        //����� ������ ���������
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

//������� 4 (���� ����� ��)
void FuncCommandFour
(
    int CountTab //������� tab
)
{
    FuncCoutLine(CountTab, LengthLineProgram, '=');

    cout << FuncCoutTab(CountTab) << "��²� ����Ѳ�" << "\n";

    //����� ����
    int CounterLines = 0, CountLines = FuncCheckVoidBaseData();

    while(CounterLines < CountLines)
    {
        FuncCoutLine(CountTab + 1, LengthLineProgram, '*');

        cout << FuncCoutTab(CountTab + 1) << "����� �" << CounterLines + 1 << ":" << "\n";

        FuncOutputDataInFile("����� ��������", CountTab + 2, NameFileNumber, CounterLines);
        FuncOutputDataInFile("������", CountTab + 2, NameFileMarshut, CounterLines);
        FuncOutputDataInFile("��� �����", CountTab + 2, NameFileType, CounterLines);
        FuncOutputDataInFile("���� ������", CountTab + 2, NameFilePrice, CounterLines);
        FuncOutputDataInFile("�������", CountTab + 2, NameFileStancia, CounterLines);

        FuncCoutLine(CountTab + 1, LengthLineProgram, '*');

        CounterLines = CounterLines + 1;
    }

    FuncCoutLine(CountTab, LengthLineProgram, '=');
}

//������� 5 (���� ����� �� �� �������� ����� �����)
void FuncCommandFive
(
    int CountTab //������� tab
)
{
    FuncCoutLine(CountTab, LengthLineProgram, '?');

    cout 
        << FuncCoutTab(CountTab) << "����� ����Ѳ� �� ����� ˲����" << "\n"
        << FuncCoutTab(CountTab + 1) << "������ ���: ";
    
    string Type;
    getline(cin, Type);
    cin.clear();

    bool NotFind = true; //��� ������ �����������, ���� �� ���� �������� ����������

    //����� ������
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

            cout << FuncCoutTab(CountTab + 2) << "����� �" << CounterLines + 1 << ":" << "\n";

            FuncOutputDataInFile("����� ��������", CountTab + 3, NameFileNumber, CounterLines);
            FuncOutputDataInFile("������", CountTab + 3, NameFileMarshut, CounterLines);
            FuncOutputDataInFile("��� �����", CountTab + 3, NameFileType, CounterLines);
            FuncOutputDataInFile("���� ������", CountTab + 3, NameFilePrice, CounterLines);
            FuncOutputDataInFile("�������", CountTab + 3, NameFileStancia, CounterLines);

            FuncCoutLine(CountTab + 2, LengthLineProgram, '*');

            NotFind = false;
        }

        CounterLines = CounterLines + 1;
    }

    File.close();

    if(NotFind)
    {
        cout << FuncCoutTab(CountTab + 2) << "��� ��� ������ ���� ����� �� �������" << "\n";
    }

    FuncCoutLine(CountTab, LengthLineProgram, '?');
}

//�������� ������� ������� 
bool FuncCheckInputCommand
(
    int CountTab, //������� tab
    string Command //�������
)
{
    for(int i = 0; i <= 5; i = i + 1)
    {
        if(Command == to_string(i))
        {
            return true;
        }
    }

    cout << FuncCoutTab(CountTab) << "������� ������� �����������!" << "\n";

    return false;
}

//��������� ���� 
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
            << "����� �" << CounterLineFiles + 1 << ":" << "\n"
            << "\t" << "������: " << Str1 << "\n"
            << "\t" << "����� ��������: " << Str2 << "\n"
            << "\t" << "���� ������: " << Str3 << "\n"
            << "\t" << "�������: " << Str4 << "\n"
            << "\t" << "��� �����: " << Str5 << "\n\n";

        CounterLineFiles = CounterLineFiles + 1;
    }

    File1.close();
    File2.close();
    File3.close();
    File4.close();
    File5.close();

    FileReport.close();
}