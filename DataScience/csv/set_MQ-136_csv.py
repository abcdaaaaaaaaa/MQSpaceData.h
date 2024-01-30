import csv

data_list = []
data_number = 1
mode = input("Do you want to (a)dd data or (w)rite data to a new file? (a/w): ")

while True:
    print(f"Data {data_number}:")
    data = input("Data: ")
    h2s = input("H2S: ")
    nh4 = input("NH4: ")
    co = input("CO: ")

    data_entry = {
        'Data': data,
        'H2S': h2s,
        'NH4': nh4,
        'CO': co
    }

    data_list.append(data_entry)

    continue_input = input("Do you want to add more data? (Y/N): ")
    if continue_input.lower() != 'y':
        break

    data_number += 1

with open('MQ-136.csv', mode, newline='') as file:
    fieldnames = ['Data', 'H2S', 'NH4', 'CO']
    writer = csv.DictWriter(file, fieldnames=fieldnames)
    
    if mode == 'w':
        writer.writeheader()

    for data_entry in data_list:
        writer.writerow(data_entry)

print("Data has been successfully written to the CSV file")
