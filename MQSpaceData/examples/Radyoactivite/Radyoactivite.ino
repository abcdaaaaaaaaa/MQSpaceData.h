/*
this library is written for https://github.com/abcdaaaaaaaaa/Chernobyl project
by abcdaaaaaaaaa
*/
#include <MQSpaceData.h>

// define true to the values ​​you want to calculate as false you don't want.
// The values ​​you define as false will be 0 on the screen output.
#define uSvhr       (true)
#define Avg         (true)
#define CPM_Count   (true)
#define LOG_PERIOD1 (30000) // enter your waiting period (30 second = 30000) 30 seconds is ideal
#define GeigerPin1  (2)

//Putting it on hold (30 seconds is recommended) will allow your sensor to measure more accurately.

GeigerCounterPin Radyoactivite(uSvhr, Avg, CPM_Count, LOG_PERIOD1, GeigerPin1);
 
void setup(){
Serial.begin(9600);
Radyoactivite.begin();
}

void loop(){
Radyoactivite.radyoactivite();
Serial.print("Usv/hr:");
Serial.println(Radyoactivite.usvhr); // uSvhr 
Serial.print("Avg:");
Serial.println(String(Radyoactivite.Avg) + "+/-" + String(Radyoactivite.sdCPM)); // Avg 
Serial.print("CPM Count:");
Serial.println(Radyoactivite.count);  // CPM_Count
}