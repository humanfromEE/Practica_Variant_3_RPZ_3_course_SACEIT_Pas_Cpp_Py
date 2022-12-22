from msvcrt import getch

UserText = ""

FirstIndex = -1 #індекс першої дужки
SecondIndex = -1 #індекс другої дужки
CounterFirstIndex = 0 #кількість перших дужок
CounterSecondIndex = 0 #кількість других дужок

#ввід тексту
while(True):
    UserText = input("Введіть текст:\n\t")

    FirstIndex = -1 #значення "-1" для визначння, якщо не буде дужок у тексті
    SecondIndex = -1 #значення "-1" для визначння, якщо не буде дужок у тексті
    CounterFirstIndex = 0
    CounterSecondIndex = 0

    #цикл пошуку дужок і їх індекс у строці тексту
    for i in range(0, len(UserText), 1):
        if(UserText[i] == "("):
            FirstIndex = i
            CounterFirstIndex = CounterFirstIndex + 1
        
        if(UserText[i] == ")"):
            SecondIndex = i
            CounterSecondIndex = CounterSecondIndex + 1

    #якщо у тексті немає дужок
    if( (FirstIndex == -1) and (SecondIndex == -1) ):
        print("\t", "У тексті відсутні дужки", sep = "", end = "\n\n")
    
    #якщо немає дужки "("
    elif(FirstIndex == -1):
        print("\t", "У тексті немає дужки: \"(\"", sep = "", end = "\n\n")
    
    #якщо немає дужки ")"
    elif(SecondIndex == -1):
        print("\t", "У тексті немає дужки: \")\"", sep = "", end = "\n\n")
    
    #якщо є кілька дужок "("
    elif(CounterFirstIndex != 1):
        print("\t", "У тексті є декілька дужок: \"(\"", sep = "", end = "\n\n")
    
    #якщо є кілька дужок ")"
    elif(CounterSecondIndex != 1):
        print("\t", "У тексті є декілька дужок: \")\"", sep = "", end = "\n\n")

    #якщо дужки стоять ") текст ("
    elif(FirstIndex > SecondIndex):
        print("\t", "У тексті введено фраграгмент: \"текст ) текст ( текст\"", sep = "", end = "\n\n")

    #вихід з циклу
    else:
        break
    
CorrectText = ""

#копіювання першої частини
for i in range(0, FirstIndex, 1):
    CorrectText = CorrectText + UserText[i]

#копіювання другої частини
for i in range(SecondIndex + 1, len(UserText), 1):
    CorrectText = CorrectText + UserText[i]

print("\n\n", "Текст без дужок:", "\n\t", CorrectText, sep = "")

getch()