/*
this library is written for https://github.com/abcdaaaaaaaaa/Chernobyl project
by abcdaaaaaaaaa

ADC_BITB RESU value is 12 for esp32 models and 13 for esp32-s2 and 10 for esp8266 and
10 for arduino models (again, before defining) (check analog (not digital) adc bit resolution.)

*/

//!!!Definitely and definitely visit the information.ino file to see which sample you need!!!\\

#include <MQSpaceData.h>

// If you are not going to use the valuea(); and valueb(); and values, you do not need to calibrate.
// If you are not going to use the valuea(); and valueb(); values, it does not need to define the RLoad value
// Since this example only returns an analog value, it is compatible with all MQ sensors we will use,
// even all analog sensors you will install.

#define ADC_BIT_RESU      (10) // define your adc bit resulation
#define space             (A1) //define your analog pin 
static const int notimportant = random(1,11);

MQSpaceData MQX(ADC_BIT_RESU, notimportant, space);


void setup() {
  Serial.begin(9600); //Baud rate 
  MQX.begin();
}
 
void loop() {  
 float percentile = MQX.MQData100();
  Serial.print("percentile%0-100:");
  Serial.println(percentile);
}
