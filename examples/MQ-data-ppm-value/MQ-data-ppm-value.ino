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
static const int notimportant = random(1,11);

MQSpaceData MQX(ADC_BIT_RESU, notimportant, space);

void setup() {
  Serial.begin(9600); //Baud rate 
  MQX.begin();
}

void loop() {
  Serial.print("Analog MQ value:");
  switch(MQSensor){
   case 1:  // MQ-135
   {
	Serial.println(MQX.MQ135DataAir());
	break;
   }
   case 2:  // MQ-2
   {
	Serial.println(MQX.MQ2DataAir());
	break;
   }
   case 3:  // MQ-3
   {
	Serial.println(MQX.MQ3DataAir());
	break;
   }
   case 4:  // MQ-4
   {
	Serial.println(MQX.MQ4DataAir());
	break;
   }
   case 5:  // MQ-5
   {
	Serial.println(MQX.MQ5DataAir());
	break;
   }
   case 6:  // MQ-6
   {
	Serial.println(MQX.MQ6DataAir());
	break;
   }
   case 7:  // MQ-7
   {
	Serial.println(MQX.MQ7DataAir());
	break;
   }
   case 8:  // MQ-8
   {
	Serial.println(MQX.MQ8DataAir());
	break;
   }
   case 9:  // MQ-9
   {
	Serial.println(MQX.MQ9DataAir());
	break;
   }
   case 131:  // MQ-131
   {
	Serial.println(MQX.MQ131DataAir());
	break;
   }
   case 136:  // MQ-136
   {
	Serial.println(MQX.MQ136DataAir());
	break;
   }
   case 303:  // MQ303A
   {
	Serial.println(MQX.MQ303ADataAir());
	break;
   }
   case 309:  // MQ309A
   {
	Serial.println(MQX.MQ309ADataAir());
	break;
   }
  }	
}
