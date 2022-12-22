from msvcrt import getch

#структура
DataStruct = {
    "Marka" : [], #марка автомобіля
    "PIB" : [], #піб власника
    "Year" : [], #рік випуску
    "Number" : [] #реєстраційний номер (5 символів)
}

#функція перевірки року випуску
def FuncCheckYear(Y):
    if( (Y <= 2022) and (Y >= 1900) ):
        return True

    print("\t\t\t", "Введіть рік в діапазоні [1900 2022]")
    return False

#функція перевірки реєстраційного номеру
def FuncCheckNumber(N):
    if ( not ( (N <= 99999) and (N >= 10000) ) ):
        print("\t\t\t", "Введіть рік в діапазоні [100000 99999]")
        return False
    
    for i in range(0, len(DataStruct["Number"]), 1):
        if(DataStruct["Number"][i] == N):
            print("\t\t\t", "Реєстраційний номер належить іншому користувачу")
            return False

    return True

#ГОЛОВНА ПРОГРАМА
#цикл вводу користувачів
while(True):
    print("\t", "Введіть дані користувача №", len(DataStruct["Marka"]) + 1)
    M = input("\t\t марка: ")
    P = input("\t\t піб: ")
    Y = int(input("\t\t рік випуску: "))
    N = int(input("\t\t реєстраційний номер: "))

    #перевірка на правильність введення даних і долучення користвувача
    if( FuncCheckYear(Y) and FuncCheckNumber(N) ):
        print("\t\t\t", "Користувач долучений!")
        
        DataStruct["Marka"].append(M)
        DataStruct["PIB"].append(P)
        DataStruct["Year"].append(Y)
        DataStruct["Number"].append(N)

    print("\n\n\t", "-----------", end = "\n\t")
    
    Answer = input("\t\tБажаєте долучити ще користувача? (\"+\" - так): ")

    print("\t", "-----------", end = "\n\n")
    
    #вихід з циклу
    if( (Answer != "+") or (len(DataStruct["Marka"]) == 100) ):
        if(len(DataStruct["Marka"]) >= 3):
            break

        else:
            print("\t\t", "Вихід неможливий, у вас введено менше 3 користувачів")

print("\n\n", "Вивід користувачів [рік - піб - марка - номер]:")
for i in range(0, len(DataStruct["Marka"]), 1):
    print("\t", "[", DataStruct["Year"][i], end = ", \"")
    print(DataStruct["PIB"][i], end = "\", \"")
    print(DataStruct["Marka"][i], end = "\", ")
    print(DataStruct["Number"][i], "]")

#пункт 1
SearchMarka = input("\n\n Введіть марку для пошуку кількості автомобілів цієї марки: ")

CounterSearchMarka = 0

for i in range(0, len(DataStruct["Marka"]), 1):
    if(DataStruct["Marka"][i] == SearchMarka):
        CounterSearchMarka = CounterSearchMarka + 1

print("\t", "Кількість: ", CounterSearchMarka, end = "\n\n")

#пункт 2
print("Вивід цих автомобілів зазначеної марки впорядкованим за піб і з реєстраційним номером: ")

for i in range(1, len(DataStruct["Marka"]), 1):
    for j in range(0, len(DataStruct["Marka"]) - i, 1):
        if(DataStruct["PIB"][j] > DataStruct["PIB"][j + 1]):
            TempVar = DataStruct["PIB"][j]
            DataStruct["PIB"][j] = DataStruct["PIB"][j + 1]
            DataStruct["PIB"][j + 1] = TempVar
            TempVar = DataStruct["Marka"][j]
            DataStruct["Marka"][j] = DataStruct["Marka"][j + 1]
            DataStruct["Marka"][j + 1] = TempVar
            TempVar = DataStruct["Year"][j]
            DataStruct["Year"][j] = DataStruct["Year"][j + 1]
            DataStruct["Year"][j + 1] = TempVar
            TempVar = DataStruct["Number"][j]
            DataStruct["Number"][j] = DataStruct["Number"][j + 1]
            DataStruct["Number"][j + 1] = TempVar

for i in range(0, len(DataStruct["Marka"]), 1):
    if(CounterSearchMarka > 0):
        if(DataStruct["Marka"][i] == SearchMarka):
            print("\t", "[", "\"", DataStruct["PIB"][i], "\", ", DataStruct["Number"][i], "]")
    else:
        print("\t користувачі зазначеної марки відсутні!")

        break

print(end = "\n\n")

#пункт 3
#цикл вводу
MinYear = 0
MaxYear = 0
while(True): 
    MinYear = int(input("Вивід мінімального року: "))
    MaxYear = int(input("Вивід максимального року: "))
    
    if( FuncCheckYear(MinYear) and FuncCheckYear(MaxYear) ):
        if(MaxYear >= MinYear):
            break

        else:
            print("\t\t", "Мінімальний рік більший за максимальний, перевведіть!", end = "\n\n")

print("\n", "Вивід марок і реєстраційних номерів за вказаним діапазон років:")

for i in range(0, len(DataStruct["Marka"]), 1):
    if( (DataStruct["Year"][i] <= MaxYear) and (DataStruct["Year"][i] >= MinYear) ):
        print("\t", "[", "\"", DataStruct["Marka"][i], "\", ", DataStruct["Number"][i], "]")

getch()