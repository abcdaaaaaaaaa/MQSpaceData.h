/*
this library is written for https://github.com/abcdaaaaaaaaa/Chernobyl project
by abcdaaaaaaaaa

ADC_BITB RESU value is 12 for esp32 models and 13 for esp32-s2 and 10 for esp8266 and
10 for arduino models (again, before defining) (check analog (not digital) adc bit resolution.)

!!This value is defined for 10k resistor, change it if you use a different value (Rload)!!!
*/

//!!!Definitely and definitely visit the information.ino file to see which sample you need!!!\\

/*
advice:
(Except MQ-135) (MQ-135 is calibrated by percentage of reading where the sum of all data equals analog value 
(slightly less than 27% (10k resistor)) ). We calibrated all values ​​according to the idea that 
if the sensor could make an analog reading out of 100 in the laboratory, 
it should display 27 values ​​and should use a 10k resistor. 
If you want to calibrate with a different value (or if you are going to use a different resistor) 
and if you know what percentage you want to see, 
just visit the calibrateR0-veryeasy.ino file with the serial port screen without even connecting a sensor,
if you have a sensor and you don't have a percentage in mind, calibrateR0-normal.ino 
(and remember to have your sensor warmed up for 48 HOURS and provided the lab environment desired in the datasheet for this.) 
 We do not recommend calibrateR0-normal.ino, but rather the calibrateR0-veryeasy file, which measures much more FULLY.
(You can never get 100% accuracy in lab environments, 
if you insist on trying, we recommend it just to get an approximate result and have an idea, 
and then again with the exact percentage, we recommend you get a 100% accurate result in the with calibrateR0-veryeasy file)
*/
#include <MQSpaceData.h>

#define Rload             (10)  // define your Rload , if you are using normal card sensor please define 10
#define ADC_BIT_RESU      (10)  // ADC bit resulation
#define space             (A1)  // define your Analog pin

//!!This value is defined for 10k resistor, change it if you use a different value (Rload)!!!
//WARNING: If you are using resistors with a value other than 0k or 10k, do not use this example, 
//instead try the calirateR0-normal or calirateR0-veryeasy files and do not use our default values at all!

MQSpaceData MQ(ADC_BIT_RESU, Rload, space);

void setup(){
Serial.begin(9600);
MQ.MQ135calibrate();
MQ.begin();  
/* 
Note: in this example , we use only MQ135calibrate(); this function 
but you can see all function to calibrate sensor (find R0 value):
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
but if you want to do calibrate :
try calibrateR0-normal
like MQ.calibrateR0(8.2809);
this is an example for MQ135 if you want a different sensor please change MQ.MQ135calibrate(); this function
functions of sensors supported here given, if you are using a different MQ (not MQ-135) you can refer to MQ-?-ready
-------------------------------------------------------------------------------------------------------
Sensor Model: [MQ-2 , MQ-3 , MQ-4, MQ-5, MQ-6, MQ7, MQ-8 MQ-9, MQ-131, MQ-135, MQ-136, MQ-303A, MQ-309A]
WARNING: if you don't use this sensor model and you want to do calibrate 
you must refer calibrateR0-normal.ino or calibrateR0-veryeasy.ino.
WARNING: if you don't use this sensor model and you want to do set valuea and valueb you can calculate refer MQother-result 
if you want to more information please look this example : information.ino
*/
}

void loop(){
  MQ.valuea(605.18); MQ.valueb(-3.937); 
  float data = MQ.readValue(); 
  // if you dont want to set value :
  // try MQ-X-ready
  // like float data = MQ.MQ135DataCO();
  Serial.println(data);
  delay(300);
}
