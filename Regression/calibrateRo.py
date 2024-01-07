RSRoMQAir = int(input("Define your MQAir RS/Ro: ")) # RS/Ro VALUE

"""
---RS/Ro VALUE---
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
MQ-303A: 1
MQ-309A: 11
"""
# for soldered this value is 1
Rload =  int(input("Define your resistor value (kΩ): ")) # Define your Rload

percentile = int(input("Define the percentile you want to calibrate %0-100: "))

def calculateRoVeryEasy(defpercentile):
    RS = (100 * Rload / defpercentile) - Rload
    Ro = RS / RSRoMQAir
    return Ro

MyRovalue = calculateRoVeryEasy(percentile) 

print("Your Ro value is:")
print(MyRovalue)
