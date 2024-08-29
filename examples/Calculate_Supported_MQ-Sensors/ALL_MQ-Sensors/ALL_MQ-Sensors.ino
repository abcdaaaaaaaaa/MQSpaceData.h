#include <MQSpaceData.h>

#define ADC_BIT_RESU  (10) // for Arduino UNO 10 // for ESP32 12 // for ESP32-S2 13 // for ESP8266 10
#define ANALOG_PIN    (A1)
MQSpaceData MQ(ADC_BIT_RESU, ANALOG_PIN);

void setup() {
  Serial.begin(115200);  
  MQ.begin();
}

void loop() {
/*
If you install a new resistor in the soldered model or 
determine the specific resistor you installed in the gas sensor, 
specify how many kΩ it is using this function.
MQ.setRL(???);
The recommended load resistance for each gas sensor is determined in the datasheet. 
You can also determine the appropriate resistance by looking at the suggestedRL file.
*/
// Warning:
// If you are using a soldered gas sensor model, we recommend that you change the 1kΩ resistor to get more accurate results.
// If you do not have the opportunity to change the resistance of the soldered gas sensor model with the recommended resistor, 
// use the solderedRL() command instead of setRL(?? resistor (kΩ) ??), but keep in mind that the accuracy rate will decrease.

// configure your resistance kΩ
// recommended resistance according to datasheet (suggestedRL)

// Run the code by soldering the recommended resistors to the gas sensors of the option you want:
//MQ135();
//MQ2();
//MQ3();
//MQ4();
//MQ5();
//MQ6();
//MQ7();
//MQ8();
//MQ9();
//MQ131();
//MQ136();
//MQ137();
//MQ303A();
//MQ307A();
//MQ309A();
GasPercentileForAllMQs();
//delay(1500);
}

void MQ135(){
// Setup for MQ-135 calculation
MQ.RSRoMQAir(3.6);
// configure your resistance kΩ
// recommended resistance according to datasheet (suggestedRL)
MQ.setRL(20); // 20kΩ for MQ-135

MQ.dangerousPer(42.5); // set calibration percentage for CO
float CO = MQ.MQ135DataCO();

MQ.dangerousPer(25.55); // set calibration percentage for Alcohol
float Alcohol = MQ.MQ135DataAlcohol();

/* ""  "" ... */
MQ.dangerousPer(27.77);
float CO2 = MQ.MQ135DataCO2();

MQ.dangerousPer(21.944);
float Toluen = MQ.MQ135DataToluen();

MQ.dangerousPer(29.166);
float NH4 = MQ.MQ135DataNH4();

MQ.dangerousPer(20.55);
float Aceton = MQ.MQ135DataAceton();

// analog ppm value for MQ-135
// no calibration required
float Air = MQ.MQ135DataAir();
}

void MQ2(){
MQ.RSRoMQAir(9.8);
MQ.setRL(20);

MQ.dangerousPer(10.2); 
float H2 = MQ.MQ2DataH2();

MQ.dangerousPer(7.96);
float LPG = MQ.MQ2DataLPG();

MQ.dangerousPer(31.63);
float CO = MQ.MQ2DataCO();

MQ.dangerousPer(16.33);
float Alcohol = MQ.MQ2DataAlcohol();

MQ.dangerousPer(8.38);
float Propane = MQ.MQ2DataPropane();

MQ.dangerousPer(17.86);
float CH4 = MQ.MQ2DataCH4(); 

MQ.dangerousPer(18.98);
float Smoke = MQ.MQ2Datasmoke();

float Air = MQ.MQ2DataAir();
}

void MQ3(){
MQ.dangerousPer(48.97);
float LPG = MQ.MQ3DataLPG();

MQ.dangerousPer(74.69);
float CH4 = MQ.MQ3DataCH4();

MQ.dangerousPer(57);
float CO = MQ.MQ3DataCO();

MQ.dangerousPer(0.67);
float Alcohol = MQ.MQ3DataAlcohol();

MQ.dangerousPer(2.92);
float Benzene = MQ.MQ3DataBenzene();

MQ.dangerousPer(38);
float Hexane = MQ.MQ3DataHexane();

float Air = MQ.MQ3DataAir();
}

void MQ4(){
MQ.RSRoMQAir(4.4);
MQ.setRL(20);

MQ.dangerousPer(64.43);
float H2 = MQ.MQ4DataH2();

MQ.dangerousPer(34.32);
float LPG = MQ.MQ4DataLPG();

MQ.dangerousPer(22.73);
float CH4 = MQ.MQ4DataCH4();

MQ.dangerousPer(86.14);
float CO = MQ.MQ4DataCO();

MQ.dangerousPer(82.05);
float Alcohol = MQ.MQ4DataAlcohol();

MQ.dangerousPer(80.23);
float Smoke = MQ.MQ4DataSmoke();

float Air = MQ.MQ4DataAir(); 
}

void MQ5(){
MQ.RSRoMQAir(6.5);
MQ.setRL(20);

MQ.dangerousPer(15.12);
float H2 = MQ.MQ5DataH2();

MQ.dangerousPer(5.54);
float LPG = MQ.MQ5DataLPG();

MQ.dangerousPer(7.92);
float CH4 = MQ.MQ5DataCH4();

MQ.dangerousPer(44.15);
float CO = MQ.MQ5DataCO();

MQ.dangerousPer(39.38);
float Alcohol = MQ.MQ5DataAlcohol();

float Air = MQ.MQ5DataAir();
}

void MQ6(){
MQ.RSRoMQAir(10);
MQ.setRL(20);

MQ.dangerousPer(33.7);
float H2 = MQ.MQ6DataH2();

MQ.dangerousPer(10);
float LPG = MQ.MQ6DataLPG();

MQ.dangerousPer(13.5);
float CH4 = MQ.MQ6DataCH4();

MQ.dangerousPer(78);
float CO = MQ.MQ6DataCO();

MQ.dangerousPer(61.2);
float Alcohol = MQ.MQ6DataAlcohol();

float Air = MQ.MQ6DataAir();
}

void MQ7(){
MQ.RSRoMQAir(26);
MQ.setRL(10);

MQ.dangerousPer(3.08);
float H2 = MQ.MQ7DataH2();

MQ.dangerousPer(30.77);
float LPG = MQ.MQ7DataLPG();

MQ.dangerousPer(49.18);
float CH4 = MQ.MQ7DataCH4();

MQ.dangerousPer(3.85);
float CO = MQ.MQ7DataCO();

MQ.dangerousPer(57.69);
float Alcohol = MQ.MQ7DataAlcohol();

float Air = MQ.MQ7DataAir();
}

void MQ8(){
MQ.RSRoMQAir(70);
MQ.setRL(10);

MQ.dangerousPer(1.43);
float H2 = MQ.MQ8DataH2();

MQ.dangerousPer(27.53);
float LPG = MQ.MQ8DataLPG();

MQ.dangerousPer(63.47);
float CH4 = MQ.MQ8DataCH4();

MQ.dangerousPer(80.57);
float CO = MQ.MQ8DataCO();

MQ.dangerousPer(14.81);
float Alcohol = MQ.MQ8DataAlcohol();

float Air = MQ.MQ8DataAir();
}

void MQ9(){
MQ.RSRoMQAir(9.7);
MQ.setRL(20);

MQ.dangerousPer(10.31);
float LPG = MQ.MQ9DataLPG();

MQ.dangerousPer(18.04);
float CH4 = MQ.MQ9DataCH4();

MQ.dangerousPer(8);
float CO = MQ.MQ9DataCO();

float Air = MQ.MQ9DataAir();
}

void MQ131(){
MQ.RSRoMQAir(12);
MQ.setRL(100);

MQ.dangerousPer(23.75);
float NOx = 1 / MQ.MQ131DataNOx();

MQ.dangerousPer(8.33);
float CL2 = 1 / MQ.MQ131DataCL2();

MQ.dangerousPer(4.166);
float O3 = 1 / MQ.MQ131DataO3();

float Air = 1 / MQ.MQ131DataAir();
}


void MQ136(){
MQ.RSRoMQAir(3.54);
MQ.setRL(20);

MQ.dangerousPer(40.68);
float H2S = MQ.MQ136DataH2S();

MQ.dangerousPer(72);
float NH4 = MQ.MQ136DataNH4();

MQ.dangerousPer(81.64);
float CO = MQ.MQ136DataCO();

float Air = MQ.MQ136DataAir();
}

void MQ137(){
MQ.RSRoMQAir(3.54);
MQ.setRL(47);

MQ.dangerousPer(81.64);
float CO = MQ.MQ137DataCO();

MQ.dangerousPer(72);
float Ethanol = MQ.MQ137DataEthanol();

MQ.dangerousPer(40.68);
float NH3 = MQ.MQ137DataNH3();

float Air = MQ.MQ137DataAir();
}

void MQ303A(){
MQ.RSRoMQAir(1);
MQ.setRL(47);

MQ.dangerousPer(28);
float IsoButane = MQ.MQ303ADataIso();

MQ.dangerousPer(27);
float Hydrogen = MQ.MQ303ADataHyd();

MQ.dangerousPer(21);
float Ethanol = MQ.MQ303ADataEthanol();

float Air = MQ.MQ303ADataAir();
}

void MQ309A(){
MQ.setRL(50);
// MQ.RSRoMQAir(11);
 MQ.RSRoMQAir(1);

// MQ309A has two data graphs, 
// these values ​​are according to the 1st graph, 
// CH4 is high sensitivity in this graph

MQ.dangerousPer(11.4545);
float H2 = MQ.MQ309ADataH2();

MQ.dangerousPer(9.0909);
float CH4 = MQ.MQ309ADataCH4();

MQ.dangerousPer(54.5454); 
float CO = MQ.MQ309ADataCO();

MQ.dangerousPer(49.0909);
float Alcohol = MQ.MQ309ADataAlcohol();

float Air = MQ.MQ309ADataAir();

// MQ309A has two data graphs, 
// these values ​​are according to the 2nd graph,
// The second graph of MQ309A is the same as MQ307A
// CO is low sensitivity in this graph

/*
MQ.RSRoMQAir(1);

MQ.dangerousPer(0.96); 
float LOW_CO = MQ.MQ307ADataCO(); // Low Sensitivity

MQ.dangerousPer(56.107);
float Second_H2 = MQ.MQ307ADataH2(); // Low Sensitivity
 */
}

void MQ307A(){
MQ.setRL(50);
MQ.RSRoMQAir(1);

MQ.dangerousPer(0.96); 
float CO = MQ.MQ307ADataCO(); // Low Sensitivity

MQ.dangerousPer(56.107);
float H2 = MQ.MQ307ADataH2(); // Low Sensitivity
}

// Note: 
// You can access the a and b coefficients of these functions in the extras-unnecessary/gas_ab_values ​​file.
// This library does not perform the calibration process by finding the Ro value, 
// instead it develops percentiles that can be adapted to all RL values, 
// so the calibration process is carried out continuously from gas to gas, not from sensor to sensor.
// You can enter the values ​​of these percentages according to the data graph from the calibration_percentile (python) file via input 
// and process them to other gas sensors according to the results you get.
// If you still want to calculate the Ro value for other studies, 
// you can calculate the desired Ro value from the exstras-unnecessary/calibrateRo-python file.
// When calculating the Ro value, you can calculate your Ro value in the most accurate way by developing a general percentile 
// from the exstras-unnecessary/calibrateRo-arduino example, taking into account the sensor sensitivity, 
// necessary laboratory conditions and the STEL limits of the gases and the exstras-unnecessary/STEL_LIMIT_FOR_GASES file, 
// and then entering the necessary values ​​into the calibrateRo-python file.

void GasPercentileForAllMQs(){
// This function is the same in all gas sensors as it is determined directly according to the analog value, 
// as no calibration or special calculation is required for the percentile.
float percentile = MQ.MQData100();
}
