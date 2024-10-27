import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit

def logarithmic_model(n, a, b, c):
  return a * np.log(n+1) + b*n + c

def linear_model(n, a, b):
    return a * n + b

def quadratic_model(n, a, b, c):
  return a * n**2 + b * n + c

def perform_regression(sort_name, data_type, regression_model, model_name):
    with open(f"{sort_name}/{data_type}.txt") as file:
        f = [line for line in file]
    g = [tuple(map(int, line.split())) for line in f]
    t = [x[1] for x in g if x[0] > 0]
    n = np.array([x[0] for x in g if x[0] > 0], dtype=np.int64)

    popt, _ = curve_fit(regression_model, n, t)
    if regression_model == linear_model:
        a, b = popt
        plt.scatter(n, t, label=f"Experimental data\nt = {a:.4f} * n + {b:.4f}")
    elif regression_model == quadratic_model:
      a, b, c = popt
      plt.scatter(n, t, label="Experimental data\n" + f"t = {a:.4f} * n^2 + {b:.4f} * n + {c:.4f}")
    elif regression_model == logarithmic_model:
      a, b, c = popt
      plt.scatter(n, t, label=f"Experimental data\nt = {a:.4f} * log(n) + {b:.4f}*n + {c:4f}")
    plt.plot(n, regression_model(n, *popt), 'r-', label=f"{model_name} regression")
    plt.xlabel("N")
    plt.ylabel("t(N), seconds")
    plt.title(f'Graph of the {sort_name}ing time complexity function ({data_type})')
    plt.legend()
    plt.show()

sorts = ["bubbleSort", "insertionSort", "selectionSort", "mergeSort",
         "quickSort", "heapSort", "shellSort", "hibbardSort", "prattSort"]
data_types = ["sorted", "reverse", "90%sorted", "random"]

for sort in sorts[:3]:
  for data_type in data_types:
    if (sort == "bubbleSort" or sort == "insartionSort") and data_type =="sorted":
        perform_regression(sort, data_type, linear_model, "linear")
    else:
        perform_regression(sort, data_type, quadratic_model, "quadratic")

for sort in sorts[3:]:
  for data_type in data_types:
    perform_regression(sort, data_type, logarithmic_model, "logarithmic")

for data_type in data_types:
    perform_regression("prattSort", data_type, quadratic_model, "quadratic")