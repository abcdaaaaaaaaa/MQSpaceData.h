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
#define space136          (A1)

MQSpaceData MQ136(ADC_BIT_RESU, Rload, space136);

void setup(){
Serial.begin(9600);
MQ136.begin();
MQ136.MQ136calibrate();
//MQ136.calibrateR0(7.5);
}

void loop(){
  Serial.print("H2S:");
  Serial.println(MQ136.MQ136DataH2S());
  Serial.print("NH4:");
  Serial.println(MQ136.MQ136DataNH4());
  Serial.print("CO:");
  Serial.println(MQ136.MQ136DataCO()); 
  Serial.print("Total ppm:");
  Serial.println(MQ136.MQ136DataAir());
  Serial.print("Percentile%:");
  Serial.println(MQ136.MQData100()); 	
}

/*
  MQ136.valuea(36.737); MQ136.valueb(-3.536); 
  float H2S = MQ136.readValue(); 
  
  MQ136.valuea(98.551); MQ136.valueb(-2.475);
  float NH4 = MQ136.readValue(); 
  
  MQ136.valuea(503.34); MQ136.valueb(-3.774);
  float CO = MQ136.readValue();

  Serial.print("H2S:");
  Serial.println(H2S);
  Serial.print("NH4:");
  Serial.println(NH4);
  Serial.print("CO:");
  Serial.println(CO); 

  Serial.print("Total ppm:");
  Serial.println(MQ136.MQ136DataAir());
  Serial.print("Percentile%:");
  Serial.println(MQ136.MQData100()); 
*/
