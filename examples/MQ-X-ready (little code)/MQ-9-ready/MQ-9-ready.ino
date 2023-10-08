/*
this library is written for https://github.com/abcdaaaaaaaaa/Chernobyl project
by abcdaaaaaaaaa

ADC_BITB RESU value is 12 for esp32 models and 13 for esp32-s2 and 10 for esp8266 and
10 for arduino models (again, before defining) (check analog (not digital) adc bit resolution.)

!!This value is defined for 10k resistor, change it if you use a different value (Rload)!!!
*/

//!!!Definitely and definitely visit the information.ino file to see which sample you need!!!\\

#include <MQSpaceData.h>

#define Rload             (10) //Rload value for soldered models is 10
#define ADC_BIT_RESU      (10)
#define space9            (A1)

MQSpaceData MQ9(ADC_BIT_RESU, Rload, space9);

void setup(){
Serial.begin(9600);
MQ9.begin();
//WARNING: [if you are not using soldered MQ model, calibrate this value according to the calibratreR0 folder
//and calibrateR0(); Define your own value to the function]
MQ9.MQ9calibrate();
//MQ9.calibrateR0(2.816);
}

void loop(){
  Serial.print("LPG:");
  Serial.println(MQ9.MQ9DataLPG());
  Serial.print("CH4:");
  Serial.println(MQ9.MQ9DataCH4());
  Serial.print("CO:");
  Serial.println(MQ9.MQ9DataCO());
  Serial.print("Total ppm:");
  Serial.println(MQ9.MQ9DataAir());
  Serial.print("Percentile%:");
  Serial.println(MQ9.MQData100());
}

/*
  MQ9.valuea(1000.5); MQ9.valueb(-2.186); 
  float LPG = MQ9.readValue(); 
  
  MQ9.valuea(4269.6); MQ9.valueb(-2.648);
  float CH4 = MQ9.readValue(); 
  
  MQ9.valuea(599.65); MQ9.valueb(-2.244);
  float CO = MQ9.readValue();

  Serial.print("LPG:");
  Serial.println(LPG);
  Serial.print("CH4:");
  Serial.println(CH4);
  Serial.print("CO:");
  Serial.println(CO);  
*/
