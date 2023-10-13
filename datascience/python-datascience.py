# python -m pip install matplotlib==3.8.0
# python -m pip install csv==0.0.13
# python -m pip install numpy==1.23.5
import matplotlib.pyplot as plt
import csv
import numpy as np
from scipy.stats import linregress

SensorModel = input("Enter the model of the MQ Gas sensor like MQ-303A: ")
SensorData = SensorModel + " " + "Datasheet"
SensorYscale = "ppm values for " + SensorModel
SensorXscale = "Scaling time for " + SensorModel

y = []

ay = []
by = []
cy = []
dy = []
ey = []
fy = []

plt.figure(facecolor='white')
plt.gca().set_facecolor('white')
plt.xlabel(SensorXscale)
plt.ylabel(SensorYscale)
plt.title(SensorData)

def generate_sequence(depth):
    return list(range(0, depth+1))

with open('../datascience/csv/{}.csv'.format(SensorModel), 'r') as file:
    depth = len(list(csv.reader(file))) - 2
    
sequence = generate_sequence(depth)
plt.xlim(0, depth)

def RealTime(file):
    csv_reader = csv.DictReader(file)
    for row in csv_reader:
        y.append(int(row['Data']))
        ay.append(int(row['H2']))
        by.append(int(row['LPG']))
        cy.append(int(row['CH4']))
        dy.append(int(row['CO']))
        ey.append(int(row['Alcohol']))
    plt.scatter(sequence, y, label=SensorModel, color='#000080', marker='o')
    plt.scatter(sequence, ay, label='H2', color='#0000FF', marker='o')
    plt.scatter(sequence, by, label='LPG', color='#000e44', marker='o')
    plt.scatter(sequence, cy, label='CH4', color='#87CEEB', marker='o')
    plt.scatter(sequence, dy, label='CO', color='#007FFF', marker='o')
    plt.scatter(sequence, ey, label='Alcohol', color='#40E0D0', marker='o')

match(SensorModel):
    case 'MQ-135':
        plt.ylim(10, 1000)
        with open('../datascience/csv/MQ-135.csv', 'r') as file:
           csv_reader = csv.DictReader(file)
           for row in csv_reader:
             y.append(int(row['Data']))
             ay.append(int(row['CO']))
             by.append(int(row['Alcohol']))
             cy.append(int(row['CO2']))
             dy.append(int(row['Toluen']))
             ey.append(int(row['NH4']))
             fy.append(int(row['Aceton']))
        plt.scatter(sequence, y, label=SensorModel, color='#000080', marker='o')
        plt.scatter(sequence, ay, label='CO', color='#0000FF', marker='o')
        plt.scatter(sequence, by, label='Alcohol', color='#000e44', marker='o')
        plt.scatter(sequence, cy, label='CO2', color='#87CEEB', marker='o')
        plt.scatter(sequence, dy, label='Toluen', color='#ADD8E6', marker='o')
        plt.scatter(sequence, ey, label='NH4', color='#007FFF', marker='o')
        plt.scatter(sequence, fy, label='Aceton', color='#40E0D0', marker='o')
    case 'MQ-2':
        plt.ylim(300, 10000)
        with open('../datascience/csv/MQ-2.csv', 'r') as file:
           csv_reader = csv.DictReader(file)
           for row in csv_reader:
             y.append(int(row['Data']))
             ay.append(int(row['H2']))
             by.append(int(row['LPG']))
             cy.append(int(row['CO']))
             dy.append(int(row['Alcohol']))
             ey.append(int(row['Propane']))
        plt.scatter(sequence, y, label=SensorModel, color='#000080', marker='o')
        plt.scatter(sequence, ay, label='H2', color='#0000FF', marker='o')
        plt.scatter(sequence, by, label='LPG', color='#000e44', marker='o')
        plt.scatter(sequence, cy, label='CO', color='#87CEEB', marker='o')
        plt.scatter(sequence, dy, label='Alcohol', color='#ADD8E6', marker='o')
        plt.scatter(sequence, ey, label='Propane', color='#007FFF', marker='o')
    case 'MQ-3':
        plt.ylim(25, 500)
        with open('../datascience/csv/MQ-3.csv', 'r') as file:
           csv_reader = csv.DictReader(file)
           for row in csv_reader:
             y.append(int(row['Data']))
             ay.append(int(row['LPG']))
             by.append(int(row['CH4']))
             cy.append(int(row['CO']))
             dy.append(int(row['Alcohol']))
             ey.append(int(row['Benzene']))
             fy.append(int(row['Hexane']))
        plt.scatter(sequence, y, label=SensorModel, color='#000080', marker='o')
        plt.scatter(sequence, ay, label='LPG', color='#0000FF', marker='o')
        plt.scatter(sequence, by, label='CH4', color='#000e44', marker='o')
        plt.scatter(sequence, cy, label='CO', color='#87CEEB', marker='o')
        plt.scatter(sequence, dy, label='Alcohol', color='#ADD8E6', marker='o')
        plt.scatter(sequence, ey, label='Benzene', color='#007FFF', marker='o')
        plt.scatter(sequence, fy, label='Hexane', color='#40E0D0', marker='o')
    case 'MQ-4':
        plt.ylim(300, 10000)
        with open('../datascience/csv/MQ-4.csv', 'r') as file:
           csv_reader = csv.DictReader(file)
           for row in csv_reader:
             y.append(int(row['Data']))
             ay.append(int(row['LPG']))
             by.append(int(row['CH4']))
             cy.append(int(row['CO']))
             dy.append(int(row['Alcohol']))
             ey.append(int(row['Smoke']))
        plt.scatter(sequence, y, label=SensorModel, color='#000080', marker='o')
        plt.scatter(sequence, ay, label='LPG', color='#0000FF', marker='o')
        plt.scatter(sequence, by, label='CH4', color='#000e44', marker='o')
        plt.scatter(sequence, cy, label='CO', color='#87CEEB', marker='o')
        plt.scatter(sequence, dy, label='Alcohol', color='#ADD8E6', marker='o')
        plt.scatter(sequence, ey, label='Smoke', color='#007FFF', marker='o')
    case 'MQ-5':
        plt.ylim(200, 10000)
        with open('../datascience/csv/MQ-5.csv', 'r') as file:
           RealTime(file)
    case 'MQ-6':
        plt.ylim(300, 10000)
        with open('../datascience/csv/MQ-6.csv', 'r') as file:
           RealTime(file)
    case 'MQ-7':
        plt.ylim(10, 10000)
        with open('../datascience/csv/MQ-7.csv', 'r') as file:
           RealTime(file)
    case 'MQ-8':
        plt.ylim(10, 10000)
        with open('../datascience/csv/MQ-8.csv', 'r') as file:
           RealTime(file)
    case 'MQ-9':
        plt.ylim(10, 10000)
        with open('../datascience/csv/MQ-9.csv', 'r') as file:
           csv_reader = csv.DictReader(file)
           for row in csv_reader:
             y.append(int(row['Data']))
             by.append(int(row['LPG']))
             cy.append(int(row['CH4']))
             dy.append(int(row['CO']))
        plt.scatter(sequence, y, label=SensorModel, color='#000080', marker='o')
        plt.scatter(sequence, ay, label='LPG', color='#0000FF', marker='o')
        plt.scatter(sequence, by, label='CH4', color='#000e44', marker='o')
        plt.scatter(sequence, cy, label='CO', color='#87CEEB', marker='o')
    case 'MQ-131':
        plt.ylim(5, 100)
        with open('../datascience/csv/MQ-131.csv', 'r') as file:
           csv_reader = csv.DictReader(file)
           for row in csv_reader:
             y.append(int(row['Data']))
             by.append(int(row['NOX']))
             cy.append(int(row['CL2']))
             dy.append(int(row['O3']))
        plt.scatter(sequence, y, label=SensorModel, color='#000080', marker='o')
        plt.scatter(sequence, ay, label='NOX', color='#0000FF', marker='o')
        plt.scatter(sequence, by, label='CL2', color='#000e44', marker='o')
        plt.scatter(sequence, cy, label='O3', color='#87CEEB', marker='o')
    case 'MQ-136':
        plt.ylim(10, 200)
        with open('../datascience/csv/MQ-136.csv', 'r') as file:
           csv_reader = csv.DictReader(file)
           for row in csv_reader:
             y.append(int(row['Data']))
             by.append(int(row['H2S']))
             cy.append(int(row['NH4']))
             dy.append(int(row['CO']))
        plt.scatter(sequence, y, label=SensorModel, color='#000080', marker='o')
        plt.scatter(sequence, ay, label='H2S', color='#0000FF', marker='o')
        plt.scatter(sequence, by, label='NH4', color='#000e44', marker='o')
        plt.scatter(sequence, cy, label='CO', color='#87CEEB', marker='o')
    case 'MQ-303A':
        plt.ylim(10, 10000)
        with open('../datascience/csv/MQ-303A.csv', 'r') as file:
           csv_reader = csv.DictReader(file)
           for row in csv_reader:
             y.append(int(row['Data']))
             by.append(int(row['Isobuthane']))
             cy.append(int(row['Hydrogen']))
             dy.append(int(row['Ethanol']))
        plt.scatter(sequence, y, label=SensorModel, color='#000080', marker='o')
        plt.scatter(sequence, ay, label='Isobuthane', color='#0000FF', marker='o')
        plt.scatter(sequence, by, label='Hydrogen', color='#000e44', marker='o')
        plt.scatter(sequence, cy, label='Ethanol', color='#87CEEB', marker='o')

    case 'MQ-309A':
        plt.ylim(30, 3000)
        with open('../datascience/csv/MQ-309A.csv', 'r') as file:
           csv_reader = csv.DictReader(file)
           for row in csv_reader:
             y.append(int(row['Data']))
             ay.append(int(row['H2']))
             by.append(int(row['CH4']))
             cy.append(int(row['CO']))
             dy.append(int(row['Alcohol']))
        plt.scatter(sequence, y, label=SensorModel, color='#000080', marker='o')
        plt.scatter(sequence, ay, label='H2', color='#0000FF', marker='o')
        plt.scatter(sequence, by, label='CH4', color='#000e44', marker='o')
        plt.scatter(sequence, cy, label='CO', color='#87CEEB', marker='o')
        plt.scatter(sequence, dy, label='Alcohol', color='#ADD8E6', marker='o')
    case 'SpaceData':
        plt.ylim(0, 100)
        with open('../datascience/csv/SpaceData.csv', 'r') as file:
           csv_reader = csv.DictReader(file)
           for row in csv_reader:
             y.append(int(row['Data']))
             ay.append(int(row['SpaceData']))
        plt.scatter(sequence, y, label=SensorModel, color='#000080', marker='o')
        plt.scatter(sequence, ay, label='SpaceData', color='#0000FF', marker='o')
    case 'GeigerCounter-low':
        plt.ylim(0.1, 10)
        plt.ylabel("usV/hr calculation for Geiger Counter")
        with open('../datascience/csv/GeigerCounter.csv', 'r') as file:
           csv_reader = csv.DictReader(file)
           for row in csv_reader:
             y.append(int(row['usV/hr']))
        plt.scatter(sequence, y, label=SensorModel, color='#000080', marker='o')
    case 'GeigerCounter-normal':
        plt.ylim(10, 100)
        plt.ylabel("usV/hr calculation for Geiger Counter")
        with open('../datascience/csv/GeigerCounter.csv', 'r') as file:
           csv_reader = csv.DictReader(file)
           for row in csv_reader:
             y.append(int(row['usV/hr']))
        plt.scatter(sequence, y, label=SensorModel, color='#000080', marker='o')
    case 'GeigerCounter-high':
        plt.ylim(100, 1000)
        plt.ylabel("usV/hr calculation for Geiger Counter")
        with open('../datascience/csv/GeigerCounter.csv', 'r') as file:
           csv_reader = csv.DictReader(file)
           for row in csv_reader:
             y.append(int(row['usV/hr']))
        plt.scatter(sequence, y, label=SensorModel, color='#000080', marker='o')

x_values = sequence  
y_values = y  

slope, intercept, r_value, p_value, std_err = linregress(x_values, y_values)

line = f'Y = {slope:.2f}X + {intercept:.2f}'

plt.plot(x_values, y_values, 'o', label='Data', color='#6600ff')
plt.plot(x_values, slope * np.array(x_values) + intercept, color='orange', label=f'Regression: {line}')

plt.legend()
plt.show()
