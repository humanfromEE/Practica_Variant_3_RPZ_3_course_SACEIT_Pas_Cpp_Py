from msvcrt import getch

x = int(input("Введіть х: "))

if(x > 0):
    x = x + 1
elif(x < 0):
    x = x - 2
else:
    x = 10

print("Після виконання умови х:", x)

getch()