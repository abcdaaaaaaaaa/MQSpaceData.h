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
#define ADC_BIT_RESU      (10) // ARDUINO Mega, this value is 10
#define space135          (A1)

MQSpaceData MQ135(ADC_BIT_RESU, Rload, space135);

#define mycard "ArduinoMega" // ARDUINO Mega

//WARNING: it is not recommended to reference this example If you have learned the value of adc_bit_resu 
//we recommend that you define it in the MQ-X-ready (little code) or MQ-X-normal (cool code) files and 
//customize your own project with custom sensors 

void setup(){
Serial.begin(9600);
MQ135.calibrateR0(8.209); // you can change it according to the value you find
// MQ135.MQ135calibrate();
MQ135.begin();  
}

void loop(){
Serial.print("My Card:");
Serial.println(mycard);
Serial.print("Total ppm:");
Serial.println(MQ135.MQ135DataAir());
Serial.print("Percentile%:");
Serial.println(MQ135.MQData100());
}

/*
Serial.println("CO:");
Serial.print(MQ135.MQ135DataCO()); 
Serial.println("Alcohol:");
Serial.print(MQ135.MQ135DataAlcohol());
Serial.println("CO2:");
Serial.print(MQ135.MQ135DataCO2());
Serial.println("Toluen:");
Serial.print(MQ135.MQ135DataToluen());
Serial.println("NH4:");
Serial.print(MQ135.MQ135DataNH4());
Serial.println("Aceton:");
Serial.print(MQ135.MQ135DataAceton());
Serial.print("Total ppm:");
Serial.println(MQ135.MQ135DataAir());
Serial.print("Percentile%:");
Serial.println(MQ135.MQData100());
*/