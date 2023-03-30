from sys import argv
from random import randrange

n = int(argv[3])
b = []
x = n-1
y = n-1

for i in range(n):
    l = []
    for j in range(n):
        t = (i*n + j + 1) % (n*n)
        l.append(t)
    b.append(l)

def printb():
    file = open("puzzle.txt", "w")
    countcol = 0
    countrow = 0 
    for l in b:
        for i in l:
            if i == 0:
                file.write("#")
            else:
                file.write(str(i))
            if countcol != n-1:
                file.write(' ')
            countcol = countcol + 1
        if countrow != n-1:
            file.write('\n')
        countcol = 0
        countrow = countrow + 1
    file.close()

printb()

def up():
    global x,y
    if y > 0:
        b[x][y], b[x][y-1] = b[x][y-1], b[x][y]
        y -= 1

def down():
    global x,y
    if y < n-1:
        b[x][y], b[x][y+1] = b[x][y+1], b[x][y]
        y += 1

def left():
    global x,y
    if x > 0:
        b[x][y], b[x-1][y] = b[x-1][y], b[x][y]
        x -= 1

def right():
    global x,y
    if x < n-1:
        b[x][y], b[x+1][y] = b[x+1][y], b[x][y]
        x += 1

fn = [up, down, left, right]

for _ in range(int(argv[2])):
    r = randrange(4)
    #print(fn[r].__name__)
    fn[r]()

printb()
