# MQDataScience

## Formulla 
1) ppm = a*ratio^b (a: valuea b: valueb)
2) ppm = 10^[(log10(ratio)-b)/m] (m: logm b: logb)
 If r^2 equals 1 :
a*ratio^b = 10^[(log10(ratio)-b)/m]
logm = valueb, logb = log10(valuea)   
        if r_squared >= 0.9995:            
            x0, y0 = x[0], y[0]
            xn, yn = x[-1], y[-1]
            b = np.log10(yn/y0) / np.log10(xn/x0)
            a = 10**(np.log10(yn) - b * np.log10(xn))
            b2 = np.log10(yn) - b * np.log10(xn)
            b2_rounded = round(b2, 4)
            a_rounded = round(a, 4)
            b_rounded = round(b, 4)
"The first and only Arduino library where Geiger Counter and MQ Sensors combine with Data Science"
![MQ3datascience](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/49a65210-5921-4a4c-acce-3c3c476c2d21)
![MQ2curve](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/14de872a-3f70-4c8b-b96f-7b368e7a5ec9)
![MQ3curve](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/c33b986e-f253-4274-96a1-afeb6ab91d83)
![MQ4curve](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/590f4b79-e53b-4c9f-947c-b22d49a62d4d)
![MQ5curve](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/4c6dfc36-8bfd-438e-bbf8-a03c7be40f2f)
![MQ6curve](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/9eea767a-6f66-43f8-affd-6fac06999dd7)
![MQ7curve](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/0435c61f-4bd4-4168-aadd-84972247c151)
![MQ8curve](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/8c3cb2ac-765a-4d2a-9341-e5b1e2fbff23)
![MQ9curve](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/c7c34507-d8c1-4760-87ac-d5427cf690e5)
![MQ131curve](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/83dd8057-6c4f-4bbc-b696-a0b6a7b2f658)
![MQ135curve](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/01ab414a-f1c1-46b8-9e44-e180cf8f96f5)
![MQ136curve](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/b875eaeb-4bc8-4f10-871c-26ddbbbeab5e)
![MQ137curve](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/31181760-c6a3-4041-9bba-e5d701e3eea7)
![MQ303Acurve](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/0d6b8d22-e414-4076-81a6-60dd9905d889)
![MQ309Acurve](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/f2148e24-0a9d-412f-b523-449b008643fd)
![MQ309A-LOW-curve](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/90c042a2-5498-4770-9ec7-ec327b875f27)

NOTE: [For detailed explanation, You can also check out the github wiki page]
https://github.com/abcdaaaaaaaaa/MQSpaceData.h/wiki
## MQSpaceData Contents
* [MQ Sensor Datasheet](#MQSensorData)
* [Start with MQ-X](#MQ-X)
  * [Start with ALL](#StartAll)
  * [Supported MQ-X](#Supported)
  * [UnSupported MQ-X](#UnSupported)
* [Data-Science](#data)
  * [for MQ-Sensors](#for-MQ-Sensors)
  * [for Geiger Conter](#for-Geiger-Counter)
  * [for SpaceData %0-100](#for-SpaceData)
* [Sensor Electronics](#Sensor)
  * [for Arduino](#Arduino)
  * [for ESP32](#ESP-32)
  * [for ESP8266](#ESP8266)
  * [for ESP32-S2](#ESP32-S2)
  * [for ALL](#for_ALL)
* [Configure your RL value](#ConfigureRL)
  * [for Soldered Model](#for-soldered)
  * [for Normal Model](#for-normal)
* [Redefine Your Values](#Arduino)
  * [Regression (a and b)](#Regression)
  * [Regression (m and b)](#Regression)
  * [Calibrate Ro with python dangerousPer()](#R0python)
* [Calculate With Python](#Python)
  * [Redefine your value a and b with Regression](#Regression_a_and_b)
  * [Calibrate Ro with percentile](#R0python)
  * [Calculating the percentile of the dangerousPer() function](#dangerousPer)
* [Radioactivity For Geiger Counter](#Radioactivity)
# MQSpaceData MQ Sensor List
MQ Sensor List: [MQ-2, MQ-3, MQ-4, MQ-5, MQ-6, MQ-7, MQ-8, MQ-9, MQ-131, MQ-135, MQ-136, MQ303A , MQ309A]
![mqsensorlist1000](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/5864202a-d58a-4222-b760-0bacb5bf790a)
# MQSpaceData Geiger Counter
![download](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/27061f03-3224-4ccd-91d6-92396889c9fd)
## You can access the library's article <a href="https://www.spacepedia.info/MQDataScience">here
