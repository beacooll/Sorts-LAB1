import matplotlib.pyplot as mpl
sorts = ["bubbleSort", "insertionSort", "selectionSort", "mergeSort",
         "quickSort", "heapSort", "shellSort", "hibbardSort", "prattSort"]
for sort in sorts:
    with open(sort + "/sorted.txt") as file:
        f1 = [line for line in file]
    with open(sort + "/reverse.txt") as file:
        f2 = [line for line in file]
    with open(sort + "/90%sorted.txt") as file:
        f3 = [line for line in file]
    with open(sort + "/random.txt") as file:
        f4 = [line for line in file]
    g1 = [tuple(map(int, line.split())) for line in f1]
    g2 = [tuple(map(int, line.split())) for line in f2]
    g3 = [tuple(map(int, line.split())) for line in f3]
    g4 = [tuple(map(int, line.split())) for line in f4]
    t1 = [x[1]/1_000_000 for x in g1]
    n1 = [x[0] for x in g1]
    t2 = [x[1]/1_000_000 for x in g2]
    n2 = [x[0] for x in g2]
    t3 = [x[1]/1_000_000 for x in g3]
    n3 = [x[0] for x in g3]
    t4 = [x[1]/1_000_000 for x in g4]
    n4 = [x[0] for x in g4]
    mpl.figure(figsize=(8, 6))
    mpl.plot(n1, t1, color='blue', label = "sorted")
    mpl.plot(n2, t2, color='red', label = "reverse")
    mpl.plot(n3, t3, color='yellow', label = "90%sorted")
    mpl.plot(n4, t4, color='green', label = "random")
    mpl.plot()
    mpl.title('Graph of the ' + sort +'ing time complexity function')
    mpl.xlabel('N')
    mpl.ylabel('t(N), seconds')
    mpl.axhline(0, color='black', linewidth=0.5, ls='--')
    mpl.axvline(0, color='black', linewidth=0.5, ls='--')
    mpl.grid()
    mpl.legend()
    mpl.show()