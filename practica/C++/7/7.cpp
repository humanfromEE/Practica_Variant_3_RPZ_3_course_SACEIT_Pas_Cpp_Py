#include <iostream>
#include <cmath>

#include <windows.h>
#include <conio.h>
#include <graphics.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //налаштування вікна
    int gd = DETECT, gm;
  
    initgraph(&gd, &gm, "");
  
    line(0, 250, 500, 250); //Ox
    line(480, 240, 500, 250);
    line(480, 260, 500, 250);
    outtextxy(485, 220, "X");

    line(250, 0, 250, 500); //Oy
    line(250, 0, 240, 20);
    line(250, 0, 260, 20);
    outtextxy(265, 5, "Y");

    double x = 0, y = pow(x, 1.0 / 3) + pow( sin(x), 2), h = 0.01;

    const double pi = 3.14;

    //вивід штрихованого відрізку [0; 2п]
    outtextxy(240, 255, "0");
    outtextxy(240 + 2 * pi * 30, 255, "2п");

    int Counter = 1;
    for(int i = 0; i < 490; i = i + 10)
    {
        if((Counter % 2) != 0)
        {
            line(250 + 2 * pi * 30, i, 250 + 2 * pi * 30, i + 10);
        }
        
        Counter = Counter + 1;
    }
    
    while( (x >= 0) && ( x <= (2 * pi) ) )
    {
        putpixel(round(250 + x * 30), round(250 - y * 30), RED); //я домножив на 30, щоб збільшити масштаб графіку функції

        y = pow(x, 1.0 / 3) + pow( sin(x), 2);
        x = x + h;
    }
  
    getch();
  
    closegraph();

    return 0;
}