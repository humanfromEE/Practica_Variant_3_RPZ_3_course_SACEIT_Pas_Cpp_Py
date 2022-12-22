from msvcrt import getch
from math import factorial

#використання if (за допомогою while(True))
print("Використання if (за допомогою while(True)):")

y = 0
i = 1

while(True):
    if(i <= 10):
        y = y + 1.0 / factorial(i)
        print("\t", "i:", i, "=>", "фактроіал:", factorial(i), "=>", "y:", y)

        i = i + 1

    else:
        break #вихід з циклу

#використання циклу while
print("\n", "Використання циклу while:", sep = "")

y = 0
i = 1

while(i <= 10):
    y = y + 1.0 / factorial(i)

    print("\t", "i:", i, "=>", "фактроіал:", factorial(i), "=>", "y:", y)
    
    i = i + 1

#використання циклу for
y = 0

print("\n", "Використання циклу for:", sep = "")

for i in range(1, 10 + 1, 1):
    y = y + 1.0 / factorial(i)
    print("\t", "i:", i, "=>", "фактроіал:", factorial(i), "=>", "y:", y)

getch()