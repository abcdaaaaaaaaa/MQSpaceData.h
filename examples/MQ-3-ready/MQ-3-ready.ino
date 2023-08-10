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
#define space3            (A1)

MQSpaceData MQ3(ADC_BIT_RESU, Rload, space3);

void setup(){
Serial.begin(9600);
MQ3.begin();
MQ3.MQ3calibrate();
//MQ3.calibrateR0(0.45);
}

void loop(){
  Serial.print("LPG:");
  Serial.println(MQ3.MQ3DataLPG());
  Serial.print("CH4:");
  Serial.println(MQ3.MQ3DataCH4());
  Serial.print("CO:");
  Serial.println(MQ3.MQ3DataCO());
  Serial.print("Alcohol:");
  Serial.println(MQ3.MQ3DataAlcohol());
  Serial.print("Benzene:");
  Serial.println(MQ3.MQ3DataBenzene());	
  Serial.print("Hexane:");
  Serial.println(MQ3.MQ3DataHexane());	
  Serial.print("Total ppm:");
  Serial.println(MQ3.MQ3DataAir());
  Serial.print("Percentile%:");
  Serial.println(MQ3.MQData100());
}  
  /*
  MQ3.valuea(44771);  MQ3.valueb( -3.245);
  float LPG = MQ3.readValue();

  MQ3.valuea(2*10^31);  MQ3.valueb(19.01);
  float CH4 = MQ3.readValue();  
  
  MQ3.valuea(521853);  MQ3.valueb(-3.821);
  float CO = MQ3.readValue();  
  
  MQ3.valuea(0.3934);  MQ3.valueb(-1.504);
  float Alcohol = MQ3.readValue();  
  
  MQ3.valuea(4.8387);  MQ3.valueb(-2.68);
  float Benzene = MQ3.readValue(); 
  
  MQ3.valuea(7585.3);  MQ3.valueb(-2.849);
  float Hexane = MQ3.readValue();  

  Serial.print("LPG:");
  Serial.println(LPG);
  Serial.print("CH4:");
  Serial.println(CH4);
  Serial.print("CO:");
  Serial.println(CO);
  Serial.print("Alcohol:");
  Serial.println(Alcohol);
  Serial.print("Benzene:");
  Serial.println(Benzene);
  Serial.print("Hexane:");
  Serial.println(Hexane);
  
  Serial.print("Total ppm:");
  Serial.println(MQ3.MQ3DataAir());
  Serial.print("Percentile%:");
  Serial.println(MQ3.MQData100());
  */	
