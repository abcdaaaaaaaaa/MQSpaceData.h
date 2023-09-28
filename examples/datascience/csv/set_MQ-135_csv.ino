import csv

data_list = []
data_number = 1
mode = input("Do you want to (a)dd data or (w)rite data to a new file? (a/w): ")

while True:
    print(f"Data {data_number}:")
    data = input("Data: ")
    co = input("CO: ")
    alcohol = input("Alcohol: ")
    co2 = input("CO2: ")
    toluen = input("Toluen: ")
    nh4 = input("NH4: ")
    aceton = input("Aceton: ")

    data_entry = {
        'Data': data,
        'CO': co,
        'Alcohol': alcohol,
        'CO2': co2,
        'Toluen': toluen,
        'NH4': nh4,
        'Aceton': aceton
    }

    data_list.append(data_entry)

    continue_input = input("Do you want to add more data? (Y/N): ")
    if continue_input.lower() != 'y':
        break

    data_number += 1

with open('MQ-135.csv', mode, newline='') as file:
    fieldnames = ['Data', 'CO', 'Alcohol', 'CO2', 'Toluen', 'NH4', 'Aceton']
    writer = csv.DictWriter(file, fieldnames=fieldnames)
    
    if mode == 'w':
        writer.writeheader()

    for data_entry in data_list:
        writer.writerow(data_entry)

print("Data has been successfully written to the CSV file")
