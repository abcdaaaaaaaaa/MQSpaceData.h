# MQSpaceData MQ Sensor List
![mqsensorlist1000](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/5864202a-d58a-4222-b760-0bacb5bf790a)

![download](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/237c07c9-eb5d-4b5e-8a3a-f85b47d5a32a)
![download](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/9696bed8-0022-42e0-8e76-e7df86c82e2d)
![download](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/da908954-4551-41f3-8213-d2ebcb33f1e3)
![download](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/13ec7e02-8f95-499a-ab3b-d5d498678b1b)
![download](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/543dcd47-b0bc-4950-b2ac-32b7c042d148)
![download](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/3aefabcf-b839-4319-a751-2b1ae3831930)
![download](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/16c905a9-1b72-47a1-bcd3-21d06929a54b)
![download](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/23469cf2-4ba2-4558-9cce-b846f13bd868)
![download](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/b1160e80-ee63-4a92-bee5-a7ac20b60fcc)
![download](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/1cb9be4b-93da-4705-ba2f-40a492a21619)
![download](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/13ea44fa-d69d-4b76-be10-03befd6b5c60)
![download](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/b4d5e6bc-2454-4a21-a4be-ff8f10f83e1c)

[MQ-2, MQ-3, MQ-4, MQ-5, MQ-6, MQ-7, MQ-8, MQ-9, MQ-131, MQ-135, MQ-136, MQ-303A, MQ-309A]
Calibrating is now easy with the MQSpaceData library:
Without connecting the sensor to your card, just show the percentage you will calibrate and define the RS/R0 difference and we will calibrate for you without laboratory conditions. If you are using one of the listed sensors, you do not need to calibrate. Download the MQ-X-ready or MQ-X-normal files, but if you are not using the listed gas sensors, feel free to download this library anyway: first define RS/R0 in the datasheet graphic, below is the example of MQ-4 just like it:
```
#include <MQSpaceData.h>

#define RSR0MQAir (4.4) // RS / R0 you should look straight line (Air value) (graphic)
/*
---RS/R0 VALUE---
MQ-2: 9.83
MQ-3: 60
MQ-4: 4.4
MQ-5: 6.5
MQ-6: 10
MQ-7: 27.5
MQ-8: 70
MQ-9: 9.6
MQ-131: 15
MQ-135: 3.6
MQ-136: 3.6
MQ-303A: 1
MQ-309A: 11
*/
// define your own Rload
#define Rload    (10) // if you are going to use a resistor other than 10k replace it 

calibrateR0VeryEasy easy(RSR0MQAir,Rload);
float mypercentile = 27; // define your percentile
// like MQ-4 concentration range is 200-10000 ,  10000+200 = 12000ppm , percentile = mypercentile/100
// we defined 27 so percentile = 27 /100 = 0,27  ppm to be calibrated: 12000 x 0.27 = 3240ppm
void setup(){
Serial.begin(9600);
float R0value = easy.calculateR0VeryEasy(mypercentile);
Serial.print("calibrating..");
Serial.println();
Serial.print("Your R0 value is:");
Serial.println(R0value);
}

void loop(){
  
}
```
And We can also calculate the a and b values ​​for you:
just define the concentration range of your gas sensor and the slopes of the graph just like the MQ4:
![download](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/39f97873-8173-4831-b662-45d26f59cd1f)
```
#include <MQSpaceData.h>

// like MQ-4:
#define y              (0.75)  // final reference point of the graph
#define y0             (2.6)   // first reference point of the graph
#define x              (10000) // max ppm concentrate
#define x0             (200)   // min ppm concentrate

float valueA, valueB;
result calculateMQresult(y, y0, x, x0);

void setup(){
Serial.begin(9600);

  valueA = calculateMQresult.resultA();
  valueB = calculateMQresult.resultB();
  Serial.print("valueA = ");
  Serial.println(valueA); 
  Serial.print("valueB = ");
  Serial.print(valueB);
}

void loop(){
  
}
```

then you can define values:

```
#include <MQSpaceData.h>

#define Rload             (10) // define your Rload , if you are not sure define 10
// define your adc bit resulation, 
//if you use arduino please define 10 , if you use esp32 please define 12,  if you use esp32-s2 please define 13
#define ADC_BIT_RESU      (10)  
#define space             (A1)

MQSpaceData MQother(ADC_BIT_RESU, Rload, space);

void setup() {
  Serial.begin(9600); //Baud rate 
  MQother.begin();
  MQother.calibrateR0(???);
}
 
void loop() {  
  MQother.valuea(???); MQother.valueb(???); 
  float data = MQother.readValue(); 
  Serial.println(data);  
}
```

that's all, if you use a Geiger Counter instead of a gas sensor, you can still download this library:

![download](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/27061f03-3224-4ccd-91d6-92396889c9fd)

```
#include <MQSpaceData.h>

// define true to the values ​​you want to calculate as false you don't want.
// The values ​​you define as false will be 0 on the screen output.
#define uSvhr1      (true)
#define Avg1        (true)
#define CPM_Count1  (true)
#define LOG_PERIOD1 (30000) // enter your waiting period (30 second = 30000) 30 seconds is ideal
#define GeigerPin1  (2)

//Putting it on hold (30 seconds is recommended) will allow your sensor to measure more accurately.

GeigerCounterPin Radyoactivite(uSvhr1, Avg1, CPM_Count1, LOG_PERIOD1, GeigerPin1);
 
void setup(){
Serial.begin(9600);
Radyoactivite.begin();
}

void loop(){
Radyoactivite.radyoactivite();
Serial.print("Usv/hr:");
Serial.println(Radyoactivite.usvhr); // uSvhr 
Serial.print("Avg:");
Serial.println(String(Radyoactivite.Avg) + "+/-" + String(Radyoactivite.sdCPM)); // Avg 
Serial.print("CPM Count:");
Serial.println(Radyoactivite.count);  // CPM_Count
}
```
![download](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/09bf5010-82dd-49ac-9deb-5251e3fc41bc)
In addition, this library provides python examples that you can do with the easy calibration method and datasheet calculations:
Try calculating the data (a and b values) we gave in the first example with the numpy library:
```
import numpy as np

y  = 0.75  #define final reference point of the graph
y0 = 2.6   #define first reference point of the graph
x  = 10000 #define max ppm concentrate
x0 = 200   #define min ppm concentrate

def resultA():
  return np.log(y/y0) / np.log(x/x0);

def resultB():
  return np.log(y) - resultA()*np.log(x)

print("ValueA:")
print(resultA())
print("ValueB:")
print(resultB())
```
and try the different calibrating method we mentioned at the beginning in python:
```
RSR0MQAir = 4.4 #RS/R0 VALUE

"""
---RS/R0 VALUE---
MQ-2: 9.83
MQ-3: 60
MQ-4: 4.4
MQ-5: 6.5
MQ-6: 10
MQ-7: 27.5
MQ-8: 70
MQ-9: 9.6
MQ-131: 15
MQ-135: 3.6
MQ-136: 3.6
MQ-303A: 1
MQ-309A: 11
"""

Rload = 10 #Define your Rload

percentile = 27 #Define your percentile

def calculateR0VeryEasy(defpercentile):

 RS = (100 * Rload / defpercentile) - Rload

 R0 = RS / RSR0MQAir

 return R0

MyR0value = calculateR0VeryEasy(percentile) 

print("Your R0 value is:")
print(MyR0value)
```
