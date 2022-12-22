from msvcrt import getch

NumberMonth = int(input("Введіть номер місяця: "))

#case (використання словників)
print("Конструкція case (використання словників):", end = "\n\t")

case = {
    12: "Зима",
    1: "Зима",
    2: "Зима",
    3: "Весна",
    4: "Весна",
    5: "Весна",
    6: "Літо",
    7: "Літо",
    8: "Літо",
    9: "Осінь",
    10: "Осінь",
    11: "Осінь"
}

if(NumberMonth in case):
    print(case[NumberMonth])
else:
    print("Немає такого місяця")

#if
print("Конструкція if:", end = "\n\t")

if( (NumberMonth == 12) or (NumberMonth == 1) or (NumberMonth == 2) ):
    print("Зима")
    
elif( (NumberMonth >= 3) and (NumberMonth <= 5) ):
    print("Весна")

elif( (NumberMonth >= 6) and (NumberMonth <= 8) ):
    print("Літо")

elif( (NumberMonth >= 9) and (NumberMonth <= 11) ):
    print("Осінь")

else:
    print("Немає такого місяця")

getch()