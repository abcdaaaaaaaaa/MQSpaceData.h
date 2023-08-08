/*
this library is written for https://github.com/abcdaaaaaaaaa/Chernobyl project
by abcdaaaaaaaaa

!!!This value is defined for 10k resistor, change it if you use a different value (Rload)!!!
*/

//!!!Definitely and definitely visit the information.ino file to see which sample you need!!!\\

/////////////////////////////////////////WARNİNG PLS READ LAST TİME/////////////////////////////////////////
//You can use this example if you are sure despite the explanations in the information.ino, 
//calibratoR 0-ready and calibratoR 0-normal file
//WARNING: use it only for idea, and to get correct result leave the circuit open for 48 hours after uploading (heat it up) 
//and ensure the LAB environment (NOT RANDOM ROOM) in the datasheet correctly
#include "MQSpaceData.h"

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
#define Rload             (10) // define your Rload , if you are not sure define 10
// define your adc bit resulation, 
//if you use arduino please define 10 , if you use esp32 please define 12,  if you use esp32-s2 please define 13
#define ADC_BIT_RESU      (10) 
// define your analog voltage if you use esp32 or esp8266 define 3.3 but if you use arduino define 5 
#define Voltage           (5) 
#define space             (A1) //define your analog pin 

calibrateR0 R0value(RSR0MQAir, Voltage, ADC_BIT_RESU, Rload, space);
float valueA, valueB, lastPercentage, lastVoltage, lastResult;

void setup() {
  Serial.begin(9600); //Baud rate 
  R0value.begin();   // setup your sensor 
}
 
void loop() {  
   // iwe recommend throwing your circuit for 48 hours.
   // we want to save last value so we define exstra one float char
  lastPercentage = ((R0value.readVoltage()/Voltage)*100);
  lastVoltage = R0value.readVoltage();
  lastResult = R0value.calculateR0();  

// when calibrating, what percentage of the sensor is written

  Serial.print("Voltage:");
  Serial.println(lastVoltage);
  Serial.print("%0-100 SensorValue:");
  Serial.println(lastPercentage);
  Serial.print("Define Your R0 value!:");
  Serial.println(lastResult);

//After making sure that you have calculated the lastResult in SUITABLE conditions 
//(varies according to the air quality and chemistry of the environment), 
//you can directly calibrate it using the MQSpaceData class without using this loop again.

 // MQ-?.calibrateR0(lastResult); 

}
