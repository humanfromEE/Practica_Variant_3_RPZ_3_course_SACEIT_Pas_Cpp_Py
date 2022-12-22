from msvcrt import getch
from random import randint

CounterArray = 0 #лічильник масиву
Array = []
CopyArray = []

#генерування масиву
def FuncGenerateArray(): 
    print("Заповнення масиву випадковими числами:", sep = "", end = "\n\t")
    for i in range(0, CounterArray, 1):
        TempArray = []

        for j in range(0, CounterArray, 1):
            TempArray.append(randint(0, 9))
            print("елемент №", i + 1, "-", j + 1, ": ", TempArray[j], sep = "", end = "\n\t")

        Array.append(TempArray)

    print(end = "\n\n\n")

#вивід масиву
def FuncOutputArray(Message):
    print(Message, ":", sep = "")
    for i in range(0, len(Array), 1):
        print(end = "\t")

        for j in range(0, len(Array), 1):
            print(Array[i][j], end = " ")

        print()

    print(end = "\n\n\n")

#копіювання масиву
def FuncCopyArray():
    for i in range(0, len(Array), 1):
        for j in range(0, len(Array), 1):
            CopyArray.append(Array[i][j])

#вивід копіювального масиву
def FuncOutputCopyArray(Message):
    print(Message, ":", sep = "", end = "\n\t")

    for i in range(0, len(CopyArray), 1):
        if(((i + 1) % 25 ) == 0):
            print(CopyArray[i], end = "\n\t")
        else:
            print(CopyArray[i], end = " ")

    print(end = "\n\n\n")

#сортування масиву методом вибору
def FuncSortArray():
    for i in range(0, len(CopyArray) - 1, 1):
        for j in range(i + 1, len(CopyArray), 1):
            if(CopyArray[i] > CopyArray[j]):
                TempVar = CopyArray[i]
                CopyArray[i] = CopyArray[j]
                CopyArray[j] = TempVar



#функція створення потрібної матриці зі завдання
def FuncCreateTrueMatrix():
    CounterCopyArray = 0; #лічильник масиву копії

    for i in range(0, len(Array), 1):
        #непарний рядок буде за спаданням
        if(((i + 1) % 2) != 0):
            for j in range(len(Array) - 1, -1, -1):
                Array[i][j] = CopyArray[CounterCopyArray]
                CounterCopyArray = CounterCopyArray + 1
        #парний рядок буде за зростанням
        else:
            for j in range(0, len(Array), 1):
                Array[i][j] = CopyArray[CounterCopyArray]
                CounterCopyArray = CounterCopyArray + 1

#ГОЛОВНА ПРОГРАМА
#цикл вводу розмірності матриці
while(True):
    CounterArray = int(input("Введіть розмірність матриці: "))
    
    if( (CounterArray <= 10) and (CounterArray > 1) ):
        break
    else:
        print("\t Розмірність повинна бути в діпазоні [2 10]", end = "\n\n")

FuncGenerateArray()
FuncOutputArray("Вивід матриці до сортування")
FuncCopyArray()
FuncOutputCopyArray("Вивід масиву значень матриці")
FuncSortArray()
FuncOutputCopyArray("Вивід масиву значень матриці у сортованому вигляді")
FuncCreateTrueMatrix()
FuncOutputArray("Вивід матриці з сортування для завдання")

getch()