/*
You can find the simulation link here: 
https://wokwi.com/projects/400828974909121537
*/

#include <MQSpaceData.h>
#include <LiquidCrystal_I2C.h>

#define ADC_BIT_RESU  (10)
#define space         (A1)

#define pot analogRead(A0)

MQSpaceData MQ(ADC_BIT_RESU, space);

int lcdColumns = 16;
int lcdRows = 2;

int x, Air;
String xname, mode, strper;

LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows); 

void setup() {
  MQ.begin();
  lcd.init();
  lcd.backlight();
  /*
  WARNING:
  [When making this circuit in a real environment, 
  keep in mind that for the values ​​to work correctly, 
  you need to install a kΩ resistor as much as the suggested RL for each mode. 
  If you do not want to use a resistor, 
  use the MQ.solderedRL() command in the void setup() function
  and delete all commands that say MQ.setRL(number). 
  However, keep in mind that your accuracy rate will decrease for sensor values 
  because you do not use the suggested resistor.]
  // MQ.solderedRL() (Not suggested)
  */
}

void loop() {
  switch (map(pot, 0, (1 << ADC_BIT_RESU) - 1, 1, 14)) {
    case (1): MQ135(); break;
    case (2): MQ2(); break;
    case (3): MQ3(); break;
    case (4): MQ4(); break;
    case (5): MQ5(); break;
    case (6): MQ6(); break;
    case (7): MQ7(); break;
    case (8): MQ8(); break;
    case (9): MQ9(); break;
    case (10): MQ131(); break;
    case (11): MQ136(); break;
    case (12): MQ137(); break;
    case (13): MQ303A(); break;
    case (14): MQ307A(); break;
    case (15): MQ309A(); break;
  }
}

void hello() {
  lcd.setCursor(0, 0);
  lcd.print("Air:" + String(Air));
  lcd.setCursor(16 - mode.length(), 0);
  lcd.print(mode);
  lcd.setCursor(0, 1);
  lcd.print(xname + ":" + String(x));
  strper = String(int(MQ.MQData100()));
  lcd.setCursor(16 - strper.length() - 1, 1);
  lcd.print("%" + strper);
  delay(1500);
  lcd.clear();
}

void MQ135(){
  MQ.RSRoMQAir(3.6);
  MQ.setRL(20); 
  mode = "MQ-135";

  xname = "CO";
  MQ.dangerousPer(42.5); 
  x = MQ.MQ135DataCO();
  hello();

  xname = "Alcohol";
  MQ.dangerousPer(25.55); 
  x = MQ.MQ135DataAlcohol();
  hello();

  xname = "CO2";
  MQ.dangerousPer(27.77);
  x = MQ.MQ135DataCO2();
  hello();

  xname = "Toluen";
  MQ.dangerousPer(21.944);
  x = MQ.MQ135DataToluen();
  hello();

  xname = "NH4";
  MQ.dangerousPer(29.166);
  x = MQ.MQ135DataNH4();
  hello();

  xname = "Aceton";
  MQ.dangerousPer(20.55);
  x = MQ.MQ135DataAceton();
  hello();

  Air = MQ.MQ135DataAir();
}

void MQ2() {
  MQ.RSRoMQAir(9.8);
  MQ.setRL(20);
  mode = "MQ-2";

  xname = "H2";
  MQ.dangerousPer(10.2);
  x = MQ.MQ2DataH2();
  hello();

  xname = "LPG";
  MQ.dangerousPer(7.96);
  x = MQ.MQ2DataLPG();
  hello();

  xname = "CO";
  MQ.dangerousPer(31.63);
  x = MQ.MQ2DataCO();
  hello();

  xname = "Alcohol";
  MQ.dangerousPer(16.33);
  x = MQ.MQ2DataAlcohol();
  hello();

  xname = "Propane";
  MQ.dangerousPer(8.38);
  x = MQ.MQ2DataPropane();
  hello();

  xname = "CH4";
  MQ.dangerousPer(17.86);
  x = MQ.MQ2DataCH4();
  hello();

  xname = "Smoke";
  MQ.dangerousPer(18.98);
  x = MQ.MQ2Datasmoke();
  hello();

  Air = MQ.MQ2DataAir();
}

void MQ3() {
  MQ.RSRoMQAir(9.8);
  MQ.setRL(20);
  mode = "MQ-3";

  xname = "H2";
  MQ.dangerousPer(10.2);
  x = MQ.MQ2DataH2();
  hello();

  xname = "LPG";
  MQ.dangerousPer(7.96);
  x = MQ.MQ2DataLPG();
  hello();

  xname = "CO";
  MQ.dangerousPer(31.63);
  x = MQ.MQ2DataCO();
  hello();

  xname = "Alcohol";
  MQ.dangerousPer(16.33);
  x = MQ.MQ2DataAlcohol();
  hello();

  xname = "Propane";
  MQ.dangerousPer(8.38);
  x = MQ.MQ2DataPropane();
  hello();

  xname = "CH4";
  MQ.dangerousPer(17.86);
  x = MQ.MQ2DataCH4();
  hello();

  xname = "Smoke";
  MQ.dangerousPer(18.98);
  x = MQ.MQ2Datasmoke();
  hello();

  Air = MQ.MQ2DataAir();
}

void MQ4() {
  MQ.RSRoMQAir(4.4);
  MQ.setRL(20);
  mode = "MQ-4";

  xname = "H2";
  MQ.dangerousPer(64.43);
  x = MQ.MQ4DataH2();
  hello();

  xname = "LPG";
  MQ.dangerousPer(34.32);
  x = MQ.MQ4DataLPG();
  hello();

  xname = "CH4";
  MQ.dangerousPer(22.73);
  x = MQ.MQ4DataCH4();
  hello();

  xname = "CO";
  MQ.dangerousPer(86.14);
  x = MQ.MQ4DataCO();
  hello();

  xname = "Alcohol";
  MQ.dangerousPer(82.05);
  x = MQ.MQ4DataAlcohol();
  hello();

  xname = "Smoke";
  MQ.dangerousPer(80.23);
  x = MQ.MQ4DataSmoke();
  hello();

  Air = MQ.MQ4DataAir();
}

void MQ5() {
  MQ.RSRoMQAir(6.5);
  MQ.setRL(20);
  mode = "MQ-5";

  xname = "H2";
  MQ.dangerousPer(15.12);
  x = MQ.MQ5DataH2();
  hello();

  xname = "LPG";
  MQ.dangerousPer(5.54);
  x = MQ.MQ5DataLPG();
  hello();

  xname = "CH4";
  MQ.dangerousPer(7.92);
  x = MQ.MQ5DataCH4();
  hello();

  xname = "CO";
  MQ.dangerousPer(44.15);
  x = MQ.MQ5DataCO();
  hello();

  xname = "Alcohol";
  MQ.dangerousPer(39.38);
  x = MQ.MQ5DataAlcohol();
  hello();

  Air = MQ.MQ5DataAir();
}

void MQ6() {
  MQ.RSRoMQAir(10);
  MQ.setRL(20);
  mode = "MQ-6";

  xname = "H2";
  MQ.dangerousPer(33.7);
  x = MQ.MQ6DataH2();
  hello();

  xname = "LPG";
  MQ.dangerousPer(10);
  x = MQ.MQ6DataLPG();
  hello();

  xname = "CH4";
  MQ.dangerousPer(13.5);
  x = MQ.MQ6DataCH4();
  hello();

  xname = "CO";
  MQ.dangerousPer(78);
  x = MQ.MQ6DataCO();
  hello();

  xname = "Alcohol";
  MQ.dangerousPer(61.2);
  x = MQ.MQ6DataAlcohol();
  hello();

  Air = MQ.MQ6DataAir();
}

void MQ7() {
  MQ.RSRoMQAir(26);
  MQ.setRL(10);
  mode = "MQ-7";

  xname = "H2";
  MQ.dangerousPer(3.08);
  x = MQ.MQ7DataH2();
  hello();

  xname = "LPG";
  MQ.dangerousPer(30.77);
  x = MQ.MQ7DataLPG();
  hello();

  xname = "CH4";
  MQ.dangerousPer(49.18);
  x = MQ.MQ7DataCH4();
  hello();

  xname = "CO";
  MQ.dangerousPer(3.85);
  x = MQ.MQ7DataCO();
  hello();

  xname = "Alcohol";
  MQ.dangerousPer(57.69);
  x = MQ.MQ7DataAlcohol();
  hello();

  Air = MQ.MQ7DataAir();
}

void MQ8() {
  MQ.RSRoMQAir(70);
  MQ.setRL(10);
  mode = "MQ-8";

  xname = "H2";
  MQ.dangerousPer(1.43);
  x = MQ.MQ8DataH2();
  hello();

  xname = "LPG";
  MQ.dangerousPer(27.53);
  x = MQ.MQ8DataLPG();
  hello();

  xname = "CH4";
  MQ.dangerousPer(63.47);
  x = MQ.MQ8DataCH4();
  hello();

  xname = "CO";
  MQ.dangerousPer(80.57);
  x = MQ.MQ8DataCO();
  hello();

  xname = "Alcohol";
  MQ.dangerousPer(14.81);
  x = MQ.MQ8DataAlcohol();
  hello();

  Air = MQ.MQ8DataAir();
}

void MQ9() {
  MQ.RSRoMQAir(9.7);
  MQ.setRL(20);
  mode = "MQ-9";

  xname = "LPG";
  MQ.dangerousPer(10.31);
  x = MQ.MQ9DataLPG();
  hello();

  xname = "CH4";
  MQ.dangerousPer(18.04);
  x = MQ.MQ9DataCH4();
  hello();

  xname = "CO";
  MQ.dangerousPer(8);
  x = MQ.MQ9DataCO();
  hello();

  Air = MQ.MQ9DataAir();
}

void MQ131() {
  MQ.RSRoMQAir(12);
  MQ.setRL(100);
  mode = "MQ131";

  xname = "NOx";
  MQ.dangerousPer(23.75);
  x = MQ.MQ131DataNOx();
  hello();

  xname = "CL2";
  MQ.dangerousPer(8.33);
  x = MQ.MQ131DataCL2();
  hello();

  xname = "O3";
  MQ.dangerousPer(4.166);
  x = MQ.MQ131DataO3();
  hello();

  Air = MQ.MQ131DataAir();
}

void MQ136() {
  MQ.RSRoMQAir(3.54);
  MQ.setRL(20);
  mode = "MQ-136";

  xname = "H2S";
  MQ.dangerousPer(40.68);
  x = MQ.MQ136DataH2S();
  hello();

  xname = "NH4";
  MQ.dangerousPer(72);
  x = MQ.MQ136DataNH4();
  hello();

  xname = "CO";
  MQ.dangerousPer(81.64);
  x = MQ.MQ136DataCO();
  hello();

  Air = MQ.MQ136DataAir();
}

void MQ137() {
  MQ.RSRoMQAir(3.54);
  MQ.setRL(47);
  mode = "MQ-137";

  xname = "CO";
  MQ.dangerousPer(81.64);
  x = MQ.MQ137DataCO();
  hello();

  xname = "Ethanol";
  MQ.dangerousPer(72);
  x = MQ.MQ137DataEthanol();
  hello();

  xname = "NH3";
  MQ.dangerousPer(40.68);
  x = MQ.MQ137DataNH3();
  hello();

  Air = MQ.MQ137DataAir();
}

void MQ303A() {
  MQ.RSRoMQAir(1);
  MQ.setRL(47);
  mode = "MQ303A";

  xname = "IsoButane";
  MQ.dangerousPer(17);
  x = MQ.MQ303ADataIso();
  hello();

  xname = "Hydrogen";
  MQ.dangerousPer(13);
  x = MQ.MQ303ADataHyd();
  hello();

  xname = "Ethanol";
  MQ.dangerousPer(10);
  x = MQ.MQ303ADataEthanol();
  hello();

  Air = MQ.MQ303ADataAir();
}

void MQ309A() {
  mode = "MQ309A";
  MQ.setRL(50);
  MQ.RSRoMQAir(11);

// MQ309A has two data graphs, 
// these values ​​are according to the 1st graph, 
// CH4 is high sensitivity in this graph

  xname = "H2";
  MQ.dangerousPer(11.4545);
  x = MQ.MQ309ADataH2();
  hello();

  xname = "CH4";
  MQ.dangerousPer(9.0909);
  x = MQ.MQ309ADataCH4();
  hello();

  xname = "CO";
  MQ.dangerousPer(54.5454);
  x = MQ.MQ309ADataCO();
  hello();

  xname = "Alcohol";
  MQ.dangerousPer(49.0909);
  x = MQ.MQ309ADataAlcohol();
  hello();

  Air = MQ.MQ309ADataAir();

/*
// MQ309A has two data graphs, 
// these values ​​are according to the 2nd graph,
// The second graph of MQ309A is the same as MQ307A
// CO is low sensitivity in this graph  xname = "LOW_CO";

  MQ.RSRoMQAir(100);

  xname = "LOW_CO";
  MQ.dangerousPer(0.96);
  x = MQ.MQ307ADataCO();
  hello();

  xname = "SecondH2";
  MQ.dangerousPer(56.107);
  x = MQ.MQ307ADataH2();
  hello();
  */
}

void MQ307A(){
  mode = "MQ307A";
  MQ.setRL(50);
  MQ.RSRoMQAir(100);

  xname = "CO";
  MQ.dangerousPer(0.96);
  x = MQ.MQ307ADataCO();
  hello();

  xname = "H2";
  MQ.dangerousPer(56.107);
  x = MQ.MQ307ADataH2();
  hello();
}

// MQ-X: [PIN --> A1] [GND --> GND] [VCC --> 5V]
// Potentiometer: [PIN --> A0] [GND --> GND] [VCC --> 5V]
