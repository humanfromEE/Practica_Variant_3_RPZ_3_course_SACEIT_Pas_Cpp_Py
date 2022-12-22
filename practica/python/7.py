from tkinter import *
from math import pow, sin, pi
 
root = Tk()
root.geometry("500x500")

Graphic = Canvas(width = 500, height = 500)

Graphic.pack()

Graphic.create_line(0, 250, 500, 250) #Ox
Graphic.create_line(480, 240, 500, 250)
Graphic.create_line(480, 260, 500, 250)
Graphic.create_text(485, 220, fill = "black", font = "10", text = "X")

Graphic.create_line(240, 0, 240, 500) #Oy
Graphic.create_line(240, 0, 230, 20)
Graphic.create_line(240, 0, 250, 20)
Graphic.create_text(260, 15, fill = "black", font = "10", text = "Y")

x = 0.0
y = 0.0
h = 0.01

#вивід штрихованого відрізку [0 2п]
Graphic.create_text(230, 260, fill = "black", font = "10", text = "0")
Graphic.create_text(round(240 + 2 * pi * 30), 260, fill = "black", font = "10", text = "2п")

Counter = 1
for i in range(0, 490, 10):
    if((Counter % 2) != 0):
        Graphic.create_line(round(240 + 2 * pi * 30), i, round(240 + 2 * pi * 30), i + 10)
    
    Counter = Counter + 1

#малювання графіку
while( (x >= 0) and ( x <= (2 * pi) ) ):
    #я домножив на 30, щоб збільшити масштаб графіку функції
    Graphic.create_oval(round(240 + x * 30), round(240 - y * 30), round(240 + x * 30), round(240 - y * 30), fill = "red")

    y = pow(x, 1.0 / 3) + pow( sin(x), 2)
    x = x + h

getch = input()