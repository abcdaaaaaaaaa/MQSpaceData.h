/*
this library is written for https://github.com/abcdaaaaaaaaa/Chernobyl project
by abcdaaaaaaaaa

!!!This value is defined for 10k resistor, change it if you use a different value (Rload)!!!
*/

//!!!Definitely and definitely visit the information.ino file to see which sample you need!!!\\

//Calibrate your sensor very quickly and precisely WİTHOUT connecting the sensor 
//(remember, you can never provide 100% environment in a laboratory environment)
//Just tell us how many k resistors you would have connected if you had your sensor with you,
//and if you could meet the necessary conditions, how many value (like 27%) would you want 
//if your sensor were analog reading  0-100 in those. 
//and you would get the most accurate result with just the serial port screen (without using any sensor)!

/////////////////////////WARNING://///////////////////////
//if your intention is not to calculate a and b values ​​but just to calibrate, go to calibrateR0-veryeasy.ino

#include <MQSpaceData.h>

// like MQ-4:
#define y              (0.75)  // final reference point of the graph
#define y0             (2.6)   // first reference point of the graph
#define x              (10000) // max ppm concentrate
#define x0             (200)   // min ppm concentrate
// You don't need to calculate a and b value, we'll just calculate it with the slope you provided.

#define RSR0MQAir         (4.4) // RS / R0 you should look straight line (Air value) (graphic)
#define Rload             (10) // define your Rload , if you are not sure define 10
// define your adc bit resulation, 
//if you use arduino please define 10 , if you use esp32 please define 12,  if you use esp32-s2 please define 13
#define ADC_BIT_RESU      (10)  
#define space             (A1)

calibrateR0VeryEasy easy(RSR0MQAir,Rload);
float mypercentile = 27; // define your percentile

result calculateMQresult(y, y0, x, x0);
calibrateR0VeryEasy R0value(RSR0MQAir, Rload);
MQSpaceData MQother(ADC_BIT_RESU, Rload, space);
float valueA, valueB, lastResult;

void setup(){
Serial.begin(9600);
float lastResult = easy.calculateR0VeryEasy(mypercentile);
// when calibrating, what percentage of the sensor is written

  MQother.calibrateR0(lastResult);
  valueA = calculateMQresult.resultA();
  valueB = calculateMQresult.resultB();
  Serial.print("Define Your R0 value!:");
  Serial.println(lastResult);
  Serial.print("valueA = ");
  Serial.println(valueA); 
  Serial.print("valueB = ");
  Serial.print(valueB);
}

void loop(){
 MQother.valuea(valueA); MQother.valueb(valueB);
 float data = MQother.readValue(); 
// Serial.println(data);    
}

//It is not recommended to be calculated by the system in this way every time. After calculating the values,
//we recommend that you define the values ​​you noted in the MQother-ready file
//here the loop is shown as an example no sensor is needed for this operation 
//if you don't have the sensor with you you can remove the MQother class from the code
