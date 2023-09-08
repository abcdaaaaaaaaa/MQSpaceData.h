# MQSpaceData MQ Sensor List
MQ Sensor List: [MQ-2, MQ-3, MQ-4, MQ-5, MQ-6, MQ-7, MQ-8, MQ-9, MQ-131, MQ-135, MQ-136, MQ-303A , MQ-309A]
![mqsensorlist1000](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/5864202a-d58a-4222-b760-0bacb5bf790a)
## MQSpaceData Contents
* [MQ Sensor Datasheet](#MQSensorData)
* [Start with MQ-X](#MQ-X)
  * [Start with MQ-135](#MQ-135)
  * [MQ-X-ready folder](#MQ-X-ready)
  * [MQ-X-normal folder](#MQ-X-normal)
* [Sensor Electronics](#Sensor)
  * [for Arduino](#Arduino)
  * [for ESP-32](#ESP-32)
  * [for ESP8266](#ESP8266)
  * [for ESP32-S2](#ESP32-S2)
* [Calibrate Your Sensor R0](#Calibrate)
* [Redefine Your Value a and b](#Arduino)
* [Calculate With Python](#Python)
  * [Redefine your value a and b with numpy](#numpy)
  * [Calibrate Your R0 Value](#R0python)
  * [Learn Your ADC BIT Resulation](#ADCBIT)
* [Radioactivity For Geiger Counter](#Radioactivity)

## MQSensorData
### MQ Sensor Datasheet:
| MQ Sensor | URL Datasheet |
|----------|----------|
| MQ-2 | [datasheet](https://www.pololu.com/file/0J309/MQ2.pdf) |
| MQ-3 | [datasheet](https://www.sparkfun.com/datasheets/Sensors/MQ-3.pdf) |
| MQ-4 | [datasheet](https://www.sparkfun.com/datasheets/Sensors/Biometric/MQ-4.pdf) |
| MQ-5 | [datasheet](https://www.parallax.com/sites/default/files/downloads/605-00009-MQ-5-Datasheet.pdf) |
| MQ-6 | [datasheet](https://www.sparkfun.com/datasheets/Sensors/Biometric/MQ-6.pdf) |
| MQ-7 | [datasheet](https://www.sparkfun.com/datasheets/Sensors/Biometric/MQ-7.pdf) |
| MQ-8 | [datasheet](https://dlnmh9ip6v2uc.cloudfront.net/datasheets/Sensors/Biometric/MQ-8.pdf) |
| MQ-9 | [datasheet](http://www.haoyuelectronics.com/Attachment/MQ-9/MQ9.pdf) |
| MQ-131 | [datasheet](http://www.sensorsportal.com/DOWNLOADS/MQ131.pdf) |
| MQ-135 | [datasheet](https://www.electronicoscaldas.com/datasheet/MQ-135_Hanwei.pdf) |
| MQ-136 | [datasheet](https://github.com/miguel5612/MQSensorsLib_Docs/blob/master/Datasheets/MQ136%20-%20Hanwei.pdf) |
| MQ-303A | [datasheet](http://www.kosmodrom.com.ua/pdf/MQ303A.pdf) |
| MQ-309A | [datasheet](http://www.sensorica.ru/pdf/MQ-309A.pdf) |

## MQ-X
### MQ-135
# Start With MQ-135
### MQ-X-ready
# MQ-X-ready folder (little code)
# Get started with the MQ-135 with ready-made functions
```
#include <MQSpaceData.h>

#define Rload             (10)
#define ADC_BIT_RESU      (10)
#define space135          (A1)

MQSpaceData MQ135(ADC_BIT_RESU, Rload, space135);

void setup(){
Serial.begin(9600);
MQ135.begin();
MQ135.MQ135calibrate(); // Ready Calibration
//  or define your custom calibration
//MQ135.calibrateR0(8.2809);
}

void loop(){
  Serial.print("CO:");
  Serial.prinln(MQ135.MQ135DataCO()); 
  Serial.print("Alcohol:");
  Serial.println(MQ135.MQ135DataAlcohol());
  Serial.print("CO2:");
  Serial.println(MQ135.MQ135DataCO2());
  Serial.print("Toluen:");
  Serial.println(MQ135.MQ135DataToluen());
  Serial.print("NH4:");
  Serial.println(MQ135.MQ135DataNH4());
  Serial.print("Aceton:");
  Serial.println(MQ135.MQ135DataAceton());  
  Serial.print("Total ppm:");
  Serial.println(MQ135.MQ135DataAir());
  Serial.print("Percentile%:");
  Serial.println(MQ135.MQData100());
}
```
### MQ-X-normal
# MQ-X-normal folder (show off)
# MQ-135 example 
or instead of the ready-made functions we have saved in the library, you define the values in order, just like the example we showed on the MQ-4 for sensors not listed below
NOTE: There is no difference between MQ-X-ready and MQ-X-regular files
```
#include <MQSpaceData.h>

#define Rload             (10)
#define ADC_BIT_RESU      (10)
#define space135          (A1)

MQSpaceData MQ135(ADC_BIT_RESU, Rload, space135);

void setup(){
Serial.begin(9600);
MQ135.calibrateR0(8.209); // you can change it according to the value you find
// MQ135.MQ135calibrate();
MQ135.begin();  
}

void loop(){
	
  MQ135.valuea(605.18); MQ135.valueb(-3.937); 
  float CO = MQ135.readValue(); 
  
  MQ135.valuea(77.255); MQ135.valueb(-3.18); 
  float Alcohol = MQ135.readValue(); 

  MQ135.valuea(110.47); MQ135.valueb(-2.862); 
  float CO2 = MQ135.readValue(); 

  MQ135.valuea(44.947); MQ135.valueb(-3.445); 
  float Toluen = MQ135.readValue(); 
  
  MQ135.valuea(102.2 ); MQ135.valueb(-2.473); 
  float NH4 = MQ135.readValue(); 

  MQ135.valuea(34.668); MQ135.valueb(-3.369); 
  float Aceton = MQ135.readValue(); 
  
Serial.print("CO:");
Serial.println(CO); 
Serial.print("Alcohol:");
Serial.println(Alcohol);
Serial.print("CO2:");
Serial.println(CO2);
Serial.print("Toluen:");
Serial.println(Toluen);
Serial.print("NH4:");
Serial.println(NH4);
Serial.print("Aceton:");
Serial.println(Aceton);

Serial.print("Total ppm:");
Serial.println(MQ135.MQ135DataAir());
Serial.print("Percentile%:");
Serial.println(MQ135.MQData100());
}
```
# The ready calibration (find your R0 value) values (function) we calculated for the MQ Sensors in the sensor list:
NOTE: If you are using a resistor other than 10k (or 0k), we do not recommend using this mode.
```
MQ2calibrate();
MQ3calibrate();
MQ4calibrate();
MQ5calibrate();
MQ6calibrate();
MQ7calibrate();
MQ8calibrate();
MQ9calibrate();
MQ131calibrate();
MQ135calibrate();
MQ136calibrate();
MQ303Acalibrate();
MQ309Acalibrate();
```
# if you are using a resistor other than 10k you can still calibrate:
# Calibrate Your Sensor (R0) Very Easily
[MQ-2, MQ-3, MQ-4, MQ-5, MQ-6, MQ-7, MQ-8, MQ-9, MQ-131, MQ-135, MQ-136, MQ-303A, MQ-309A]
Calibrating is now easy with the MQSpaceData library:
Without connecting the sensor to your card, just show the percentage you will calibrate and define the RS/R0 difference and we will calibrate for you without laboratory conditions. If you are using one of the listed sensors, you do not need to calibrate. Download the MQ-X-ready or MQ-X-normal folders, but if you are not using the listed gas sensors, feel free to download this library anyway: first define RS/R0 in the datasheet graphic, below is the example of MQ-4 just like it:

![MQ4datashee](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/9e72a831-2342-4da8-8d4b-f0e1dcd84aba)

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
# Calculate valueA and valueB with Logarithm 
And We can also calculate the a and b values ​​for you:
just define the concentration range of your gas sensor and the slopes of the graph just like the MQ4:
![MQ4datasheet](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/ed616dc8-3145-4233-9741-5e848bdae377)
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
### Radioactivity
# Radioactive Calculation with Geiger Counter

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
## Python
# Calculate valueA and valueB with Python
### numpy
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
### R0python
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
