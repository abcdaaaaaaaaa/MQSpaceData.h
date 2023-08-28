bit = int(input("define your card: If you are using Arduino UNO, Arduino NANO, Arduino Mega or esp8266 boards, define 1 if using esp32, 2 if using esp32-s2, then 3:"))

match bit:
 case 1:
  print("Your ADC BIT Resulation: 10")
 case 2:
  print("Your ADC BIT Resulation: 12")
 case 3:
  print("Your ADC BIT Resulation: 13")