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
  MQ.valuea(17.6135); MQ.valueb(-0.4539); 
  float LPG = MQ.readValue();   

  MQ.dangerousPer(8.38);
  MQ.valuea(19.5575); MQ.valueb(-0.461); 
  float propane = MQ.readValue(); 

  MQ.dangerousPer(9.8);
  MQ.valuea(25.7473); MQ.valueb(-0.4731); 
  float H2 = MQ.readValue();   

  MQ.dangerousPer(16.33);
  MQ.valuea(19.2641); MQ.valueb(-0.3604); 
  float alcohol = MQ.readValue(); 

  MQ.dangerousPer(17.86);
  MQ.valuea(20.7074); MQ.valueb(-0.36); 
  float CH4 = MQ.readValue(); 

  MQ.dangerousPer(18.98);
  MQ.valuea(26.4698); MQ.valueb(-0.3876); 
  float smoke = MQ.readValue();   

  MQ.dangerousPer(31.63);
  MQ.valuea(28.024); MQ.valueb(-0.3182); 
  float CO = MQ.readValue(); 
  
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
Gas    | a       | b
LPG    | 17.6135 | -0.4539
propane| 19.5575 | -0.461 
H2     | 25.7473 | -0.4731
alcohol| 19.2641 | -0.3604
CH4    | 20.7074 | -0.36  
smoke  | 26.4698 | -0.3876
CO     | 28.024  | -0.3182
*/
