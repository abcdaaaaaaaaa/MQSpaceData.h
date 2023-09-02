/*
this library is written for https://github.com/abcdaaaaaaaaa/Chernobyl project
by abcdaaaaaaaaa
*/

//!!!Definitely and definitely visit the information.ino file to see which sample you need!!!\\

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

//if you have calibrated the values ​​in the files: calibrateR0-veryeasy.ino or calibrateR0-normal.ino, 
//and if you dont use sensor list [MQ-2, MQ-3, MQ-4, MQ-5, MQ-6, MQ-7, MQ-8, MQ-9, MQ-131, MQ-135, MQ-136, MQ-303A, MQ-309A]
//define the values ​​in the MQother-ready example so that you have defined the values ​​in your external sensor.