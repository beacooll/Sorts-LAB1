import matplotlib.pyplot as mpl
import numpy as np

with open("bubbleSort/random.txt") as file:
    f1 = [line for line in file]
with open("insertionSort/random.txt") as file:
    f2 = [line for line in file]
with open("selectionSort/random.txt") as file:
    f3 = [line for line in file]
with open("prattSort/random.txt") as file:
    f9 = [line for line in file]
g1 = [tuple(map(int, line.split())) for line in f1]
g2 = [tuple(map(int, line.split())) for line in f2]
g3 = [tuple(map(int, line.split())) for line in f3]
g9 = [tuple(map(int, line.split())) for line in f9]
t1 = [x[1]/1_000_000 for x in g1]
n1 = [x[0] for x in g1]
t2 = [x[1]/1_000_000 for x in g2]
n2 = [x[0] for x in g2]
t3 = [x[1]/1_000_000 for x in g3]
n3 = [x[0] for x in g3]
t9 = [x[1]/1_000_000 for x in g9]
n9 = [x[0] for x in g9]
mpl.figure(figsize=(8, 6))
mpl.plot(n1, t1, color='blue', label = "bubbleSort")
mpl.plot(n2, t2, color='red', label = "insertionSort")
mpl.plot(n3, t3, color='yellow', label = "selectionSort")
mpl.plot(n9, t9, color='purple', label = "prattSort")
mpl.plot()
mpl.title('Graph of the quadratic time complexity functions')
mpl.xlabel('N')
mpl.ylabel('t(N), seconds')
mpl.axhline(0, color='black', linewidth=0.5, ls='--')
mpl.axvline(0, color='black', linewidth=0.5, ls='--')
mpl.grid()
mpl.legend()
mpl.show()
with open("mergeSort/random.txt") as file:
    f4 = [line for line in file]
with open("quickSort/random.txt") as file:
    f5 = [line for line in file]
with open("heapSort/random.txt") as file:
    f6 = [line for line in file]
with open("shellSort/random.txt") as file:
    f7 = [line for line in file]
with open("hibbardSort/random.txt") as file:
    f8 = [line for line in file]

g4 = [tuple(map(int, line.split())) for line in f4]
g5 = [tuple(map(int, line.split())) for line in f5]
g6 = [tuple(map(int, line.split())) for line in f6]
g7 = [tuple(map(int, line.split())) for line in f7]
g8 = [tuple(map(int, line.split())) for line in f8]

t4 = [x[1]/1_000_000 for x in g4]
n4 = [x[0] for x in g4]
t5 = [x[1]/1_000_000 for x in g5]
n5 = [x[0] for x in g5]
t6 = [x[1]/1_000_000 for x in g6]
n6 = [x[0] for x in g6]
t7 = [x[1]/1_000_000 for x in g7]
n7 = [x[0] for x in g7]
t8 = [x[1]/1_000_000 for x in g8]
n8 = [x[0] for x in g8]

mpl.figure(figsize=(8, 6))
mpl.plot(n4, t4, color='blue', label = "mergeSort")
mpl.plot(n5, t5, color='red', label = "quickSort")
mpl.plot(n6, t6, color='yellow', label = "heapSort")
mpl.plot(n7, t7, color='green', label = "shellSort")
mpl.plot(n8, t8, color='orange', label = "hibbardSort")

mpl.plot()
mpl.title('Graph of the logarithmic time complexity functions')
mpl.xlabel('N')
mpl.ylabel('t(N), seconds')
mpl.axhline(0, color='black', linewidth=0.5, ls='--')
mpl.axvline(0, color='black', linewidth=0.5, ls='--')
mpl.grid()
mpl.legend()
mpl.show()