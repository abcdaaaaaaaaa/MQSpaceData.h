import csv

data_list = []
data_number = 1
mode = input("Do you want to (a)dd data or (w)rite data to a new file? (a/w): ")

while True:
    print(f"Data {data_number}:")
    data = input("Data: ")
    h2 = input("H2: ")
    lpg = input("LPG: ")
    co = input("CO: ")
    alcohol = input("Alcohol: ")
    propane = input("Propane: ")
    ch4 = input("CH4: ")
    smoke = input("Smoke: ")

    data_entry = {
        'Data': data,
        'H2': h2,
        'LPG': lpg,
        'CO': co,
        'Alcohol': alcohol,
        'Propane': propane,
        'CH4': ch4,
        'Smoke': smoke
    }

    data_list.append(data_entry)

    continue_input = input("Do you want to add more data? (Y/N): ")
    if continue_input.lower() != 'y':
        break

    data_number += 1

with open('MQ-2.csv', mode, newline='') as file:
    fieldnames = ['Data', 'H2', 'LPG', 'CO', 'Alcohol', 'Propane', 'CH4', 'Smoke']
    writer = csv.DictWriter(file, fieldnames=fieldnames)
    
    if mode == 'w':
        writer.writeheader()

    for data_entry in data_list:
        writer.writerow(data_entry)

print("Data has been successfully written to the CSV file")
