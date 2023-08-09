![download](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/237c07c9-eb5d-4b5e-8a3a-f85b47d5a32a)
![download](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/9696bed8-0022-42e0-8e76-e7df86c82e2d)
![download](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/da908954-4551-41f3-8213-d2ebcb33f1e3)
![download](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/13ec7e02-8f95-499a-ab3b-d5d498678b1b)
![download](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/543dcd47-b0bc-4950-b2ac-32b7c042d148)
![download](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/3aefabcf-b839-4319-a751-2b1ae3831930)
![download](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/16c905a9-1b72-47a1-bcd3-21d06929a54b)
![download](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/23469cf2-4ba2-4558-9cce-b846f13bd868)
![download](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/b1160e80-ee63-4a92-bee5-a7ac20b60fcc)
![download](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/1cb9be4b-93da-4705-ba2f-40a492a21619)
![download](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/13ea44fa-d69d-4b76-be10-03befd6b5c60)
![download](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/b4d5e6bc-2454-4a21-a4be-ff8f10f83e1c)

Calibrating is now easy with the MQSpaceData library:
Without connecting the sensor to your card, just show the percentage you will calibrate and define the RS/R0 difference and we will calibrate for you without laboratory conditions.
```
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
```
We can also calculate the a and b values ​​for you:
just define the concentration range of your gas sensor and the slopes of the graph just like the MQ4:
![download](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/446fdd27-5f85-4b6f-8834-30b77a3e440c)
```
#include <MQSpaceData.h>

// like MQ-4:
#define y              (0.75)  // final reference point of the graph
#define y0             (2.6)   // first reference point of the graph
#define x              (10000) // max ppm concentrate
#define x0             (200)   // min ppm concentrate

float valueA, valueB;
result calculateMQresult(y, y0, x, x0);

void setup(){
Serial.begin(9600);

  valueA = calculateMQresult.resultA();
  valueB = calculateMQresult.resultB();
  Serial.print("Define Your R0 value!:");
  Serial.println(lastResult);
  Serial.print("valueA = ");
  Serial.println(valueA); 
  Serial.print("valueB = ");
  Serial.print(valueB);
}

void loop(){
  
}
```

![download](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/27061f03-3224-4ccd-91d6-92396889c9fd)

