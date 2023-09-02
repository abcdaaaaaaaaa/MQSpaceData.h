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
#define space4            (A1)

MQSpaceData MQ4(ADC_BIT_RESU, Rload, space4);

void setup(){
Serial.begin(9600);
MQ4.begin();
//WARNING: [if you are not using 10k or 0k resistors, calibrate this value according to the calibratreR0 folder and calibrateR0(); Define your own value to the function]
MQ4.MQ4calibrate();
//MQ4.calibrateR0();
}
void loop(){ 
  Serial.print("LPG:");
  Serial.println(MQ4.MQ4DataLPG());
  Serial.print("CH4:");
  Serial.println(MQ4.MQ4DataCH4());
  Serial.print("CO:");
  Serial.println(MQ4.MQ4DataCO());
  Serial.print("Alcohol:");
  Serial.println(MQ4.MQ4DataAlcohol());
  Serial.print("Smoke:");
  Serial.println(MQ4.MQ4DataSmoke());	
  Serial.print("Total ppm:");
  Serial.println(MQ4.MQ4DataAir());
  Serial.print("Percentile%:");
  Serial.println(MQ4.MQData100());
}  
/*
  MQ4.valuea(3811.9); MQ4.valueb(-3.113); 
  float LPG = MQ4.readValue(); 
  
  MQ4.valuea(1012.7); MQ4.valueb(-2.786); 
  float CH4 = MQ4.readValue(); 
  
  MQ4.valuea(200000000000000); MQ4.valueb(-19.05);
  float CO = MQ4.readValue(); 
  
  MQ4.valuea(60000000000); MQ4.valueb(-14.01);
  float Alcohol = MQ4.readValue();
  
  MQ4.valuea(30000000); MQ4.valueb(-8.308); 
  float Smoke = MQ4.readValue(); 
  
  Serial.print("LPG:");
  Serial.println(LPG);
  Serial.print("CH4:");
  Serial.println(CH4);
  Serial.print("CO:");
  Serial.println(CO);
  Serial.print("Alcohol:");
  Serial.println(Alcohol);
  Serial.print("Smoke:");
  Serial.println(Smoke);
  
  Serial.print("Total ppm:");
  Serial.println(MQ4.MQ3DataAir());
  Serial.print("Percentile%:");
  Serial.println(MQ4.MQData100());
*/
