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
#define space7            (A1)

MQSpaceData MQ7(ADC_BIT_RESU, Rload, space5);

void setup(){
Serial.begin(9600);
MQ7.begin();
MQ7.calibrateR0(0.98); // you can change it according to the value you find
//MQ7.MQ7calibrate();
}

void loop(){
	
  MQ7.valuea(69.014); MQ7.valueb(-1.374); 
  float H2 = MQ7.readValue(); 
  
  MQ7.valuea(700000000); MQ7.valueb(-7.703); 
  float LPG = MQ7.readValue(); 
  
  MQ7.valuea(60000000000000); MQ7.valueb(-10.54);
  float CH4 = MQ7.readValue(); 
  
  MQ7.valuea(99.042); MQ7.valueb(-1.518);
  float CO = MQ7.readValue();
  
  MQ7.valuea(40000000000000000); MQ7.valueb(-12.35); 
  float Alcohol = MQ7.readValue(); 
 
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
  
//Serial.print("Total ppm:");
//Serial.println(MQ7.MQ7DataAir());
//Serial.print("Percentile%:");
//Serial.println(MQ7.MQData100());
}

  /*
  Serial.print("H2:");
  Serial.println(MQ7.MQ7DataH2); 
  Serial.print("LPG:");
  Serial.println(MQ7.MQ7DataLPG);
  Serial.print("CH4:");
  Serial.println(MQ7.MQ7DataCH4);
  Serial.print("CO:");
  Serial.println(MQ7.MQ7DataCO);
  Serial.print("Alcohol:");
  Serial.println(MQ7.MQ7DataAlcohol);
  */