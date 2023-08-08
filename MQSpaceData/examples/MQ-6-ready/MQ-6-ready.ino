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
#define space5            (A1)

MQSpaceData MQ5(ADC_BIT_RESU, Rload, space6);

void setup(){
Serial.begin(9600);
MQ5.begin();
MQ5.MQ5calibrate(2.71); // you can change it according to the value you find
//MQ5.calibrateR0();
}

void loop(){
  Serial.print("H2:");
  Serial.println(MQ6.MQ6DataH2()); 
  Serial.print("LPG:");
  Serial.println(MQ6.MQ6DataLPG());
  Serial.print("CH4:");
  Serial.println(MQ6.MQ6DataCH4());
  Serial.print("CO:");
  Serial.println(MQ6.MQ6DataCO());
  Serial.print("Alcohol:");
  Serial.println(MQ6.MQ6DataAlcohol());
}

/*
  MQ6.valuea(88158); MQ6.valueb(-3.597); 
  float H2 = MQ6.readValue(); 
  
  MQ6.valuea(1009.2); MQ6.valueb(-2.35); 
  float LPG = MQ6.readValue(); 
  
  MQ6.valuea(2127.2); MQ6.valueb(-2.526);
  float CH4 = MQ6.readValue(); 
  
  MQ6.valuea(1000000000000000); MQ6.valueb(-13.5);
  float CO = MQ6.readValue();
  
  MQ6.valuea(50000000); MQ6.valueb(-6.017); 
  float Alcohol = MQ6.readValue(); 
 
  Serial.print("H2:");
  Serial.println(H2); 
  Serial.print("LPG:");
  Serial.println(LPG);
  Serial.print("CH4:");
  Serial.println(CH4);
  Serial.print("CO:");
  Serial.println(CO);
  Serial.print("Alcohol:");
  Serial.println(Alcohol);
  
  Serial.print("Total ppm:");
  Serial.println(MQ6.MQ6DataAir());
  Serial.print("Percentile%:");
  Serial.println(MQ6.MQData100());
*/
