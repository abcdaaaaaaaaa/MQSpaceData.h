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

MQSpaceData MQ5(ADC_BIT_RESU, Rload, space5);

void setup(){
Serial.begin(9600);
MQ5.begin();
MQ5.MQ5calibrate();
//MQ5.calibrateR0(4.16);
}

void loop(){
  Serial.print("H2:");
  Serial.println(MQ5.MQ5DataH2()); 
  Serial.print("LPG:");
  Serial.println(MQ5.MQ5DataLPG());
  Serial.print("CH4:");
  Serial.println(MQ5.MQ5DataCH4());
  Serial.print("CO:");
  Serial.println(MQ5.MQ5DataCO());
  Serial.print("Alcohol:");
  Serial.println(MQ5.MQ5DataAlcohol());	
  Serial.print("Total ppm:");
  Serial.println(MQ5.MQ5DataAir());
  Serial.print("Percentile%:");
  Serial.println(MQ5.MQData100());
}

/*
  MQ5.valuea(1163.8); MQ5.valueb(-3.874); 
  float H2 = MQ5.readValue(); 
  
  MQ5.valuea(80.897); MQ5.valueb(-2.431); 
  float LPG = MQ5.readValue(); 
  
  MQ5.valuea(177.65); MQ5.valueb(-2.56);
  float CH4 = MQ5.readValue(); 
  
  MQ5.valuea(491204); MQ5.valueb(-5.826);
  float CO = MQ5.readValue();
  
  MQ5.valuea(97124); MQ5.valueb(-4.918); 
  float Alcohol = MQ5.readValue(); 
 
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
  Serial.println(MQ5.MQ5DataAir());
  Serial.print("Percentile%:");
  Serial.println(MQ5.MQData100());
*/
