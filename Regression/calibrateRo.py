RSRoMQAir = int(input("Enter the MQAir RS/Ro: ")) # RS/Ro VALUE

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
MQ131: 12
MQ-135: 3.6
MQ-136: 3.54
MQ-137: 3.54
MQ303A: 1 (Not Important)
MQ307A: No Air (Not Important)
MQ309A 11 (Not Important)
"""

# for soldered this value is 1
Rload =  int(input("Define your resistor value (kΩ): ")) # Define your Rload

percentile = int(input("Define the percentile you want to calibrate %0-100: "))

def calculateRoVeryEasy(defpercentile):
    Rs = (100 * Rload / defpercentile) - Rload
    Ro = RS / RSRoMQAir
    return Ro

def calculateRsVeryEasy(defpercentile):
    Rs = (100 * Rload / defpercentile) - Rload
    return Rs
    
MyRovalue = calculateRoVeryEasy(percentile) 

print("Your Ro value is:")
print(MyRovalue)

# for MQ303A, MQ307A, MQ309A  [A models]
# MyRsvalue = calculateRsVeryEasy(percentile) 

# print("Your Rs value is:")
# print(MyRsvalue)
