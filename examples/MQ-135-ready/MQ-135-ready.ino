/*
this library is written for https://github.com/abcdaaaaaaaaa/Chernobyl project
by abcdaaaaaaaaa

ADC_BITB RESU value is 12 for esp32 models and 13 for esp32-s2 and 10 for esp8266 and
10 for arduino models (again, before defining) (check analog (not digital) adc bit resolution.)

!!This value is defined for 10k resistor, change it if you use a different value (Rload)!!!
*/

//!!!Definitely and definitely visit the information.ino file to see which sample you need!!!\\

//NOTE: There is no difference between MQ?-ready and MQ?-normal. For those who want to define an external sensor,
//it is enriched with examples to give a better answer to the question of how to use it 
//(or for those who want to show off for using ready-made functions)

#include <MQSpaceData.h>

#define Rload             (10)
#define ADC_BIT_RESU      (10)
#define space135          (A1)

MQSpaceData MQ135(ADC_BIT_RESU, Rload, space135);

void setup(){
Serial.begin(9600);
MQ135.begin();
MQ135.MQ135calibrate();
//MQ135.calibrateR0(8.2809); 
}

void loop(){
  Serial.print("CO:");
  Serial.prinln(MQ135.MQ135DataCO()); 
  Serial.print("Alcohol:");
  Serial.println(MQ135.MQ135DataAlcohol());
  Serial.print("CO2:");
  Serial.println(MQ135.MQ135DataCO2());
  Serial.print("Toluen:");
  Serial.println(MQ135.MQ135DataToluen());
  Serial.print("NH4:");
  Serial.println(MQ135.MQ135DataNH4());
  Serial.print("Aceton:");
  Serial.println(MQ135.MQ135DataAceton());  
  Serial.print("Total ppm:");
  Serial.println(MQ135.MQ135DataAir());
  Serial.print("Percentile%:");
  Serial.println(MQ135.MQData100());
}

/*
  MQ135.valuea(605.18); MQ135.valueb(-3.937); 
  float CO = MQ135.readValue(); 
  
  MQ135.valuea(77.255); MQ135.valueb(-3.18); 
  float Alcohol = MQ135.readValue(); 

  MQ135.valuea(110.47); MQ135.valueb(-2.862); 
  float CO2 = MQ135.readValue(); 

  MQ135.valuea(44.947); MQ135.valueb(-3.445); 
  float Toluen = MQ135.readValue(); 
  
  MQ135.valuea(102.2 ); MQ135.valueb(-2.473); 
  float NH4 = MQ135.readValue(); 

  MQ135.valuea(34.668); MQ135.valueb(-3.369); 
  float Aceton = MQ135.readValue(); 
  
  Serial.print("CO:");
  Serial.println(CO); 
  Serial.print("Alcohol:");
  Serial.println(Alcohol);
  Serial.print("CO2:");
  Serial.println(CO2);
  Serial.print("Toluen:");
  Serial.println(Toluen);
  Serial.print("NH4:");
  Serial.println(NH4);
  Serial.print("Aceton:");
  Serial.println(Aceton);

  Serial.print("Total ppm:");
  Serial.println(MQ135.MQ135DataAir());
  Serial.print("Percentile%:");
  Serial.println(MQ135.MQData100());
*/
