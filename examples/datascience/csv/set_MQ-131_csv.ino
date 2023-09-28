import csv

data_list = []
data_number = 1
mode = input("Do you want to (a)dd data or (w)rite data to a new file? (a/w): ")

while True:
    print(f"Data {data_number}:")
    data = input("Data: ")
    nox = input("NOX: ")
    cl2 = input("CL2: ")
    o3 = input("O3: ")

    data_entry = {
        'Data': data,
        'NOX': nox,
        'CL2': cl2,
        'O3': o3
    }

    data_list.append(data_entry)

    continue_input = input("Do you want to add more data? (Y/N): ")
    if continue_input.lower() != 'y':
        break

    data_number += 1

with open('MQ-131.csv', mode, newline='') as file:
    fieldnames = ['Data', 'NOX', 'CL2', 'O3']
    writer = csv.DictWriter(file, fieldnames=fieldnames)
    
    if mode == 'w':
        writer.writeheader()

    for data_entry in data_list:
        writer.writerow(data_entry)

print("Data has been successfully written to the CSV file")
