#include <iostream>

#include <windows.h>
#include <conio.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "������ �: ";
    int x;
    cin >> x;

    if(x > 0)
    {
        x = x + 1;
    }
    else if(x < 0)
    {
        x = x - 2;
    }
    else
    {
        x = 10;
    }

    cout << "ϳ��� ��������� ����� ��� �: " << x << "\n";

    getch();

    return 0;
}