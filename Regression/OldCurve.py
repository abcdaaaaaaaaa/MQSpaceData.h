import numpy as np
from scipy.optimize import curve_fit
import matplotlib.pyplot as plt

sensor_name = input("Enter the type of your gas sensor like 'MQ-2': ")

gases = {}
plt.figure(figsize=(8, 6))

while True:
    gas_name = input("Enter the gas name (or press 'Enter' to finish): ")
    if gas_name == '':
        break

    values = []
    values_input = input(f"Enter (x, y) values for {gas_name} as [(x1, y1), (x2, y2), ...]: ")
    try:
        values = eval(values_input)
        x_values = [value[0] for value in values]
        y_values = [value[1] for value in values]

        x = np.array(x_values)
        y = np.array(y_values)

        def func(x, a, b):
            return a * np.power(x, b)

        popt, pcov = curve_fit(func, x, y)

        residuals = y - func(x, *popt)
        ss_res = np.sum(residuals**2)
        ss_tot = np.sum((y - np.mean(y))**2)

        plt.scatter(x, y, label=f'Real Datas for {gas_name}')
        plt.plot(x, func(x, *popt), label=f'Curve for {gas_name}: y = {round(popt[0], 4)} * x^({round(popt[1], 4)})')

        gases[gas_name] = {'a': popt[0], 'b': popt[1]}
    except Exception as e:
        print("An error occurred:", e)
        print("Invalid input format. Please enter the values as [(x1, y1), (x2, y2), ...]")

plt.xlabel('x')
plt.ylabel('y')
plt.legend()
plt.title(f'Regression Curves for {sensor_name} Gas Sensor')
plt.show()
