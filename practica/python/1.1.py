from msvcrt import getch
from math import pow, log2, fabs

x = float(input("Введіть х: "))

#розрахунок формули
y = log2( fabs( (pow(x, 2) - 4) / (pow(x, 2) - 1) ) )
print("Розрахунок формули рівний y: ", y, sep = "")

getch()