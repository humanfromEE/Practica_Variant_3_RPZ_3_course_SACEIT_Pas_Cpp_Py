from msvcrt import getch
from random import randint

Array = []

#ввід листа
print("Ввід листа 4х3:")

for i in range(0, 4, 1):
    ColumnArray = []

    for j in range(0, 3, 1):
        ColumnArray.append(randint(0, 9))
        print("\t", "елемент №", i + 1, j + 1, ": ", ColumnArray[j], sep = "")

    Array.append(ColumnArray)
    
print(end = "\n\n\n")

#вивід листа
print("Вивід листа 4х3:")

for i in range(0, len(Array), 1):
    print(end = "\t")
    
    for j in range(0, len(Array[i]), 1):
        print(Array[i][j], end = " ")  
    
    print()

print(end = "\n\n\n")

#сортування рядків
for i in range(0, len(Array), 1): 

    #сортування методом бульбашки
    for j in range(1, len(Array[0]), 1):
        for k in range(0, (len(Array[0]) - j), 1):
            if(Array[i][k] > Array[i][k + 1]):
                TempVar = Array[i][k]
                Array[i][k] = Array[i][k + 1]
                Array[i][k + 1] = TempVar

#вивід листа
print("Вивід листа 4х3:")

for i in range(0, len(Array), 1):
    print(end = "\t")
    
    for j in range(0, len(Array[i]), 1):
        print(Array[i][j], end = " ")  
    
    print()

getch()