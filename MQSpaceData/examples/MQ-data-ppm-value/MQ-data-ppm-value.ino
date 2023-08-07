/*
this library is written for https://github.com/abcdaaaaaaaaa/Chernobyl project
by abcdaaaaaaaaa

ADC_BITB RESU value is 12 for esp32 models and 13 for esp32-s2 and 10 for esp8266 and
10 for arduino models (again, before defining) (check analog (not digital) adc bit resolution.)
*/

//!!!Definitely and definitely visit the information.ino file to see which sample you need!!!\\

#include <MQSpaceData.h>

#define MQSensor (1) // define your value (like MQ-135)

// If you are not going to use the valuea(); and valueb(); and values, you do not need to calibrate.
// If you are not going to use the valuea(); and valueb(); values, it does not need to define the RLoad value
// in this example MQ sensors measure according to ppm range concentration does not support external MQs
// For external MQ go to MQother-result.ino file

#define ADC_BIT_RESU      (10) // define your adc bit resulation
#define space             (A1) //define your analog pin 

MQSpaceData MQ-X(ADC_BIT_RESU, (random[1,11]), space);


void setup() {
  Serial.begin(9600); //Baud rate 
  MQ-X.begin();
  	Serial.print("Analog MQ value:");
}

void loop() {
  switch(MQSensor){
   case 1:  // MQ-135
   {
	Serial.println(MQ-X.MQ135DataAir());
	break;
   }
   case 2:  // MQ-2
   {
	Serial.println(MQ-X.MQ2DataAir());
	break;
   }
   case 3:  // MQ-3
   {
	Serial.println(MQ-X.MQ3DataAir());
	break;
   }
   case 4:  // MQ-4
   {
	Serial.println(MQ-X.MQ4DataAir());
	break;
   }
   case 5:  // MQ-5
   {
	Serial.println(MQ-X.MQ5DataAir());
	break;
   }
   case 6:  // MQ-6
   {
	Serial.println(MQ-X.MQ6DataAir());
	break;
   }
   case 7:  // MQ-7
   {
	Serial.println(MQ-X.MQ7DataAir());
	break;
   }
   case 8:  // MQ-8
   {
	Serial.println(MQ-X.MQ8DataAir());
	break;
   }
   case 9:  // MQ-9
   {
	Serial.println(MQ-X.MQ9DataAir());
	break;
   }
   case 131:  // MQ-131
   {
	Serial.println(MQ-X.MQ131DataAir());
	break;
   }
   case 136:  // MQ-136
   {
	Serial.println(MQ-X.MQ136DataAir());
	break;
   }
   case 303:  // MQ-303A
   {
	Serial.println(MQ-X.MQ303ADataAir());
	break;
   }
   case 309:  // MQ-309A
   {
	Serial.println(MQ-X.MQ309ADataAir());
	break;
   }
  }	
}