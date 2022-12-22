from msvcrt import getch
from math import log10, fabs

#у прикладі не задовільне ОДЗ для заданого діапазону, я долучив для наглядності до числа логарифму модуль

Xmin = 7.5 
Xmax = 10
Xstep = 0.5

#використання if (за допомогою умови while(True)) 
print("Використання if (за допомогою умови while(True)):")

x = Xmin

while(True):
    if(x <= Xmax):
        y = log10(  fabs( (1 - x) / (1 + x) ) )
        print("\t", "x:", x, "=>", "y:", y)

        x = x + Xstep
    else:
        break #вихід з циклу

#використання циклу while
print("\n", "Використання циклу while", sep = "")

x = Xmin

while(x <= Xmax):
    y = log10(  fabs( (1 - x) / (1 + x) ) )
    print("\t", "x:", x, "=>", "y:", y)

    x = x + Xstep

#використання циклу for
print("\n", "Використання циклу for", sep = "")

x = Xmin

for i in range(0, int( (Xmax - Xmin + 0.5) / Xstep), 1):
    y = log10(  fabs( (1 - x) / (1 + x) ) )
    print("\t", "x:", x, "=>", "y:", y)

    x = x + Xstep

getch()