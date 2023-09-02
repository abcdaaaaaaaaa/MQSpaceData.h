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
#define space309          (A1)

MQSpaceData MQ309(ADC_BIT_RESU, Rload, space309);

void setup(){
Serial.begin(9600);
MQ309.begin();
//WARNING: [if you are not using 10k or 0k resistors, calibrate this value according to the calibratreR0 folder and calibrateR0(); Define your own value to the function]
MQ309.MQ309Acalibrate();
//MQ309.calibrateR0(2.458);
}

void loop(){
  Serial.print("H2:");
  Serial.println(MQ309.MQ309ADataH2());
  Serial.print("CH4:");
  Serial.println(MQ309.MQ309ADataCH4());
  Serial.print("CO:");
  Serial.println(MQ309.MQ309ADataCO()); 
  Serial.print("Alcohol:");
  Serial.println(MQ309.MQ309ADataAlcohol()); 
  Serial.print("Total ppm:");
  Serial.println(MQ309.MQ309ADataAir());
  Serial.print("Percentile%:");
  Serial.println(MQ309.MQData100()); 	
}

/*
  MQ309.valuea(1532.9); MQ309.valueb(-1.951); 
  float H2 = MQ309.readValue(); 
  
  MQ309.valuea(980.24); MQ309.valueb(-1.68);
  float CH4 = MQ309.readValue(); 
  
  MQ309.valuea(1000000); MQ309.valueb(-4.01);
  float CO = MQ309.readValue();
  
  MQ309.valuea(473622); MQ309.valueb(-3.647);
  float Alcohol = MQ309.readValue();

  Serial.print("H2:");
  Serial.println(H2);
  Serial.print("CH4:");
  Serial.println(CH4);
  Serial.print("CO:");
  Serial.println(CO); 
  Serial.print("Alcohol:");
  Serial.println(Alcohol); 

  Serial.print("Total ppm:");
  Serial.println(MQ309.MQ309ADataAir());
  Serial.print("Percentile%:");
  Serial.println(MQ309.MQData100()); 	
*/
