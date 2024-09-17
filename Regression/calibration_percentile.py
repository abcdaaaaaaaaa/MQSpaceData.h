RSRoMQAir = float(input("Enter the MQAir Rs/Ro: "))  # Rs/Ro VALUE

"""
---Air VALUE---
MQ-2: 9.8
MQ-3: 60.53
MQ-4: 4.4
MQ-5: 6.5
MQ-6: 10
MQ-7: 26
MQ-8: 70
MQ-9: 9.7
MQ-131: 12
MQ-135: 3.6
MQ-136: 3.54
MQ-137: 3.54
MQ-303A: 1 (Since it does not fall within the ppm range where gases are defined, it is not valid for gas calculations.)
MQ-307A: Does not contain any Air values.
MQ-309A: 11 (Since it does not fall within the ppm range where gases are defined, it is not valid for gas calculations.)
"""

clean_air = int(input(
    "\n"
    "At what concentration level in ppm does the sensor resistance (Ro) occur in clean air (also see sensor datasheet)?\n"
    "---------------------------OR---------------------------\n"
    "When the Rs/Ro value of any gas is 1, how many ppm was the gas (also see sensor datagraphic)? "
))

gas_count = int(input("\nEnter the number of gases: "))
gas_names = [input(f"Enter name for Gas-{i + 1}: ") for i in range(gas_count)]
gas_values = [int(input(f"Enter Rs/Ro level in ppm for {gas} at point {clean_air} ppm of the sensor: ")) for gas in gas_names]

percentile_values = [round(value / RSRoMQAir * 100, 2) for value in gas_values]

print("\nPercentile Values for Each Gas:")
for gas, percentile in zip(gas_names, percentile_values):
    print(f"{gas}: {percentile}%")
