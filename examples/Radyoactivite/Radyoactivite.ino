#include <MQSpaceData.h>

// define true to the values ​​you want to calculate as false you don't want.
// The values ​​you define as false will be 0 on the screen output.

#define uSvhr1      (true)
#define Avg1        (true)
#define CPM_Count1  (true)
#define LOG_PERIOD1 (30000) // enter your waiting period (30 second = 30000) 30 seconds is ideal
#define GeigerPin1  (2)

// Putting it on hold (30 seconds is recommended) will allow your sensor to measure more accurately.

GeigerCounterPin Radyoactivite(uSvhr1, Avg1, CPM_Count1, LOG_PERIOD1, GeigerPin1);
 
void setup(){
Serial.begin(9600);
Radyoactivite.begin();
}

void loop(){
Radyoactivite.radyoactivite();
delay(LOG_PERIOD1);
Serial.print("Usv/hr:");
Serial.println(Radyoactivite.usvhr); // uSvhr 
Serial.print("Avg:");
Serial.println(String(Radyoactivite.Avg) + "+/-" + String(Radyoactivite.sdCPM)); // Avg 
Serial.print("CPM Count:");
Serial.println(Radyoactivite.count);  // CPM_Count
}
