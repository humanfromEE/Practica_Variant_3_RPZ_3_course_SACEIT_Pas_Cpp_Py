from msvcrt import getch
from math import fabs

Array = []

#ввід елементів списку
print("Ввід списку (мінімум 5 елементів):")

while(True):  
    print("\t", "елемент №", len(Array) + 1, end = ": ")
    Array.append(float(input()))

    Answer = input("\t\tбажаєте долучити ще елемент? (\"+\" - так): ")

    #умова на долучення елементів
    if(Answer != "+"):
        #умова на вихід з циклу
        if(len(Array) > 4):
            break

        else:
            print("\t\t\t", "введіть мінімум 5 елементів", end = "\n\n\n")
    

SummPlus = 0.0
SummMinus = 0.0

#цикл пошуку
for i in range(0, len(Array), 1):

    if(Array[i] > 0):
        SummPlus = SummPlus + Array[i]
    
    else:
        SummMinus = SummMinus + Array[i]
    
print("\n", "Результати:", sep = "")
print("\t", "Сума додатніх чисел:", SummPlus)
print("\t", "Сума від'ємних чисел:", SummMinus)
print("\t", "Модуль(додатні) - модуль(від'ємні):", fabs(SummPlus) - fabs(SummMinus))

getch()