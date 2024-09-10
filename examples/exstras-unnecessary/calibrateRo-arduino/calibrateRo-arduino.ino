/*
This value is calculated as a percentage in dangerousPer() 
so that this process occurs continuously from gas to gas 
and not from sensor to sensor. Preset percentiles also 
prevent the gas sensor from needing a new value each time 
based on different RL values. But you'll probably notice 
that this value is often calculated in other studies. 
Therefore, although this example does not mean anything 
for this library, it is presented as an addition for 
different studies.
 */

// WARNING: use it only for idea, and to get correct result leave the circuit open for 48 hours after uploading (heat it up) 
// and ensure the LAB environment (NOT RANDOM ROOM) in the datasheet correctly


// Then, you can calibrate for "other studies" (n) via Python with the help of percentile and calibration values
// This feature is FOR OTHER WORKS only.
// You can also perform virtual calibration via Python (calibrateRo-python) 
// by taking the percentile into account and reach a conclusion by looking at the differences here.

#include <MQSpaceData.h>

// These values ​​are shown as an example for MQ-2

#define ADC_BIT_RESU      (10) // for Arduino UNO 10 // for ESP32 12 // for ESP32-S2 13 // for ESP8266 10
#define space             (A1)

MQSpaceData MQ(ADC_BIT_RESU, space);

#define AverageRange      (500) // We recommend 500
#define Voltage           (5)   // for Arduino UNO 5V // for ESP32 3.3V // for ESP32-S2 3.3V  // for ESP8266 3.3V

float Percentile, AverageVoltage, LastVoltage, AverageRoValue, LastRoValue, AverageRsValue, LastRsValue;

void setup(){
Serial.begin(9600);
MQ.begin();  
MQ.solderedRL(); // 1kΩ for soldered model
/*
If you install a new resistor in the soldered model or 
determine the specific resistor you installed in the gas sensor, 
specify how many kΩ it is using this function.
MQ.setRL(???);
The recommended load resistance for each gas sensor is determined in the datasheet. 
*/
// If you are using a soldered gas sensor model, we recommend that you change the 1kΩ resistor to get more accurate results.
// If you do not have the opportunity to change the resistance of the soldered gas sensor model with the recommended resistor, 
// use the solderedRL() command instead of setRL(?? resistor (kΩ) ??), but keep in mind that the accuracy rate will decrease.

// configure your resistance kΩ
// recommended resistance according to datasheet (suggestedRL)
// for MQ-2 suggestedRL: 20kΩ MQ.setRL(20);

MQ.RSRoMQAir(9.8); // for MQ-2

MQ.setVoltage(Voltage);

/*
"""
---Air VALUE---
MQ-2: 9.8
MQ-3: 60.53
MQ-4: 4.4
MQ-5: 6.5
MQ-6: 10
MQ-7: 26
MQ-8: 70
MQ-9: 9.7
MQ131: 12
MQ-135: 3.6
MQ-136: 3.54
MQ-137: 3.54
MQ303A: 1 (Not Important)
MQ307A: No Air (Not Important)
MQ309A 11 (Not Important)
"""
 */
}

void loop(){
// Important:
// AverageRange: We (recommend 500)
// This value gives the average, for example, 
// if you define 500, measuring this value 500 times, 
// adding these 500 values ​​and then dividing by 500 
// will give you the arithmetic average of this value.

Percentile = MQ.MQData100();

MQ.setRange(AverageRange); // The average is taken as the value defined here MQ.setRange(500)
LastVoltage = MQ.readVoltage();
LastRoValue = MQ.calculateRo(); // for MQ-2 ratio = Ro/Rs, MQ-3, MQ-4, MQ-5 ... MQ131, MQ-135, MQ-136, MQ-137 || WARNING: only -> MQ131 ratio = Rs/Ro.
LastRsValue = MQ.calculateRs(); // for MQ303A, MQ307A, MQ309A Because in these sensors, we do not need the Ro value since the ratio = Rs/Rs.
MQ.setRange(1); // just to get the final result, we define this value as 1
// because here the value is defined as 1 since only the last value will be taken into account when getting the result.
AverageVoltage = MQ.readVoltage();
AverageRoValue = MQ.calculateRo();
AverageRsValue = MQ.calculateRo();
Serial.print("Percentile:");
Serial.println(Percentile);
Serial.print("AverageVoltage:");
Serial.println(AverageVoltage);
Serial.print("LastVoltage:");
Serial.println(LastVoltage);

// for MQ-2 ratio = Ro/Rs, MQ-3, MQ-4, MQ-5 ... MQ131, MQ-135, MQ-136, MQ-137
Serial.print("AverageRoValue:");
Serial.println(AverageRoValue);
Serial.print("LastRoValue:");
Serial.println(LastRoValue);

// for MQ303A, MQ307A, MQ309A [A models]
Serial.print("AverageRsValue:");
Serial.println(AverageRsValue);
Serial.print("LastRsValue:");
Serial.println(LastRsValue);
delay(3000);
}
