/*
this library is written for https://github.com/abcdaaaaaaaaa/Chernobyl project
by abcdaaaaaaaaa

ADC_BITB RESU value is 12 for esp32 models and 13 for esp32-s2 and 10 for esp8266 and
10 for arduino models (again, before defining) (check analog (not digital) adc bit resolution.)

!!This value is defined for 10k resistor, change it if you use a different value (Rload)!!!
*/

//!!!Definitely and definitely visit the information.ino file to see which sample you need!!!\\

#include <MQSpaceData.h>

#define Rload             (10)
#define ADC_BIT_RESU      (10)
#define space2            (5) 

MQSpaceData MQ2(ADC_BIT_RESU, Rload, space2);

void setup(){
Serial.begin(9600);
MQ2.begin();
MQ2.calibrateR0(2.74); // you can change it according to the value you find
//MQ2.MQ2calibrate();
}

void loop(){
	
  MQ2.valuea(987.99);  MQ2.valueb(-2.162);
  float H2 = MQ2.readValue();
  
  MQ2.valuea(574.25); MQ2.valueb(-2.222); 
  float LPG = MQ2.readValue();
  
  MQ2.valuea(36974);  MQ2.valueb(-3.109);
  float CO = MQ2.readValue();
  
  MQ2.valuea(3616.1);  MQ2.valueb(-2.675);
  float Alcohol = MQ2.readValue();
  
  MQ2.valuea(658.71);  MQ2.valueb(-2.168);
  float Propane = MQ2.readValue();
  
  Serial.print("H2:");
  Serial.println(H2);
  Serial.print("LPG:");
  Serial.println(LPG);
  Serial.print("CO:");
  Serial.println(CO);
  Serial.print("Alcohol:");
  Serial.println(Alcohol);
  Serial.print("Propane:");
  Serial.println(Propane);
  
//Serial.print("Total ppm:");
//Serial.println(MQ2.MQ2DataAir());
//Serial.print("Percentile%:");
//Serial.println(MQ2.MQData100());
}  
  /*
  Serial.print("H2:");
  Serial.println(MQ2.MQ2DataH2());
  Serial.print("LPG:");
  Serial.println(MQ2.MQ2DataLPG());
  Serial.print("CO:");
  Serial.println(MQ2.MQ2DataCO());
  Serial.print("Alcohol:");
  Serial.println(MQ2.MQ2DataAlcohol());
  Serial.print("Propane:");
  Serial.println(MQ2.MQ2DataPropane());	
  Serial.print("Total ppm:");
  Serial.println(MQ2.MQ2DataAir());
  Serial.print("Percentile%:");
  Serial.println(MQ2.MQData100());
  */	
