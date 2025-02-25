from random import *

# Random 10 arrays
with open("input.txt", "w") as file:
    for i in range(10):
        n = randint(700000, 1000000)
        lst = []
        for j in range(n):
            lst.append(randint(1, 1000000))

        if i == 0:
            lst.sort()
        if i == 1:
            lst.sort(reverse=True)

        file.write(str(n) + "\n")
        for val in lst:
            file.write(str(val) + " ")
        file.write("\n")


