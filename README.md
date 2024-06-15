# MQSpaceData

## Formulla 

1) ppm = a*ratio^b (a: valuea b: valueb)
2) ppm = 10^[(log10(ratio)-b)/m] (m: logm b: logb)

If R^2 equals 1 :

a*ratio^b = 10^[(log10(ratio)-b)/m]                                                                                                                                             
logm = valueb, logb = log10(valuea)

# 1]

![loghello](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/76cb0263-3cbf-4c50-a446-616039d5fbba)

[(1,10), (2,4), (3,3)]

loge(b) = ln(b) 

(ln(1),ln(10)) for ≈ (0,2.3026) 

(ln(2),ln(4)) ≈ (0.6931,1.3863) and 

(ln(3),ln(3)) ≈ (1.0986,1.0986) 

b = ∑ i=1 n (x i − x ˉ ) 2 ∑ i=1 n (xi − xˉ)(yi−yˉ) 

ln(x):(0,0.6931,1.0986)ln(y):(2.3026,1.3863,1.0986)ln(y)ˉ=(2.3026+1.3863+1.0986)/3≈1.5958

ln(x)ˉ=(0+0.6931+1.0986)/3≈0.5972

b = (0−0.5972)(2.3026−1.5958)+(0.6931−0.5972)(1.3863−1.5958)+(1.0986−0.5972)(1.0986−1.5958)/(0−0.5972)^2+(0.6931−0.5972)^2+(1.0986−0.5972)^2 ≈ -1.2


ln(a) = − ln ˉ (y) - b ln ˉ (x) ≈ 1.5958−(−1.2)⋅0.5972≈2.31244

a=e^2.31244 ≈ 9.947

# b  ≈ -1.2

# a ≈ 9.947

# 2]

y = mx+ n                                                                                                                                                                       
n = b                                                                                                                                                                                                                                                                                                                                 
log10(y) = m*log10(x) + b

-b = m*log10(x) - log10(y)

last b = log10(y) - m*log10(x)

m = (y - y0) / (x - x0)

m = (log10(y) - log10(y0)) / (log10(x) - log10(x0))

if y= a*x^b:

last m = log10(y/y0) / log10(x/x0)

m = slope of the line

b = intersection point

m = log10(y/y0) / log10(x/x0)

b = log10(y) - m*log10(x)

        if r_squared >= 0.9995:
            print("R-squared value for {gas name} is above 0.9995, plotting against first and last values.")
            
            x0, y0 = x[0], y[0]
            xn, yn = x[-1], y[-1]
            b = np.log10(yn/y0) / np.log10(xn/x0)
            a = 10**(np.log10(yn) - b * np.log10(xn))
            b2 = np.log10(yn) - b * np.log10(xn)
            b2_rounded = round(b2, 4)
            a_rounded = round(a, 4)
            b_rounded = round(b, 4)

The first formula is determined according to all points (OldCurve.py, OldCurve), while the second formula is determined according to the first and last point. Therefore, in order to collect them all in the same formula and to increase the accuracy rate, we used the method in the second formula and took the logarithm (if R^2 = 1 (%100) always: logm = valueb, logb = log10(valuea)) for slopes greater than 99.95% and collected them all in the first formula, thus we increased the accuracy rate without having to use 2 different formulas (Regression.py, NewCurve).

## MQDataScience
"The first and only Arduino library where Geiger Counter and MQ Sensors combine with Data Science"
![MQ3datascience](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/49a65210-5921-4a4c-acce-3c3c476c2d21)

## MQ-2
### NewCurve:
![MQ2curve](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/14de872a-3f70-4c8b-b96f-7b368e7a5ec9)
### OldCurve:
![MQ2curve](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/a427bd97-08cf-42d1-9d62-03c4d546369c)
### DataScience:
![MQ2Science](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/63bb0837-d85f-437f-b34b-dcf3c8051a09)
## MQ-3
### NewCurve:
![MQ3curve](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/c33b986e-f253-4274-96a1-afeb6ab91d83)
### OldCurve:
![MQ3curve](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/d33aac86-89d1-4f50-bb71-c080acd13011)
### DataScience:
![MQ3Science](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/c9cf3792-ec7b-48a5-9114-be9a31fc04db)
## MQ-4
### NewCurve:
![MQ4curve](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/590f4b79-e53b-4c9f-947c-b22d49a62d4d)
### OldCurve:
![MQ4curve](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/26d9234d-e11f-4250-b194-2cd024c68258)
### DataScience:
![MQ4Science](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/4cd4536f-9e8c-4451-96e4-0b34bc7a9230)
## MQ-5
### NewCurve:
![MQ5curve](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/4c6dfc36-8bfd-438e-bbf8-a03c7be40f2f)
### OldCurve:
![MQ5curve](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/5cb6f4f4-2d24-4e10-be19-849f186f0332)
### DataScience:
![MQ5Science](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/f684c037-880d-4a40-8883-a6268b9b3829)
## MQ-6
### NewCurve:
![MQ6curve](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/9eea767a-6f66-43f8-affd-6fac06999dd7)
### OldCurve:
![MQ6curve](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/ede333c9-5132-46c9-830b-5e904eb06759)
### DataScience:
![MQ6Science](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/afb8ff0c-83b7-46ac-8b20-2505b7a706cb)
## MQ-7
### NewCurve:
![MQ7curve](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/0435c61f-4bd4-4168-aadd-84972247c151)
### OldCurve:
![MQ7curve](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/0c6e93d0-5f60-4964-ad06-2308c65be39c)
### DataScience:
![MQ7Science](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/9c03ba5c-1b1f-4246-b56b-57d3c5b1902c)
## MQ-8
### NewCurve:
![MQ8curve](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/8c3cb2ac-765a-4d2a-9341-e5b1e2fbff23)
### OldCurve:
![MQ8curve](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/bc9e2299-dd0f-472b-aea3-288d3ce11f46)
### DataScience:
![MQ8Science](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/4eb7ca67-6a9b-493f-bf71-749cf5ded362)
## MQ-9
### NewCurve:
![MQ9curve](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/c7c34507-d8c1-4760-87ac-d5427cf690e5)
### OldCurve:
![MQ9curve](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/f9d41512-c13d-4952-b7bd-8367d613476c)
### DataScience:
![MQ9Science](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/7207e899-2755-4789-a294-a4e20774962f)
## MQ131
### NewCurve:
![MQ131curve](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/83dd8057-6c4f-4bbc-b696-a0b6a7b2f658)
### OldCurve:
![MQ131curve](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/7e87e4be-b43a-410d-827a-4942f822cb32)
### DataScience:
![MQ131Science](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/cfdbcdea-6dde-4dd6-9244-a1fea7544327)
## MQ-135
### NewCurve:
![MQ135curve](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/01ab414a-f1c1-46b8-9e44-e180cf8f96f5)
### OldCurve:
![MQ135curve](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/d4c4b505-4750-47db-b0a9-ec1d211c7296)
### DataScience:
![MQ135Science](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/c41773f3-3567-41f1-a94e-1f70bb029fb6)
## MQ-136
### NewCurve:
![MQ136curve](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/b875eaeb-4bc8-4f10-871c-26ddbbbeab5e)
### OldCurve:
![MQ136curve](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/e9e1516f-27e9-43dd-9d68-02deda75deeb)
### DataScience:
![MQ136Science](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/244d4a98-541a-4c4e-818c-3154e54dedb8)
## MQ-137
### NewCurve:
![MQ137curve](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/31181760-c6a3-4041-9bba-e5d701e3eea7)
### OldCurve:
![MQ137curve](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/795298b2-792d-4906-af2e-25bfffacb3f6)
### DataScience:
![MQ137Science](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/0de65a24-85fb-43c2-847d-bd1c35098af0)
## MQ303A
### NewCurve:
![MQ303Acurve](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/0d6b8d22-e414-4076-81a6-60dd9905d889)
### OldCurve:
![MQ303Acurve](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/55e4f706-e9b7-478c-a253-2ae7b0e3b107)
### DataScience:
![MQ303AScience](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/9ea3893d-f9cd-4e58-80e6-eb79daa8a635)

## MQ309A HIGH SENSIVITY FOR CH4
### NewCurve:
![MQ309Acurve](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/f2148e24-0a9d-412f-b523-449b008643fd)
### OldCurve:
![MQ309Acurve](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/6758cd50-fb59-4500-9358-98c7f502d9fd)
## MQ-309A LOW SENSIVITY FOR CO
### NewCurve:
![MQ309A-LOW-curve](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/90c042a2-5498-4770-9ec7-ec327b875f27)
### OldCurve:
![MQ309A-LOW-curve](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/c7ea730d-b4d7-40af-bd94-2a5dbb2fd835)
## DataScience for MQ309A
### DataScience:
![MQ309AScience](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/b90a7427-7779-4ae4-ae2c-a44fcb82070c)

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
MQ Sensor List: [MQ-2, MQ-3, MQ-4, MQ-5, MQ-6, MQ-7, MQ-8, MQ-9, MQ131, MQ-135, MQ-136, MQ-137, MQ303A , MQ309A]
![MQSensorList](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/4fbb9ab5-21a6-46fe-bf88-a904105a2634)
# MQSpaceData Geiger Counter
![download](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/27061f03-3224-4ccd-91d6-92396889c9fd)
## You can access the library's article <a href="https://www.spacepedia.info/MQDataScience">here
