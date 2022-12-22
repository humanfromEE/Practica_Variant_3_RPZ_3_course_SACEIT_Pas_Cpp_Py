from math import pow, cos
from msvcrt import getch

#функція
def FuncY(x):
    return ( pow(x, 5) * pow( cos(1.0 / x), 2) )

#головна програма
x = float(input("Ведіть x: "))
y = float(input("Ведіть y: "))

A = (pow(FuncY(x), 2) + pow(FuncY(y), 2)) / 2
print("\n", "Значення виразу A: ", A, sep = "")

getch()