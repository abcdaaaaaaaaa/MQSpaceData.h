# MQSpaceData

## What awaits v4.0.0?

## 1) Advanced Data Science System for Regression Calculations
![MQ-135_gas_curves](https://github.com/user-attachments/assets/e8d6e1bf-6f61-40c8-9cc8-fd0cd7189c22)

## 2) Formulated Correction Coefficients depending on Temperature and Humidity
![MQ-135_correction_coefficient](https://github.com/user-attachments/assets/8783b3a5-7956-47f1-a61b-ae300041e047)

## 3) Comparison of theoretical "Ratio" measurements and practical "Sensor measurements" in 3D graphics
![MQ135_CO2_3D](https://github.com/user-attachments/assets/f743feef-5a3c-4ff5-beea-3368e3a48f41)

## 4) Slope Estimation in Time-Based 4D Space
![4D_Slope_Estimation)](https://github.com/user-attachments/assets/1b1b3841-46c5-4634-a141-e221a0b9033a)


## Sample Projects
| Place | Category | Project Name |
|----------|----------|----------|
| [1] | Getting Started | [Adjustable Air Quality Monitoring & Analysis Platform](https://projecthub.arduino.cc/abcda123/adjustable-air-quality-monitoring-analysis-platform-with-plug-unplug-system-8a0057) |

## Formulla 

1) ppm = a*ratio^b (a: valuea b: valueb)
2) ppm = 10^[(log10(ratio)-b)/m] (m: logm b: logb)

If R^2 equals 1 :

a*ratio^b = 10^[(log10(ratio)-b)/m]                                                                                                                                             
logm = valueb, logb = log10(valuea)

# 1]
![loghello)](https://github.com/user-attachments/assets/5b251bec-9677-421d-9101-ccb1e3ad4d2e)


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

## V = I x R
V = I x R -> VRL = [VC / (RS + RL)] x RL -> VRL = (VC x RL) / (RS + RL)

RS: -> VRL x (RS + RL) = VC x RL -> (VRL x RS) + (VRL x RL) = VC x RL -> (VRL x RS) = (VC x RL) - (VRL x RL)

RS = [(VC x RL) - (VRL x RL)] / VRL -> RS = [(VC x RL) / VRL] – RL

Rs = (voltage * Rload) / (voltage/2^n-1)) - (Rload)

analogRead(pin) / bitadc -> calibrationPercentile / 100

Rs = bitadc * Rload / analogRead(pin) - Rload -> calibrationRs = 100 * Rload / calibrationPercentile – Rload

Ro = calibrationRs / Air ||| ratio = Rs / Ro -> ratio = Rs / (calibrationRs / Air) -> ratio = Rs x Air / calibrationRs

Ratio = (bitadc * Rload / analogRead(pin) – Rload) * RsRoMQAir / (100 * Rload / calibrationPercentile – Rload) [Rs / Ro]

## Calculate Ratio
(1) if ratio = Rs / Ro: 

ratio = (bitadc * Rload / analogRead(pin) – Rload) * RsRoMQAir / (100 * Rload / calibrationPercentile – Rload) 

(2) if ratio = Rs / Rs: 

ratio = (bitadc * Rload / analogRead(pin) – Rload) / (100 * Rload / calibrationPercentile – Rload) [No RsRoMQAir]

(3) if ratio = Ro / Rs: 

ratio = (bitadc * Rload / analogRead(pin) – Rload) * RsRoMQAir / (100 * Rload / calibrationPercentile – Rload) 

But: slpoe = slope x -1

valueb() = valueb() * -1

logm() = logm() * -1

        float MQSpaceData::readValue()
        {
         if (_ratioMode == "Ro/Rs") _vb = _vb * -1;
         return pow(ratio(),_vb)*_va;
        }
        
        float MQSpaceData::logValue()
        {
         if (_ratioMode == "Ro/Rs") _mlog = _mlog * -1;
         return pow(10,((log10(ratio())-_blog)/_mlog));
        }

## Ratio for Sensors
STATUS 1: MQ-2, MQ-3, MQ-4, MQ-5, MQ-6, MQ-7, MQ-8, MQ-9, MQ-135, MQ-136, MQ-137 [Almost All & Standart]

STATUS 2: MQ303A, MQ307A, MQ309A [A models]

STATUS 3: MQ131 [MQ131 only]

## MQDataScience
"The first and only Arduino library where Geiger Counter and MQ Sensors combine with Data Science"

## 3D Surface Diagram for MQ-135 Gases
![MQ135_CO2_3D](https://github.com/user-attachments/assets/f743feef-5a3c-4ff5-beea-3368e3a48f41)

## 4D Slope Estimation
![4D_Slope_Estimation)](https://github.com/user-attachments/assets/1b1b3841-46c5-4634-a141-e221a0b9033a)

## MQ-135 NewCurve & MQ-135 OldCurve
![MQ-135_gas_curves](https://github.com/user-attachments/assets/dbd1d04b-51dc-499c-be32-ff976911b9d8)
## MQ-2 NewCurve & MQ-2 OldCurve
![MQ-2_gas_curves](https://github.com/user-attachments/assets/b9de3a96-4efa-4aa6-8d0f-9702a5c8a50d)
## MQ-3 NewCurve & MQ-3 OldCurve
![MQ-3_gas_curves](https://github.com/user-attachments/assets/cfaf6c93-3f95-425b-b3c9-57e131c534e0)
## MQ-4 NewCurve & MQ-4 OldCurve
![MQ-4_gas_curves](https://github.com/user-attachments/assets/4efb70ae-b686-4efc-ab29-341866704ed7)
## MQ-5 NewCurve & MQ-5 OldCurve
![MQ-5_gas_curves](https://github.com/user-attachments/assets/c6384a51-971d-4fd8-a7ba-2cbd937851c4)
## MQ-6 NewCurve & MQ-6 OldCurve
![MQ-6_gas_curves](https://github.com/user-attachments/assets/21f6ee26-5595-4649-993a-f67d3755b609)
## MQ-7 NewCurve & MQ-7 OldCurve
![MQ-7_gas_curves](https://github.com/user-attachments/assets/7c6ef35c-ea4d-47e5-9631-ef132026fe86)
## MQ-8 NewCurve & MQ-8 OldCurve
![MQ-8_gas_curves](https://github.com/user-attachments/assets/213661d3-20b2-4ead-9e76-42496034446b)
## MQ-9 NewCurve & MQ-9 OldCurve
![MQ-9_gas_curves](https://github.com/user-attachments/assets/4bb1f6e5-803d-4593-8152-96e587e65b0f)
## MQ131 NewCurve & MQ131 OldCurve
![MQ-131_gas_curves](https://github.com/user-attachments/assets/d63e0af9-f9a0-4a79-a89e-54e7660f1c86)
## MQ-136 NewCurve & MQ-136 OldCurve
![MQ-136_gas_curves](https://github.com/user-attachments/assets/8fe753d1-f88b-4183-8da6-396fb12f4c54)
## MQ-137 NewCurve & MQ-137 OldCurve
![MQ-137_gas_curves](https://github.com/user-attachments/assets/773455b0-cebe-4c3a-bc5e-9ae2b8813378)
## MQ303A NewCurve & MQ303A OldCurve
![MQ-303A_gas_curves](https://github.com/user-attachments/assets/2c6f128c-0995-4537-af7b-aedcbb1afd04)
## MQ307A NewCurve & MQ207A OldCurve
![MQ-307A_gas_curves](https://github.com/user-attachments/assets/74e1b4c7-7e32-4fa7-9f62-e93b8f17aa74)
## MQ309A NewCurve & MQ309A OldCurve
![MQ-309A_gas_curves](https://github.com/user-attachments/assets/d73a5e21-85e7-4671-bb7d-92a15aabd671)

NOTE: [For detailed explanation, You can also check out the github wiki page]
https://github.com/abcdaaaaaaaaa/MQSpaceData.h/wiki

# MQSpaceData MQ Sensor List
MQ Sensor List: [MQ-2, MQ-3, MQ-4, MQ-5, MQ-6, MQ-7, MQ-8, MQ-9, MQ131, MQ-135, MQ-136, MQ-137, MQ303A, MQ307A, MQ309A]
![MQSensorList](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/bbaf16d0-9646-4751-9307-2ad09320bd4c)

# MQSpaceData Geiger Counter
![GeigerCounter](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/27061f03-3224-4ccd-91d6-92396889c9fd)
## You can access the library's article <a href="https://www.spacepedia.info/MQDataScience">here
