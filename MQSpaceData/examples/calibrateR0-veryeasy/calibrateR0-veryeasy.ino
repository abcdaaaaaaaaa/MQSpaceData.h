/*
this library is written for https://github.com/abcdaaaaaaaaa/Chernobyl project
by abcdaaaaaaaaa

!!!This value is defined for 10k resistor, change it if you use a different value (Rload)!!!
*/

//!!!Definitely and definitely visit the information.ino file to see which sample you need!!!\\

//Calibrate your sensor very quickly and precisely WİTHOUT connecting the sensor 
//(remember, you can never provide 100% environment in a laboratory environment)
//Just tell us how many k resistors you would have connected if you had your sensor with you,
//and if you could meet the necessary conditions, how many value (like 27%) would you want 
//if your sensor were analog reading  0-100 in those. 
//and you would get the most accurate result with just the serial port screen (without using any sensor)!

#include <MQSpaceData.h>

#define RSR0MQAir (4.4) // RS / R0 you should look straight line (Air value) (graphic)
/*
---RS/R0 VALUE---
MQ-2: 9.83
MQ-3: 60
MQ-4: 4.4
MQ-5: 6.5
MQ-6: 10
MQ-7: 27.5
MQ-8: 70
MQ-9: 9.6
MQ-131: 15
MQ-135: 3.6
MQ-136: 3.6
MQ-303A: 1
MQ-309A: 11
*/
#define Rload             (10) // Rload

calibrateR0VeryEasy easy(RSR0MQAir,Rload);
float mypercentile = 27; // define your percentile

void setup(){
Serial.begin(9600);
float R0value = easy.calculateR0VeryEasy(mypercentile);
Serial.print("calibrating..");
Serial.println();
Serial.print("Your R0 value is:");
Serial.println(R0value);
}

void loop(){
  
}
