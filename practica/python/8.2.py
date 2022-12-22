from msvcrt import getch
from random import randint

#масив копалин для запису у множини
ArrayKopalin = [
    "nafta",
    "zoloto",
    "vugillya",

    "diamanti",
    "gaz",
    "ryda",

    "pisok",
    "zemlya",
    "granit",

    "slanets",
    "aluminiy",
    "bronza",

    "byrshtin",
    "izumrud",
    "svinets"
]

#функція заповнення множини
def FuncInputSet(SET):
    for i in range(0, 5, 1):
        SET.add(ArrayKopalin[randint(0, len(ArrayKopalin) - 1)])

#функція виводу множини
def FuncOutputSet(Message, SET):
    print(Message, ":", sep = "")
    print("\t", SET, end = "\n\n")

First= set()
Second= set()
Third= set()
Fourth= set()
Fifth= set()

FuncInputSet(First)
FuncInputSet(Second)
FuncInputSet(Third)
FuncInputSet(Fourth)
FuncInputSet(Fifth)

FuncOutputSet("перша множина", First)
FuncOutputSet("друга множина", Second)
FuncOutputSet("третя множина", Third)
FuncOutputSet("четверта множина", Fourth)
FuncOutputSet("п'ята множина", Fifth)

#вивід елементів які є у всіх множинах
print("Вивід елементів, які є у всіх множинах:")
for i in ArrayKopalin:
    if(
        (i in First) and (i in Second) and
        (i in Third) and (i in Fourth) and
        (i in Fifth) 
    ):
        print("\t", i)

#вивід елементів яких немає у множинах
print("\n\n", "Вивід елементів, яких немає у множинах множинах:", sep = "")
for i in ArrayKopalin:
    if(
        (
            (i in First) or (i in Second) or
            (i in Third) or (i in Fourth) or
            (i in Fifth) 
        ) == 0
    ):
        print("\t", i)

#додаткове завдання - елементи, які є лише у першій множині
print("\n\n", "Вивід елементів, які є лише у першій множині:", sep = "")
for i in First:
    if(
        (
            (i in Second) or (i in Third) or 
            (i in Fourth) or (i in Fifth) 
        ) == 0
    ):
        print("\t", i)

getch()