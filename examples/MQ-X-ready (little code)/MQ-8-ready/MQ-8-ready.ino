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
#define space8            (A1)

MQSpaceData MQ8(ADC_BIT_RESU, Rload, space8);

void setup(){
Serial.begin(9600);
MQ8.begin();
MQ8.MQ8calibrate();
//MQ8.calibrateR0(0.386);
}

void loop(){
  Serial.print("H2:");
  Serial.println(MQ8.MQ8DataH2()); 
  Serial.print("LPG:");
  Serial.println(MQ8.MQ8DataLPG());
  Serial.print("CH4:");
  Serial.println(MQ8.MQ8DataCH4());
  Serial.print("CO:");
  Serial.println(MQ8.MQ8DataCO());
  Serial.print("Alcohol:");
  Serial.println(MQ8.MQ8DataAlcohol());
  Serial.print("Total ppm:");
  Serial.println(MQ8.MQ8DataAir());
  Serial.print("Percentile%:");
  Serial.println(MQ8.MQData100());
}

/*
	
  MQ8.valuea(976.97); MQ8.valueb(-0.688); 
  float H2 = MQ8.readValue(); 
  
  MQ8.valuea(10000000); MQ8.valueb(-3.12); 
  float LPG = MQ8.readValue(); 
  
  MQ8.valuea(80000000000000); MQ8.valueb(-6.666);
  float CH4 = MQ8.readValue(); 
  
  MQ8.valuea(2000000000000000000); MQ8.valueb(-8.074);
  float CO = MQ8.readValue();
  
  MQ8.valuea(76101); MQ8.valueb(-1.86); 
  float Alcohol = MQ8.readValue(); 
 
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
  Serial.println(MQ8.MQ8DataAir());
  Serial.print("Percentile%:");
  Serial.println(MQ8.MQData100());
*/
