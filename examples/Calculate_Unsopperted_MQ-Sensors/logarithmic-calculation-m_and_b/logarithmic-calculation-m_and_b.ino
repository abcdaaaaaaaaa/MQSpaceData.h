#include <MQSpaceData.h>

// WARNING:
// There is no difference between the formulas m and b and a and b.
// Both formulas will give the same result.
// To be usable for both alternatives, this library is presneted 
// Always: logm = valueb, logb = log10(valuea) 
// We recommend using the formula with coefficients a and b

// These values ​​are shown as an example for MQ-2


#define ADC_BIT_RESU      (10) // for Arduino UNO 10 // for ESP32 12 // for ESP32-S2 13 // for ESP8266 10
#define space             (A1)

MQSpaceData MQ(ADC_BIT_RESU, space);

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
/*
"""
---RS/Ro VALUE---
MQ-2: 9.8
MQ-3: 60.53
MQ-4: 4.4
MQ-5: 6.5
MQ-6: 10
MQ-7: 26
MQ-8: 70
MQ-9: 9.7
MQ-131: 12
MQ-135: 3.6
MQ-136: 3.54
MQ-137: 3.54
MQ-303A: 1
MQ-309A: 11
"""
 */
}

void loop(){
  MQ.dangerousPer(7.96);
  MQ.logm(-0.4539); MQ.logb(1.2458); 
  float LPG = MQ.logValue();   

  MQ.dangerousPer(8.38);
  MQ.logm(-0.461); MQ.logb(1.2913); 
  float propane = MQ.logValue(); 

  MQ.dangerousPer(9.8);
  MQ.logm(-0.4731); MQ.logb(1.4107); 
  float H2 = MQ.logValue();   

  MQ.dangerousPer(16.33);
  MQ.logm(-0.3604); MQ.logb(1.2847); 
  float alcohol = MQ.logValue(); 

  MQ.dangerousPer(17.86);
  MQ.logm(-0.36); MQ.logb(1.3161); 
  float CH4 = MQ.logValue(); 

  MQ.dangerousPer(18.98);
  MQ.logm(-0.3876); MQ.logb(1.4228); 
  float smoke = MQ.logValue();   

  MQ.dangerousPer(31.63);
  MQ.logm(-0.3182); MQ.logb(1.4475); 
  float CO = MQ.logValue(); 
  
Serial.print("LPG:");
Serial.println(LPG); 
Serial.print("propane:");
Serial.println(propane);
Serial.print("H2:");
Serial.println(H2);
Serial.print("alcohol:");
Serial.println(alcohol);
Serial.print("CH4:");
Serial.println(CH4);
Serial.print("smoke:");
Serial.println(smoke);
Serial.print("CO:");
Serial.println(CO);
delay(1500);
}

/*
MQ-2
Gas    | m       | b
LPG    | -0.4539 | 1.2458 
propane| -0.461  | 1.2913 
H2     | -0.4731 | 1.4107 
alcohol| -0.3604 | 1.2847 
CH4    | -0.36   | 1.3161 
smoke  | -0.3876 | 1.4228 
CO     | -0.3182 | 1.4475 
*/
