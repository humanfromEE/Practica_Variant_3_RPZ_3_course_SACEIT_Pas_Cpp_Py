from msvcrt import getch
from math import pi, pow, atan, log, exp, tan

x = float(input("Введіть х: "))

#розрахунок параметрів
a = pow( (3 * log(7)), 1.0 / 2)
b = tan(pi / 3)
c = exp(-2)

print("\n", "Значення параметрів", sep = "")
print("\t", "a = ", a, sep = "")
print("\t", "b = ", b, sep = "")
print("\t", "c = ", c, sep = "", end = "\n\n")

#умови завдання
if(x > a):
    y = atan(pow(2, x)) + a * log(b * c)
    print("Розрахунок формули х > a, y:", y)

elif(x == a):
    y = exp(x - b) + log( pow( (a * c), 1.0 / 2))
    print("Розрахунок формули х = a, y:", y)

else:
    y = pow( (pow(a, 2) + pow(b, 2)), 1.0 / 3) + exp(x - c) * log(x)
    print("Розрахунок формули х < a, y:", y)

getch()