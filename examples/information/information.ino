 !!! Try Radioactive.ino with (Geiger Counter) for any kind of Radioactive analysis (Usv/hr, sdCPM, Avg, CPM Count) !!!
 !!! Also Allows calculating a and b values ​​without using a sensor, calculating percent caliber (different method) with python language (try python example) !!!
---------------------------------------------------------------------------------------------------------
if you dont want to calibrate sensor try this functions:
Sensor Model: [MQ-2 , MQ-3 , MQ-4, MQ-5, MQ-6, MQ7, MQ-8 MQ-9, MQ-131, MQ-135, MQ-136, MQ-303A, MQ-309A]
WARNING: if you don't use this sensor model and you want to do calibrate you must refer calibrateR0-normal or calibrateR0-veryeasy (different method):
but if you use this sensor model and you don't want to calibrate you can use this functions:
(calibrateR0-ready , MQ?-ready)
MQ2calibrate();
MQ3calibrate();
MQ4calibrate();
MQ5calibrate();
MQ6calibrate();
MQ7calibrate();
MQ8calibrate();
MQ9calibrate();
MQ131calibrate();
MQ135calibrate();
MQ136calibrate();
MQ303Acalibrate();
MQ309Acalibrate();
but if you want to calibrate own:
like this code: calibrateR0(8.2809); 
calibrateR0(R0 value);
If you have a lab environment, look at the calibrateR0-normal.ino example 
(and you will get more accurate results by defining the percentage in the calibrateR0-veryeasy file 
after you know how many out of 100 it would read if it did analog reading) 
(because you can't get 100% results in the lab, you just have an idea about what you get. 
We recommend that you fix the percentage at a certain value and see a more precise value in the calibrateR0-veryeasy file)
but if you do not have the means to provide the necessary environment for the sensor you want to calibrate
(even if you have not received your sensor yet), remember that you can still calibrate it MUCH MORE (yes, much more precisely)!
Visit the calibrateR0-veryeasy.ino file and tell the library how many value (like 27) 
it would read out of 100 if you had a sensor, if you could provide the environment with an analog reading,
 and if you had your sensor, tell me how much you would define the resistance (If you had a sensor, 
 how many k resistors would you use? ) and calibrate it only with the serial port screen 
 without connecting the SENSOR with the simulated values ​​you said. you can learn how to do it!
----------------------------------------------------------------------------
if you dont want to calculate or write valuea and valueb you can use this functions:
Sensor Model: [MQ-2 , MQ-3 , MQ-4, MQ-5, MQ-6, MQ7, MQ-8 MQ-9, MQ-131, MQ-135, MQ-136, MQ-303A, MQ-309A]
WARNING: if you don't use this sensor model and you want to do set valuea and valueb you can calculate refer 
MQother-result or MQother-resulteasy.ino (different calibration) method like (calibrateR0veryeasy vs calibrateR0-normal)
 MQ2DataH2();
 MQ2DataLPG();
 MQ2DataCO();
 MQ2DataAlcohol();
 MQ2DataPropane();
 MQ3DataLPG();
 MQ3DataCH4();
 MQ3DataCO();
 MQ3DataAlcohol();
 MQ3DataBenzene();
 MQ3DataHexane();
 MQ4DataLPG();
 MQ4DataCH4();
 MQ4DataCO();
 MQ4DataAlcohol();
 MQ4DataSmoke();
 MQ5DataH2();
 MQ5DataLPG();
 MQ5DataCH4();
 MQ5DataCO();
 MQ5DataAlcohol();
 MQ6DataH2();
 MQ6DataLPG();
 MQ6DataCH4();
 MQ6DataCO();
 MQ6DataAlcohol();
 MQ7DataH2();
 MQ7DataLPG();
 MQ7DataCH4();
 MQ7DataCO();
 MQ7DataAlcohol();
 MQ8DataH2();
 MQ8DataLPG();
 MQ8DataCH4();
 MQ8DataCO();
 MQ8DataAlcohol();
 MQ9DataLPG();
 MQ9DataCH4();
 MQ9DataCO();
 MQ131DataNOx();
 MQ131DataCL2();
 MQ131DataO3();
 MQ135DataCO();
 MQ135DataAlcohol();
 MQ135DataCO2();
 MQ135DataToluen();
 MQ135DataNH4();
 MQ135DataAceton();
 MQ136DataH2S();
 MQ136DataNH4();
 MQ136DataCO();
 MQ303ADataIso();
 MQ303ADataHyd();
 MQ303ADataEthanol();
 MQ309ADataH2();
 MQ309ADataCH4();
 MQ309ADataCO();
 MQ309ADataAlcohol();
 -----------------------------------------
this function has been developed specifically for this library. 
this function assigns value between 0-100 and this way you can check the sensor's percentage, 
it doesn't have to be compatible with the list given in the sensorlist.
so a function has been written for all sensors and you can use it with all analog sensor!
(MQ-data-percentile.ino)
 MQData100();
 ------------------------------------------
 In these functions, it aims to reach the analog result directly rather than the estimated value you wrote and
 calibrated in the data and returns the value as the concentration (ppm range) of the sensors given in the list (example MQ135: 10-1000ppm), 
 but the disadvantage of these functions is that they return the sensor as a single value, not dividing them into groups. 
 they are kind of like the average of all data, and unlike other data, they work with 100% accuracy because there is no estimation.
(MQ-data-ppm-value.ino)

 MQ2DataAir();
 MQ3DataAir();
 MQ4DataAir();
 MQ5DataAir();
 MQ6DataAir();
 MQ7DataAir();
 MQ8DataAir();
 MQ9DataAir();
 MQ131DataAir();
 MQ135DataAir();
 MQ136DataAir();
 MQ303ADataAir();
 MQ309ADataAir();
 ------------------------------------------
however, if you do not use the sensors used in the sensor list, this library, unlike other libraries, 
both prepares an environment for you to calibrate and calculates a and b values ​​for you.
(find out how!) 
this library calculates the a and b values ​​for you only
when you define the concentration range of the gas sensor (x,x0,y,y0) with the graph slopes (MQother-result.ino) 
then, After calculating the a and b values ​​and taking note of your required calibration values (calibrateR0-normal or calibrateR0-veryeasy) , 
you can now define all the values ​​in the MQother-ready file!
WARNING: If you are using resistors with a value other than 0k or 10k, do not use this example, 
instead try the calirateR0-normal or calirateR0-veryeasy files and do not use our default values at all! not MQother-ready file
-------------------------------------------
Also Allows calculating a and b values ​​without using a sensor, calculating percent caliber (different method) with python language (try python example)
--------------------------------------------
[If you are using the gas sensors given in the list, 
you do not have to define the values ​​using the MQ?-ready examples. If you want to be cool the code you will write,
use MQ-X-normal.ino, but there is no difference (my advice use MQ-X-ready because it is very useful and little code) MQ-X-ready (little code) MQ-X-normal (show off code).
------------------------------------------
if you don't know how many bits to define the cards : 
You can also look at arduino (examples -> arduino --> ArduinoUNO.ino or ArduinoNano.ino or ArduinoMega.ino) 
or  esp (examples -> esp --> esp32.ino esp32-s2.ino esp8266.ino) examples
also you can learn adc bit resulation with python try (python -> learn-your-adc-bit-resulation.py)
------------------------------------------
this file is like a general helper see examples for more information!
