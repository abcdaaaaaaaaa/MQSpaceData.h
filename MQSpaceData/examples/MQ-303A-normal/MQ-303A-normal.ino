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
#define space303          (A1)

MQSpaceData MQ303(ADC_BIT_RESU, Rload, space303);

void setup(){
Serial.begin(9600);
MQ303.begin();
MQ303.calibrateR0(27); // you can change it according to the value you find
//MQ303.MQ303Acalibrate();
}

void loop(){
	
  MQ303.valuea(6.2144); MQ303.valueb(-2.894); 
  float Iso = MQ303.readValue(); 
  
  MQ303.valuea(4.1487); MQ303.valueb(-2.716);
  float Hyd = MQ303.readValue(); 
  
  MQ303.valuea(3.4916); MQ303.valueb(-2.432);
  float Ethanol = MQ303.readValue();

  Serial.print("Iso_butano:");
  Serial.println(Iso);
  Serial.print("Hydrogen:");
  Serial.println(Hyd);
  Serial.print("Ethanol:");
  Serial.println(Ethanol); 

//Serial.print("Total ppm:");
//Serial.println(MQ303.MQ303ADataAir());
//Serial.print("Percentile%:");
//Serial.println(MQ303.MQData100()); 	
}

/*
  Serial.print("Iso_butano:");
  Serial.println(MQ303.MQ303ADataIso());
  Serial.print("Hydrogen:");
  Serial.println(MQ303.MQ303ADataHyd());
  Serial.print("Ethanol:");
  Serial.println(MQ303.MQ303ADataEthanol()); 
 
  Serial.print("Total ppm:");
  Serial.println(MQ303.MQ303ADataAir());
  Serial.print("Percentile%:");
  Serial.println(MQ303.MQData100()); 
*/
