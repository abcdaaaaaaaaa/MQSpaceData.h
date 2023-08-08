/*
this library is written for https://github.com/abcdaaaaaaaaa/Chernobyl project
by abcdaaaaaaaaa

ADC_BITB RESU value is 12 for esp32 models and 13 for esp32-s2 and 10 for esp8266 and
10 for arduino models (again, before defining) (check analog (not digital) adc bit resolution.)

!!This value is defined for 10k resistor, change it if you use a different value (Rload)!!!
*/

//!!!Definitely and definitely visit the information.ino file to see which sample you need!!!\\

#include <MQSpaceData.h>

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
MQSpaceData MQ-other(ADC_BIT_RESU, Rload, space);
float valueA, valueB, lastPercentage, lastVoltage, lastResult;

void setup() {
  Serial.begin(9600); //Baud rate 
  MQother.begin();
  MQother.calibrateR0(???);
}
 
void loop() {  
  MQother.valuea(???); MQother.(???); 
  float data = MQother.readValue(); 
  Serial.println(data);  
}

// WARNING: if you don't know how to define values, upload MQother-result.ino codes and it will give you how to define which values ​​on serial port screen
