import matplotlib.pyplot as plt
import csv
import numpy as np
from scipy.stats import linregress

mode  = int(input("Would you prefer Y content ​to be static or malleable range to the DataScience chart? (0/1)?: "))
hello = int(input("Would you prefer to focus on Radioactivity or ppm values for Gas Sensors or Percentile for Data (1/2/3)?: "))

match(hello):
    case 1:
        SensorModel  = 'GeigerCounter'
        SensorYscale = "usv/hr calculation for Geiger Counter"
    case 2:
        SensorModel  = input("Enter the model of the MQ Gas sensor like MQ-303A: ")
        SensorYscale = "ppm values for " + SensorModel
    case 3:
        SensorModel  = 'SpaceData'
        SensorYscale = "Percentile for SpaceData"        

SensorData = SensorModel + " " + "Datasheet"      
SensorXscale = "Scaling time for " + SensorModel     


y = []

ay = []
by = []
cy = []
dy = []
ey = []
fy = []
gy = []

plt.figure(facecolor='white')
plt.gca().set_facecolor('white')
plt.xlabel(SensorXscale)
plt.ylabel(SensorYscale)
plt.title(SensorData)

def generate_sequence(depth):
    return list(range(0, depth+1))

with open('../DataScience/csv/{}.csv'.format(SensorModel), 'r') as file:
    depth = len(list(csv.reader(file))) - 2
    
sequence = generate_sequence(depth)
plt.xlim(0, depth)

def MQTime(file):
    csv_reader = csv.DictReader(file)
    for row in csv_reader:
        y.append(float(row['Data']))
        ay.append(float(row['H2']))
        by.append(float(row['LPG']))
        cy.append(float(row['CH4']))
        dy.append(float(row['CO']))
        ey.append(float(row['Alcohol']))
    plt.scatter(sequence, y, label=SensorModel, color='#000080', marker='o')
    plt.scatter(sequence, ay, label='H2', color='#0000FF', marker='o')
    plt.scatter(sequence, by, label='LPG', color='#000e44', marker='o')
    plt.scatter(sequence, cy, label='CH4', color='#87CEEB', marker='o')
    plt.scatter(sequence, dy, label='CO', color='#007FFF', marker='o')
    plt.scatter(sequence, ey, label='Alcohol', color='#40E0D0', marker='o')

def GeigerTime(file):
    with open('../DataScience/csv/GeigerCounter.csv', 'r') as file:
     csv_reader = csv.DictReader(file)
     for row in csv_reader:
       y.append(float(row['Data']))
    plt.scatter(sequence, y, label='usv/hr', color='#000080', marker='o')

match(SensorModel):
    case 'MQ-135':
        if (mode == 0):
         plt.ylim(0, 200)
        with open('../DataScience/csv/MQ-135.csv', 'r') as file:
           csv_reader = csv.DictReader(file)
           for row in csv_reader:
             y.append(float(row['Data']))
             ay.append(float(row['CO']))
             by.append(float(row['Alcohol']))
             cy.append(float(row['CO2']))
             dy.append(float(row['Toluen']))
             ey.append(float(row['NH4']))
             fy.append(float(row['Aceton']))
        plt.scatter(sequence, y, label=SensorModel, color='#000080', marker='o')
        plt.scatter(sequence, ay, label='CO', color='#0000FF', marker='o')
        plt.scatter(sequence, by, label='Alcohol', color='#000e44', marker='o')
        plt.scatter(sequence, cy, label='CO2', color='#87CEEB', marker='o')
        plt.scatter(sequence, dy, label='Toluen', color='#ADD8E6', marker='o')
        plt.scatter(sequence, ey, label='NH4', color='#007FFF', marker='o')
        plt.scatter(sequence, fy, label='Aceton', color='#40E0D0', marker='o')
    case 'MQ-2':
        if (mode == 0):
         plt.ylim(0, 10000)
        with open('../DataScience/csv/MQ-2.csv', 'r') as file:
           csv_reader = csv.DictReader(file)
           for row in csv_reader:
             y.append(float(row['Data']))
             ay.append(float(row['H2']))
             by.append(float(row['LPG']))
             cy.append(float(row['CO']))
             dy.append(float(row['Alcohol']))
             ey.append(float(row['Propane']))
             fy.append(float(row['CH4']))
             gy.append(float(row['Smoke']))
        plt.scatter(sequence, y, label=SensorModel, color='#000080', marker='o')
        plt.scatter(sequence, ay, label='H2', color='#0000FF', marker='o')
        plt.scatter(sequence, by, label='LPG', color='#000e44', marker='o')
        plt.scatter(sequence, cy, label='CO', color='#87CEEB', marker='o')
        plt.scatter(sequence, dy, label='Alcohol', color='#ADD8E6', marker='o')
        plt.scatter(sequence, ey, label='Propane', color='#007FFF', marker='o')
        plt.scatter(sequence, fy, label='CH4', color='#40E0D0', marker='o')
        plt.scatter(sequence, ey, label='Smoke', color='#40E0B0', marker='o')
    case 'MQ-3':
        if (mode == 0):
         plt.ylim(0, 500)
        with open('../DataScience/csv/MQ-3.csv', 'r') as file:
           csv_reader = csv.DictReader(file)
           for row in csv_reader:
             y.append(float(row['Data']))
             ay.append(float(row['LPG']))
             by.append(float(row['CH4']))
             cy.append(float(row['CO']))
             dy.append(float(row['Alcohol']))
             ey.append(float(row['Benzene']))
             fy.append(float(row['Hexane']))
        plt.scatter(sequence, y, label=SensorModel, color='#000080', marker='o')
        plt.scatter(sequence, ay, label='LPG', color='#0000FF', marker='o')
        plt.scatter(sequence, by, label='CH4', color='#000e44', marker='o')
        plt.scatter(sequence, cy, label='CO', color='#87CEEB', marker='o')
        plt.scatter(sequence, dy, label='Alcohol', color='#ADD8E6', marker='o')
        plt.scatter(sequence, ey, label='Benzene', color='#007FFF', marker='o')
        plt.scatter(sequence, fy, label='Hexane', color='#40E0D0', marker='o')
    case 'MQ-4':
        if (mode == 0):
         plt.ylim(0, 10000)
        with open('../DataScience/csv/MQ-4.csv', 'r') as file:
           csv_reader = csv.DictReader(file)
           for row in csv_reader:
             y.append(float(row['Data']))
             ay.append(float(row['H2']))
             by.append(float(row['LPG']))
             cy.append(float(row['CH4']))
             dy.append(float(row['CO']))
             ey.append(float(row['Alcohol']))
             fy.append(float(row['Smoke']))
        plt.scatter(sequence, y, label=SensorModel, color='#000080', marker='o')
        plt.scatter(sequence, ay, label='H2', color='#0000FF', marker='o')
        plt.scatter(sequence, by, label='LPG', color='#000e44', marker='o')
        plt.scatter(sequence, cy, label='CH4', color='#87CEEB', marker='o')
        plt.scatter(sequence, dy, label='CO', color='#ADD8E6', marker='o')
        plt.scatter(sequence, ey, label='Alcohol', color='#007FFF', marker='o')
        plt.scatter(sequence, fy, label='Smoke', color='#40E0D0', marker='o')
    case 'MQ-5':
        if (mode == 0):
         plt.ylim(0, 10000)
        with open('../DataScience/csv/MQ-5.csv', 'r') as file:
           MQTime(file)
    case 'MQ-6':
        if (mode == 0):
         plt.ylim(0, 10000)
        with open('../DataScience/csv/MQ-6.csv', 'r') as file:
           MQTime(file)
    case 'MQ-7':
        if (mode == 0):
         plt.ylim(0, 4000)
        with open('../DataScience/csv/MQ-7.csv', 'r') as file:
           MQTime(file)
    case 'MQ-8':
        if (mode == 0):
         plt.ylim(0, 10000)
        with open('../DataScience/csv/MQ-8.csv', 'r') as file:
           MQTime(file)
    case 'MQ-9':
        if (mode == 0):
         plt.ylim(0, 10000)
        with open('../DataScience/csv/MQ-9.csv', 'r') as file:
           csv_reader = csv.DictReader(file)
           for row in csv_reader:
             y.append(float(row['Data']))
             ay.append(float(row['LPG']))
             by.append(float(row['CH4']))
             cy.append(float(row['CO']))
        plt.scatter(sequence, y, label=SensorModel, color='#000080', marker='o')
        plt.scatter(sequence, ay, label='LPG', color='#0000FF', marker='o')
        plt.scatter(sequence, by, label='CH4', color='#000e44', marker='o')
        plt.scatter(sequence, cy, label='CO', color='#87CEEB', marker='o')
    case 'MQ-131':
        if (mode == 0):
         plt.ylim(0, 100)
        with open('../DataScience/csv/MQ-131.csv', 'r') as file:
           csv_reader = csv.DictReader(file)
           for row in csv_reader:
             y.append(float(row['Data']))
             ay.append(float(row['NOX']))
             by.append(float(row['CL2']))
             cy.append(float(row['O3']))
        plt.scatter(sequence, y, label=SensorModel, color='#000080', marker='o')
        plt.scatter(sequence, ay, label='NOX', color='#0000FF', marker='o')
        plt.scatter(sequence, by, label='CL2', color='#000e44', marker='o')
        plt.scatter(sequence, cy, label='O3', color='#87CEEB', marker='o')
    case 'MQ-136':
        if (mode == 0):
         plt.ylim(0, 200)
        with open('../DataScience/csv/MQ-136.csv', 'r') as file:
           csv_reader = csv.DictReader(file)
           for row in csv_reader:
             y.append(float(row['Data']))
             ay.append(float(row['H2S']))
             by.append(float(row['NH4']))
             cy.append(float(row['CO']))
        plt.scatter(sequence, y, label=SensorModel, color='#000080', marker='o')
        plt.scatter(sequence, ay, label='H2S', color='#0000FF', marker='o')
        plt.scatter(sequence, by, label='NH4', color='#000e44', marker='o')
        plt.scatter(sequence, cy, label='CO', color='#87CEEB', marker='o')
    case 'MQ-137':
        if (mode == 0):
         plt.ylim(0, 200)
        with open('../DataScience/csv/MQ-137.csv', 'r') as file:
           csv_reader = csv.DictReader(file)
           for row in csv_reader:
             y.append(float(row['Data']))
             ay.append(float(row['CO']))
             by.append(float(row['Ethanol']))
             cy.append(float(row['NH3']))
        plt.scatter(sequence, y, label=SensorModel, color='#000080', marker='o')
        plt.scatter(sequence, ay, label='CO', color='#0000FF', marker='o')
        plt.scatter(sequence, by, label='Ethanol', color='#000e44', marker='o')
        plt.scatter(sequence, cy, label='NH3', color='#87CEEB', marker='o')
    case 'MQ-303A':
        if (mode == 0):
         plt.ylim(0, 10000)
        with open('../DataScience/csv/MQ-303A.csv', 'r') as file:
           csv_reader = csv.DictReader(file)
           for row in csv_reader:
             y.append(float(row['Data']))
             ay.append(float(row['Isobuthane']))
             by.append(float(row['Hydrogen']))
             cy.append(float(row['Ethanol']))
        plt.scatter(sequence, y, label=SensorModel, color='#000080', marker='o')
        plt.scatter(sequence, ay, label='Isobuthane', color='#0000FF', marker='o')
        plt.scatter(sequence, by, label='Hydrogen', color='#000e44', marker='o')
        plt.scatter(sequence, cy, label='Ethanol', color='#87CEEB', marker='o')

    case 'MQ-309A':
        if (mode == 0):
         plt.ylim(0, 7000)
        with open('../DataScience/csv/MQ-309A.csv', 'r') as file:
           csv_reader = csv.DictReader(file)
           for row in csv_reader:
             y.append(float(row['Data']))
             ay.append(float(row['H2']))
             by.append(float(row['CH4']))
             cy.append(float(row['CO']))
             dy.append(float(row['Alcohol']))
             ey.append(float(row['LowCO']))
             fy.append(float(row['SecondH2']))
        plt.scatter(sequence, y, label=SensorModel, color='#000080', marker='o')
        plt.scatter(sequence, ay, label='H2', color='#0000FF', marker='o')
        plt.scatter(sequence, by, label='CH4', color='#000e44', marker='o')
        plt.scatter(sequence, cy, label='CO', color='#87CEEB', marker='o')
        plt.scatter(sequence, dy, label='Alcohol', color='#ADD8E6', marker='o')
        plt.scatter(sequence, ey, label='LowCO', color='#007FFF', marker='o')
        plt.scatter(sequence, fy, label='SecondH2', color='#40E0D0', marker='o')
    case 'SpaceData':
        if (mode == 0):
         plt.ylim(0, 100)
        with open('../DataScience/csv/SpaceData.csv', 'r') as file:
           csv_reader = csv.DictReader(file)
           for row in csv_reader:
             y.append(float(row['Data']))
        plt.scatter(sequence, y, label=SensorModel, color='#000080', marker='o')
    case 'GeigerCounter':
      if (mode == 1):
        user_choice = 4
      if (mode == 0):
        user_choice = float(input("Low mode, Medium mode, High mode or Special mode? (1/2/3/4): "))
      match(user_choice):
        case 1:
         plt.ylim(0.1, 10)
         GeigerTime(file)
        case 2:
         plt.ylim(10, 100)
         GeigerTime(file)
        case 3:
         plt.ylim(100, 1000)
         GeigerTime(file)
        case 4:
         GeigerTime(file)

# x_values = sequence  
# y_values = y  

slope, intercept, r_value, p_value, std_err = linregress(sequence, y)

line = f'Y = {slope:.2f}X + {intercept:.2f}'

plt.plot(sequence, y, 'o', label='Data', color='#6600ff')
plt.plot(sequence, slope * np.array(sequence) + intercept, color='orange', label=f'Regression: {line}')

plt.legend()
plt.show()
