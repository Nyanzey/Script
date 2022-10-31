from subprocess import run, TimeoutExpired, DEVNULL
from math import inf
import numpy as np
import matplotlib.pyplot as plt
import os

def execute(name, num, args):
    file = f'''#include <fstream>
#include "{name}/{name}_{num}.h"
int main() {{
    std::ofstream out("out");
    auto time = {name}_{num}({str(args).strip('[]')});
    out << time;
}}'''
    with open('main.cc', 'w') as out:
        out.write(file)
    try:
        run(['g++', 'main.cc', '-o', 'main.exe','-std=c++17', '-O3'], check=True, stdout=DEVNULL, stderr=DEVNULL)
    except:
        print(f'Compilation error: {name}_{num}')
        return inf
    try:
        err = run(['./main.exe'], timeout=60, check=True, stdout=DEVNULL, stderr=DEVNULL)
    except TimeoutExpired:
        print(f'Timeout error: {name}_{num}')
        return inf
    except:    
        print(f'Runtime error: {name}_{num}')
        return inf
    return float(open('out').read())

def getinputs(filename, result):
    file = open(filename)
    for row in file:
        row = row.split(',')
        assert len(row) == 3
        inlst = [int(row[0]), int(row[1]), int(row[2])]
        print(inlst)
        result.append(inlst)

horseinputs = []
nqueensinputs = []

print("Inputs for horse:")
getinputs('inhorse.txt', horseinputs)

print("Inputs for nqueens:")
getinputs('inqueens.txt', nqueensinputs)

puzzlesize = 0
puzzleiter = 0
puzzleopt = input("Use script to generate random puzzle.txt? y/n ")

if puzzleopt == 'y':
    puzzleopt = True
    puzzlesize = int(input("Puzzle size: "))
    puzzleiter = int(input("Iterations to unsort the puzzle: "))
else:
    puzzleopt = False

puzzlecount = int(input("Number of executions for puzzle: "))

names = [ 'puzzle', 'nqueens', 'horse', 'total' ]

resnames = ['-----PUZZLE AVG RESULTS-----', '-----NQUEENS AVG RESULTS-----', '-----HORSE AVG RESULTS-----', '-----OVERALL AVG RESULTS-----']

times = [ [(0, i+1) for i in range(5)], [(0, i+1) for i in range(5)], [(0, i+1) for i in range(5)], [(0, i+1) for i in range(5)] ]

for i in range(len(horseinputs)):
    args = horseinputs[i]
    for j in range(1,6):
        t = execute('horse', j, args)/len(horseinputs)

        t1, t2 = times[3][j-1]
        times[3][j-1] = (t1 + t, t2)

        t1, t2 = times[2][j-1]
        times[2][j-1] = (t1 + t, t2)

for i in range(len(nqueensinputs)):
    args = nqueensinputs[i]
    for j in range(1,6):
        t = execute('nqueens', j, args)/len(nqueensinputs)
        
        t1, t2 = times[3][j-1]
        times[3][j-1] = (t1 + t, t2)

        t1, t2 = times[1][j-1]
        times[1][j-1] = (t1 + t, t2)

for i in range(puzzlecount):
    args = []
    if puzzleopt:
        os.system(f'gen_puzzle.py {puzzlesize} {puzzleiter}')
    for j in range(1,6):
        t = execute('puzzle', j, args)/puzzlecount
        
        t1, t2 = times[3][j-1]
        times[3][j-1] = (t1 + t, t2)

        t1, t2 = times[0][j-1]
        times[0][j-1] = (t1 + t, t2)

HORSE = [(0) for i in range(5)]
NQUEENS = [(0) for i in range(5)]
PUZZLE = [(0) for i in range(5)]
OVERALL = [(0) for i in range(5)]

MASTER = [PUZZLE, NQUEENS, HORSE, OVERALL]

numinputs = [puzzlecount, len(nqueensinputs), len(horseinputs), 3]

for i in range(4):
    print()
    times[i].sort()
    print(resnames[i])
    placement = 1
    for t, j in times[i]:

        MASTER[i][j-1] = t
        print(f'#{placement} PLACE: grupo {j} ({t}s)')
        placement = placement + 1

barWidth = 0.25
fig = plt.subplots(figsize =(16, 8))

br1 = np.arange(len(HORSE))
br2 = [x + barWidth for x in br1]
br3 = [x + barWidth for x in br2]
br4 = [x + 0.1875 for x in br3]
 
plt.bar(br1, HORSE, color ='r', width = barWidth,
        edgecolor ='grey', label ='HORSE')
plt.bar(br2, NQUEENS, color ='g', width = barWidth,
        edgecolor ='grey', label ='NQUEENS')
plt.bar(br3, PUZZLE, color ='b', width = barWidth,
        edgecolor ='grey', label ='PUZZLE')
plt.bar(br4, OVERALL, color ='cyan', width = barWidth/2,
        edgecolor ='grey', label ='OVERALL')
 
plt.xlabel('Grupos', fontweight ='bold', fontsize = 15)
plt.ylabel('Tiempo (s)', fontweight ='bold', fontsize = 15)
plt.xticks([r + 0.065 + barWidth for r in range(len(HORSE))],
        ['Grupo 1', 'Grupo 2', 'Grupo 3', 'Grupo 4', 'Grupo 5'])
 
plt.legend()
plt.show()
