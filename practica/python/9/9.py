"""
    #перевірка наявності файлів і цілісність даних - def FuncCheckFiles():

    #табуляція - def FuncPrintTab(CountTab):
    #вивід лінії - def FuncPrintLine(CountTab, LengthLine, SymbolLine):

    #перевірка на долучення даних, якщо номер авіарейсу відсутній у БД - def FuncCheckCommandOne(CountTab, Number):
    #перевірка на видалення редагування на існування номеру авіарейсу для подальших дій - def FuncCheckCommandTwoThree(CountTab, Number):
    #кількість записів у БД - def FuncCheckVoidBaseData():
    #долучення записів у кінець файлів - def FuncAppendDataInEndFile(NameFile, Value):
    #видалення записів за номером строки - def FuncDeleteDataInFile(NameFile, SaveLine):
    #редагування записів за номером строки - def FuncEditDataInFile(NameFile, SaveLine, Value):
    #вивід даних за номером строки - def FuncOutputDataInFile(Message, CountTab, NameFile, SaveLine):

    #команда 1 (долучення даних у БД) - def FuncCommandOne(CountTab):
    #команда 2 (редагування даних у БД) - def FuncCommandTwo(CountTab):
    #команда 3 (видалення даних у БД) - def FuncCommandThree(CountTab):
    #команда 4 (вивід даних БД) - def FuncCommandFour(CountTab):
    #команда 5 (вивід даних БД за вказаним типом літака) - def FuncCommandFive(CountTab):

    #перевірка введеної команди - def FuncCheckInputCommand(CountTab, Command):
    #створення звіту - def FuncCreateReport():
"""

from msvcrt import getch

#назви файлів
NameFileReport = "звіт.txt"
NameFileNumber = "номер авіарейсу.txt"
NameFileMarshut = "маршрут.txt"
NameFileType = "тип літака.txt"
NameFileStancia = "станція.txt"
NameFilePrice = "ціна квітка.txt"

#довжина ліній
LengthLineProgram = 125 

#!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

#перевірка наявності файлів і цілісність даних
def FuncCheckFiles():
    try:
        print("ПОВІДОМЛЕННЯ!")

        File1 = open(NameFileMarshut)
        File2 = open(NameFileNumber)
        File3 = open(NameFilePrice)
        File4 = open(NameFileStancia)
        File5 = open(NameFileType)

        ArrayFilesLines = []
        ArrayFilesLines.append(len(File1.readlines()))
        ArrayFilesLines.append(len(File2.readlines()))
        ArrayFilesLines.append(len(File3.readlines()))
        ArrayFilesLines.append(len(File4.readlines()))
        ArrayFilesLines.append(len(File5.readlines()))

        CreateAllFiles = False #змінна, яка відповідає за створення усіх файлів

        for i in range(0, len(ArrayFilesLines), 1):
            if(ArrayFilesLines[0] != ArrayFilesLines[i]):
                CreateAllFiles = True
                break
        
        if(CreateAllFiles):
            File1 = open(NameFileMarshut, "w")
            File1.close()
            File2 = open(NameFileNumber, "w")
            File2.close()
            File3 = open(NameFilePrice, "w")
            File3.close()
            File4= open(NameFileStancia, "w")
            File4.close()
            File5 = open(NameFileType, "w")
            File5.close()

            print("\t", "Файли БД не були знайдені (чи була нецілісність даних) і створююється нова БД", sep = "")

        else:
            print("\t", "БД була перевірена і відкрита!", sep = "")

    except FileNotFoundError:
        File1 = open(NameFileMarshut, "w")
        File1.close()
        File2 = open(NameFileNumber, "w")
        File2.close()
        File3 = open(NameFilePrice, "w")
        File3.close()
        File4= open(NameFileStancia, "w")
        File4.close()
        File5 = open(NameFileType, "w")
        File5.close()

        print("\t", "Файли БД не були знайдені (чи була нецілісність даних) і створююється нова БД", sep = "")

#табуляція
def FuncPrintTab(CountTab):
    ReturnString = ""

    for i in range(0, CountTab, 1):
        ReturnString = ReturnString + "\t"

    return ReturnString

#вивід лінії
def FuncPrintLine(CountTab, LengthLine, SymbolLine):
    print("\n", FuncPrintTab(CountTab), sep = "", end = "")

    for i in range(CountTab * 8 + 1, LengthLine + 1, 1):
        print(SymbolLine, sep = "", end = "")

    print(end = "\n\n")

#перевірка на долучення даних, якщо номер авіарейсу відсутній у БД
def FuncCheckCommandOne(CountTab, Number):
    Number = Number + "\n"

    File = open(NameFileNumber)

    ArrayLines = File.readlines()

    for i in range(0, len(ArrayLines), 1):
        if(ArrayLines[i] == Number):
            File.close()

            FuncPrintLine(CountTab, LengthLineProgram, "!")

            print(FuncPrintTab(CountTab), "Цей номер авіарейсу існує у БД, долучення даних неможливе, операцію скасовано!", sep = "")

            FuncPrintLine(CountTab, LengthLineProgram, "!")

            return False

    File.close()

    return True

#перевірка на видалення редагування на існування номеру авіарейсу для подальших дій
def FuncCheckCommandTwoThree(CountTab, Number):
    Number = Number + "\n"

    File = open(NameFileNumber)

    ArrayLines = File.readlines()

    for i in range(0, len(ArrayLines), 1):
        if(ArrayLines[i] == Number):
            File.close()
            return True
        

    File.close()

    FuncPrintLine(CountTab, LengthLineProgram, "!")

    print(FuncPrintTab(CountTab), "Цей номер авіарейсу не знайдено у БД, дії з даними неможливі, операцію скасовано!", sep = "")

    FuncPrintLine(CountTab, LengthLineProgram, "!")

    return False

#кількість записів у БД
def FuncCheckVoidBaseData():
    File = open(NameFileNumber)

    CounterLines = len(File.readlines())

    File.close()

    return CounterLines

#долучення записів у кінець файлів
def FuncAppendDataInEndFile(NameFile, Value):
    if(Value != ""):
        File = open(NameFile, "a")
        File.write(Value + "\n")
        File.close()

#видалення записів за номером строки
def FuncDeleteDataInFile(NameFile, SaveLine):
    #зчитування даних у список
    File = open(NameFile)
    ArrayLines = File.readlines()
    File.close()

    if(len(ArrayLines) > 0):
        ArrayLines.pop(SaveLine - 1) #видалення строки 

        #перезапис даних
        File = open(NameFile, "w")
        for i in range(0, len(ArrayLines), 1):
            File.write(ArrayLines[i])
        File.close()

#редагування записів за номером строки
def FuncEditDataInFile(NameFile, SaveLine, Value):
    #зчитування даних у список
    File = open(NameFile)
    ArrayLines = File.readlines()
    File.close()

    if(len(ArrayLines) > 0):
        ArrayLines[SaveLine - 1] = Value + "\n"

        File = open(NameFile, "w")
        for i in range(0, len(ArrayLines), 1):
            File.write(ArrayLines[i])
        File.close()

#вивід даних за номером строки
def FuncOutputDataInFile(Message, CountTab, NameFile, SaveLine):
    File = open(NameFile)
    ArrayLines = File.readlines()
    print(FuncPrintTab(CountTab), Message, ": ", ArrayLines[SaveLine - 1], sep = "", end = "")
    File.close()

#команда 1 (долучення даних у БД)
def FuncCommandOne(CountTab):
    FuncPrintLine(CountTab, LengthLineProgram, "+")

    print(FuncPrintTab(CountTab), "ДОЛУЧЕННЯ ЗАПИСУ", sep = "")
    Number = input(FuncPrintTab(CountTab + 1) + "введіть номер авіарейсу: ")

    if(FuncCheckCommandOne(CountTab + 2, Number)):
        Marshut = input(FuncPrintTab(CountTab + 1) + "введіть маршут: ")
        Type = input(FuncPrintTab(CountTab + 1) + "введіть тип: ")
        Stancia = input(FuncPrintTab(CountTab + 1) + "введіть станцію: ")
        Price = input(FuncPrintTab(CountTab + 1) + "введіть ціну квитка: ")

        #долучення даних у файл
        FuncAppendDataInEndFile(NameFileMarshut, Marshut)
        FuncAppendDataInEndFile(NameFileType, Type)
        FuncAppendDataInEndFile(NameFileStancia, Stancia)
        FuncAppendDataInEndFile(NameFilePrice, Price)
        FuncAppendDataInEndFile(NameFileNumber, Number)

    FuncPrintLine(CountTab, LengthLineProgram, "+")

#команда 2 (редагування даних у БД)
def FuncCommandTwo(CountTab):
    FuncPrintLine(CountTab, LengthLineProgram, "@")

    print(FuncPrintTab(CountTab), "РЕДАГУВАННЯ ЗАПИСУ", sep = "")
    Number = input(FuncPrintTab(CountTab + 1) + "введіть номер авіарейсу (його не можна редагувати): ")

    if(FuncCheckCommandTwoThree(CountTab + 2, Number)):
        #зчитування даних
        File = open(NameFileNumber)
        ArrayLines = File.readlines()
        File.close()

        #пошук строки редагування
        for i in range(0, len(ArrayLines), 1):
            if(ArrayLines[i] == (Number + "\n")):
                Marshut = input(FuncPrintTab(CountTab + 1) + "введіть маршут: ")
                Type = input(FuncPrintTab(CountTab + 1) + "введіть тип: ")
                Stancia = input(FuncPrintTab(CountTab + 1) + "введіть станцію: ")
                Price = input(FuncPrintTab(CountTab + 1) + "введіть ціну квитка: ")

                #зміна даних
                FuncEditDataInFile(NameFileMarshut, i + 1, Marshut)
                FuncEditDataInFile(NameFileType, i + 1, Type)
                FuncEditDataInFile(NameFileStancia, i + 1, Stancia)
                FuncEditDataInFile(NameFilePrice, i + 1, Price)

                break

    FuncPrintLine(CountTab, LengthLineProgram, "@")

#команда 3 (видалення даних у БД)
def FuncCommandThree(CountTab):
    FuncPrintLine(CountTab, LengthLineProgram, "-")

    print(FuncPrintTab(CountTab), "ВИДАЛЕННЯ ЗАПИСУ", sep = "")
    Number = input(FuncPrintTab(CountTab + 1) + "введіть номер авіарейсу: ")
    
    if(FuncCheckCommandTwoThree(CountTab + 2, Number)):
        #зчитування даних
        File = open(NameFileNumber)
        ArrayLines = File.readlines()
        File.close()

        #пошук строки редагування
        for i in range(0, len(ArrayLines), 1):
            if(ArrayLines[i] == (Number + "\n")):
                #видалення даних
                FuncDeleteDataInFile(NameFileNumber, i + 1)
                FuncDeleteDataInFile(NameFileMarshut, i + 1)
                FuncDeleteDataInFile(NameFileType, i + 1)
                FuncDeleteDataInFile(NameFileStancia, i + 1)
                FuncDeleteDataInFile(NameFilePrice, i + 1)

                break
    

    FuncPrintLine(CountTab, LengthLineProgram, "-")

#команда 4 (вивід даних БД)
def FuncCommandFour(CountTab):
    FuncPrintLine(CountTab, LengthLineProgram, "=")

    print(FuncPrintTab(CountTab), "ВИВІД ЗАПИСІВ", sep = "")

    #зчитування даних
    File = open(NameFileNumber)
    ArrayLines = File.readlines()
    File.close()

    #пошук строки редагування
    for i in range(0, len(ArrayLines), 1):
        FuncPrintLine(CountTab + 1, LengthLineProgram, "*")

        #вивід даних
        print(FuncPrintTab(CountTab + 1), "запис №", i + 1, ":", sep = "")
        FuncOutputDataInFile("номер авіарейсу", CountTab + 2, NameFileNumber, i + 1)
        FuncOutputDataInFile("маршут", CountTab + 2, NameFileMarshut, i + 1)
        FuncOutputDataInFile("тип літака", CountTab + 2, NameFileType, i + 1)
        FuncOutputDataInFile("ціна квитка", CountTab + 2, NameFilePrice, i + 1)
        FuncOutputDataInFile("станція", CountTab + 2, NameFileStancia, i + 1)

        FuncPrintLine(CountTab + 1, LengthLineProgram, "*")

    FuncPrintLine(CountTab, LengthLineProgram, "=")

#команда 5 (вивід даних БД за вказаним типом літака)
def FuncCommandFive(CountTab):
    FuncPrintLine(CountTab, LengthLineProgram, "?")

    print(FuncPrintTab(CountTab), "ПОШУК ЗАПИСІВ ЗА ТИПОМ ЛІТАКА", sep = "")
    Type = input(FuncPrintTab(CountTab + 1) + "введіть тип: ")

    NotFind = True #для виводу повідомлення, якщо не буде знайдено результатів

    #пошук строки редагування
    #зчитування даних
    File = open(NameFileType)
    ArrayLines = File.readlines()
    File.close()

    #пошук строки редагування
    for i in range(0, len(ArrayLines), 1):
        if(ArrayLines[i] == (Type + "\n")):
            FuncPrintLine(CountTab + 1, LengthLineProgram, "*")

            #вивід даних
            print(FuncPrintTab(CountTab + 1), "запис №", i + 1, ":", sep = "")
            FuncOutputDataInFile("номер авіарейсу", CountTab + 2, NameFileNumber, i + 1)
            FuncOutputDataInFile("маршут", CountTab + 2, NameFileMarshut, i + 1)
            FuncOutputDataInFile("тип літака", CountTab + 2, NameFileType, i + 1)
            FuncOutputDataInFile("ціна квитка", CountTab + 2, NameFilePrice, i + 1)
            FuncOutputDataInFile("станція", CountTab + 2, NameFileStancia, i + 1)

            FuncPrintLine(CountTab + 1, LengthLineProgram, "*")

            NotFind = False

    if(NotFind):
        print(FuncPrintTab(CountTab + 2), "дані для такого типу літака не знайдені", sep = "")

    FuncPrintLine(CountTab, LengthLineProgram, "?")

#перевірка введеної команди 
def FuncCheckInputCommand(CountTab, Command):
    for i in range(0, 5 + 1, 1):
        if(Command == str(i)):
            return True
    
    print(FuncPrintTab(CountTab), "команда введена неправильно!", sep = "")

    return False

#створення звіту 
def FuncCreateReport():
    FileReport = open(NameFileReport, "w")

    #зчитування даних
    File1 = open(NameFileMarshut)
    ArrayLinesFile1 = File1.readlines()
    File1.close()

    File2 = open(NameFileNumber)
    ArrayLinesFile2 = File2.readlines()
    File2.close()

    File3 = open(NameFilePrice)
    ArrayLinesFile3 = File3.readlines()
    File3.close()

    File4 = open(NameFileStancia)
    ArrayLinesFile4 = File4.readlines()
    File4.close()

    File5 = open(NameFileType)
    ArrayLinesFile5 = File5.readlines()
    File5.close()

    #запис даних
    for i in range(0, len(ArrayLinesFile1), 1):
        FileReport.write("запис №" + str(i + 1) + ":" + "\n")
        FileReport.write("\t" + "маршут: " + ArrayLinesFile1[i])
        FileReport.write("\t" + "номер авіарейсу: " + ArrayLinesFile2[i])
        FileReport.write("\t" + "ціна квитка: " + ArrayLinesFile3[i])
        FileReport.write("\t" + "станція: " + ArrayLinesFile4[i])
        FileReport.write("\t" + "тип літака: " + ArrayLinesFile5[i] + "\n")

    FileReport.close()

#|||||||||||||||||||||||||||||||||||||||||||||||||||||
#|||||||||||||||||||||||||||||||||||||||||||||||||||||
#|||||||||||||||||||||||||||||||||||||||||||||||||||||
#|||||||||||||||||||||||||||||||||||||||||||||||||||||
#|||||||||||||||||||||||||||||||||||||||||||||||||||||
#|||||||||||||||||||||||||||||||||||||||||||||||||||||
#|||||||||||||||||||||||||||||||||||||||||||||||||||||
#|||||||||||||||||||||||||||||||||||||||||||||||||||||
#|||||||||||||||||||||||||||||||||||||||||||||||||||||

FuncCheckFiles()

FuncPrintLine(0, LengthLineProgram, "`")

while (True):
    print("МЕНЮ:")
    print("\t", "1 - долучити запис", sep = "")
    print("\t", "2 - редагувати запис", sep = "")
    print("\t", "3 - видалити запис", sep = "")
    print("\t", "4 - вивести записи", sep = "")
    print("\t", "5 - вивести літаки за вказаним типомс", sep = "")
    print("\t", "0 - вихід з програми", sep = "")
    print("\t\t\t", "кількість записів у БД: ", FuncCheckVoidBaseData(), sep = "")

    Command = input("\t\t" + "ваш вибір: ")

    if(FuncCheckInputCommand(3, Command)):
        if(Command == "1"):
            FuncCommandOne(3)

        elif((Command == "2") and (FuncCheckVoidBaseData() > 0)):
            FuncCommandTwo(3)

        elif((Command == "3") and (FuncCheckVoidBaseData() > 0)):
            FuncCommandThree(3)

        elif((Command == "4") and (FuncCheckVoidBaseData() > 0)):
            FuncCommandFour(3)

        elif((Command == "5") and (FuncCheckVoidBaseData() > 0)):
            FuncCommandFive(3)

        elif(Command != "0"): #вивід повідомлення, що для виконання команди потрібен хоча б 1 запис
            print(FuncPrintTab(3), "для цієї комнади потрібен хочаб 1 запис у БД, долучіть запис", sep = "")

        else:
            print(FuncPrintTab(3), "ВИХІД З ПРОГРАМИ")
            print(FuncPrintTab(4), "Не видаляйте файли для повторного перезапуску", sep = "")
            Answer = input(FuncPrintTab(4) + "Бажаєте створити звіт? (\"+\" - так): ")

            if(Answer == "+"):
                FuncCreateReport()
                print(FuncPrintTab(5), "Назва файлу: \"", NameFileReport, "\"", sep = "")

            FuncPrintLine(0, LengthLineProgram, "`")

            break

    FuncPrintLine(0, LengthLineProgram, "`")
    
getch()

#|||||||||||||||||||||||||||||||||||||||||||||||||||||
#|||||||||||||||||||||||||||||||||||||||||||||||||||||
#|||||||||||||||||||||||||||||||||||||||||||||||||||||
#|||||||||||||||||||||||||||||||||||||||||||||||||||||
#|||||||||||||||||||||||||||||||||||||||||||||||||||||
#|||||||||||||||||||||||||||||||||||||||||||||||||||||
#|||||||||||||||||||||||||||||||||||||||||||||||||||||
#|||||||||||||||||||||||||||||||||||||||||||||||||||||
#|||||||||||||||||||||||||||||||||||||||||||||||||||||