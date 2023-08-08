/*
this library is written for https://github.com/abcdaaaaaaaaa/Chernobyl project
by abcdaaaaaaaaa

ADC_BITB RESU value is 12 for esp32 models and 13 for esp32-s2 and 10 for esp8266 and
10 for arduino models (again, before defining) (check analog (not digital) adc bit resolution.)

!!This value is defined for 10k resistor, change it if you use a different value (Rload)!!!
*/

//!!!Definitely and definitely visit the information.ino file to see which sample you need!!!\\


#include "MQSpaceData.h"

//please redefine according to card and sensor we will use values!!!!

// like MQ-4:
#define y              (0.75)  // final reference point of the graph
#define y0             (2.6)   // first reference point of the graph
#define x              (10000) // max ppm concentrate
#define x0             (200)   // min ppm concentrate

#define RSR0MQAir         (4.4) // RS / R0 you should look straight line (Air value) (graphic)
#define Rload             (10) // define your Rload , if you are not sure define 10
// define your adc bit resulation, 
//if you use arduino please define 10 , if you use esp32 please define 12,  if you use esp32-s2 please define 13
#define ADC_BIT_RESU      (10)  
#define Voltage           (5) 
#define space             (A1)

result calculateMQresult(y, y0, x, x0);
calibrateR0 R0value(RSR0MQAir, Voltage, ADC_BIT_RESU, Rload, space);
MQSpaceData MQother(ADC_BIT_RESU, Rload, space);
float valueA, valueB, lastPercentage, lastVoltage, lastResult;

void setup() {
  Serial.begin(9600); //Baud rate 
  MQother.begin();

  for(int i = 0 ; i < 500 ; i++) // calibrateR0 500 time = 500 * 500 = 250000 time
  {
  lastPercentage = ((R0value.readVoltage()/Voltage)*100);
  lastVoltage = R0value.readVoltage();
  lastResult = R0value.calculateR0();  
  }
   
// when calibrating, what percentage of the sensor is written

  MQother.calibrateR0(lastResult);
  valueA = calculateMQresult.resultA();
  valueB = calculateMQresult.resultB();
  Serial.print("Voltage:");
  Serial.println(lastVoltage);
  Serial.print("%0-100 SensorValue:");
  Serial.println(lastPercentage);
  Serial.print("Define Your R0 value!:");
  Serial.println(lastResult);
  Serial.print("valueA = ");
  Serial.println(valueA); 
  Serial.print("valueB = ");
  Serial.print(valueB);
}
 
void loop() {  
 MQother.valuea(valueA); MQother.valueb(valueB);
  float data = MQother.readValue(); 
// Serial.println(data);  
}
/*
it is not recommended to have the values ​​calibrated by the system each time and repeatedly 
have the a and b values ​​calculated by the system notrecommended, 
write down the values ​​you find and define the values ​​directly next time (MQresult-ready.ino) 
and this will save you code and time
-----------------------
like this:
MQother.calibrateR0(???);
MQother.valuea(???);
MQother.valueb(???);
--------------------
this is the normal calibration method but if you want to calibrate this way
we recommend that you warm up your sensor for 48 hours and calibrate it 
after you have met the correct conditions on the datasheet. 
however, remember that you can never provide 100% environment in a laboratory environment and
use this method only to get an idea. once you have a clear idea of ​​setting the percentage to calibrate (we set it to 27%)
*/
