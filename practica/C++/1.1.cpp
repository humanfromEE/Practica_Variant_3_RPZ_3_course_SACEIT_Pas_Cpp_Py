#include <iostream>
#include <cmath>

#include <windows.h>
#include <conio.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "������ x: ";
    double x;
    cin >> x;

    double y = log2( fabs( (pow(x, 2) - 4) / (pow(x, 2) - 1) ) ); 
    cout << "���������� ������� ����� y: " << y << "\n";

    getch();

    return 0;
}