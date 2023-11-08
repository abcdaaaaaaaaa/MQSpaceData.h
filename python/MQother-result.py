from math import log10

user_response = input("Would you like an example regarding the calculation? (yes/no): ")

if user_response.lower() == "yes":
 print("For example, For LPG gas, the MQ-4 gas sensor has a y value of 2.6. This y value represents the initial reading of the sensor gas.")
 print("In the context of AverageY, it is important to note that it corresponds to the midpoint when the concentration reaches exactly 5000 ppm,")
 print("within the range of 200-10000 ppm. The ordinate value at this point aligns with the y value, which is 0.9 for the MQ-4 sensor with LPG gas.")
 print("As for the x value, it signifies the minimum required concentration, and since it falls within the 200-10,000 ppm range, x = 200 and x0 = 10000")
 print("NOTE: Average Y: For example, in a 10000 ppm gas sensor, the ordinate of the ppm point at x/2 point (10000/2) gives the AverageY value")
 print("For more detailed explanation, you can check out our github repository.")

if user_response.lower() == "no":
 print("For more detailed explanation, you can check out our github repository.")

def valueA(y, y0, x, x0):
    return round(log10(y/y0) / log10(x/x0), 4)

def valueB(y, AverageY, x, x0):
    return round(log10(AverageY) - valueA(y, y0, x, x0) * log10(x/2), 4)

def print_gas_table(gas_data):
    print("Gas    | a       | b")
    for gas, (a, b) in gas_data.items():
        print(f"{gas.ljust(7)}| {str(a).ljust(8)}| {str(b).ljust(7)}")

MQ_Model = input("please define your MQ model like MQ-303A: ")

gas_data = {}  

while True:
    Gas = input("name of the gas like LPG (type 'stop' to exit): ")

    if Gas == 'stop':
        break

    y0 = float(input(f"define first reference point of the graph for {Gas} (y0 value): "))
    y = float(input(f"define final reference point of the graph for {Gas}  (y value): "))
    x = float(input(f"define max ppm concentrate point of the graph for {Gas} (x value): "))
    x0 = float(input(f"define min ppm concentrate for {Gas} (x0 value): "))
    AverageY = float(input(f"define your y value at medium ppm concentration for {Gas} (AverageY value): "))

    a = valueA(y, y0, x, x0)
    b = valueB(y, AverageY, x, x0)

    gas_data[Gas] = (a, b)

    print("Continue with another gas (yes/no)?")
    user_input = input()
    if user_input.lower() != 'yes':
        break

print("Your MQ Model is " + str(MQ_Model))
print_gas_table(gas_data)
