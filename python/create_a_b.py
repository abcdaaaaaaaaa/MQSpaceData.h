import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit
import pandas as pd
print("ppm = a*ratio^b")
inp = input("please write your txt file name: ")
data = pd.read_csv('../Regression/' + inp + '.txt', header=None)

x = np.array(data.iloc[:, 0])
y = np.array(data.iloc[:, 1])

def func(x, a, b):
    return a * np.power(x, b)

popt, pcov = curve_fit(func, x, y)

a = popt[0]
b = popt[1]

print(f"create_a: {a}, create_b: {b}")


with open('../Regression/' + inp + "a_b" +'.txt', 'a') as file:
    file.write(f"a: {a}, b: {b}\n")


plt.scatter(x, y, label='Real Datas')
plt.plot(x, func(x, *popt), 'r-', label=f'New Curve: y = {a} * x^({b})')
plt.xlabel('x')
plt.ylabel('y')
plt.legend()
plt.show()
