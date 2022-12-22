from msvcrt import getch
from math import pow, sin, cos, fabs

print("Введіть координати точки M1:")
x1 = float(input("\t x1: "))
y1 = float(input("\t y1: "))

print("\n", "Введіть координати точки M2:")
x2 = float(input("\t x2: "))
y2 = float(input("\t y2: "))

#розрахунок відстані
d = pow( ( pow( (x2 - x1), 2) + pow( (y2 - y1), 2) ), 1.0 / 2)
print("\n", "Відстань між точками рівна d:", d, sep = "")


#розрахунок формули
y = ( pow( sin(x2 + x1), 2) + cos( fabs(x2 - y2) ) ) / (cos(d) + pow( (4.75 + 3.2 * pow(d, 2)), 1.0 / 2) )
print("\n", "Розрахунок формули рівний y:", y, sep = "")

getch()