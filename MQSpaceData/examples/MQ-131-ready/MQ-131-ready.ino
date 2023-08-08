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
#define space131          (A1)

MQSpaceData MQ131(ADC_BIT_RESU, Rload, space131);

void setup(){
Serial.begin(9600);
MQ131.begin();
MQ131.MQ131calibrate();
//MQ131.calibrateR0(0.67);
}

void loop(){
  Serial.print("LPG:");
  Serial.println(MQ131.MQ131DataNOx);
  Serial.print("CH4:");
  Serial.println(MQ131.MQ131DataCL2());
  Serial.print("CO:");
  Serial.println(MQ131.MQ131DataO3());

  Serial.print("Total ppm:");
  Serial.println(MQ131.MQ131DataAir());
  Serial.print("Percentile%:");
  Serial.println(MQ131.MQData100());
}

/*
  MQ131.valuea(-462.43); MQ131.valueb(-2.204); 
  float NOx = MQ131.readValue(); 
  
  MQ131.valuea(47.209); MQ131.valueb(-1.186);
  float CL2 = MQ131.readValue(); 
  
  MQ131.valuea(23.943); MQ131.valueb(-1.11);
  float O3 = MQ131.readValue();

  Serial.print("NOx:");
  Serial.println(NOx);
  Serial.print("CL2:");
  Serial.println(CL2);
  Serial.print("O3:");
  Serial.println(O3); 

  Serial.print("Total ppm:");
  Serial.println(MQ131.MQ131DataAir());
  Serial.print("Percentile%:");
  Serial.println(MQ131.MQData100());  
*/
