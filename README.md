# MQSpaceData

## What awaits v4.0.0?
![newplotMQ-135curves](https://github.com/user-attachments/assets/b2a34329-fcf4-48e7-9bcc-67f244939534)
![newplotMQ-135TH](https://github.com/user-attachments/assets/1921246c-c8a2-4a64-a9d8-ab923e564688)
![newplotMQ-135TH4)](https://github.com/user-attachments/assets/d4abe66d-4f5f-4180-97ae-a1b545c88619)

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
![loghello](https://github.com/user-attachments/assets/c3456754-2ad3-47f0-8336-92bb0804c4e9)


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

## RadioactivityDataScience
"The first and only Arduino library where Geiger Counter and MQ Sensors combine with Data Science"

## SpaceDataScience
"The first and only Arduino library where Geiger Counter and MQ Sensors combine with Data Science"


## 3D Surface Diagram for MQ-135 Gases
![1mq135acetone](https://github.com/user-attachments/assets/8ea439eb-74c0-4d34-8340-06ac2da46d0f)
![1mq135alcohol](https://github.com/user-attachments/assets/4035b1ca-d3e0-4684-b658-686220da2c96)
![1mq135co](https://github.com/user-attachments/assets/26d55964-ce85-4b85-a6e5-6c991a1126a2)
![1mq135co2](https://github.com/user-attachments/assets/9d43d33f-89e8-43e6-a935-e66f5aff9016)
![1mq135nh4](https://github.com/user-attachments/assets/aa840714-2f9c-4477-8592-13bff9bb8342)
![1mq135toluene](https://github.com/user-attachments/assets/aa8cb955-f280-48d9-8c4d-e7e302f57ce4)


## MQ-135 NewCurve & MQ-135 OldCurve
![MQ-135](https://github.com/user-attachments/assets/b2a34329-fcf4-48e7-9bcc-67f244939534)
## MQ-2 NewCurve & MQ-2 OldCurve
![MQ-2](https://github.com/user-attachments/assets/7ef90f38-c4a2-4a0a-a2ee-cb2249f18df6)
## MQ-3 NewCurve & MQ-3 OldCurve
![MQ-3](https://github.com/user-attachments/assets/15711519-18df-45b8-aa8b-a9d9352cc1b7)
## MQ-4 NewCurve & MQ-4 OldCurve
![MQ-4](https://github.com/user-attachments/assets/52c0d426-b0ce-4876-805f-a288e003bb5e)
## MQ-5 NewCurve & MQ-5 OldCurve
![MQ-5](https://github.com/user-attachments/assets/9aee2dd0-ddef-41d9-ab48-14f18d27bdb7)
## MQ-6 NewCurve & MQ-6 OldCurve
![MQ-6](https://github.com/user-attachments/assets/7bdfdb12-3c6d-4dca-8efc-2703059ae526)
## MQ-7 NewCurve & MQ-7 OldCurve
![MQ-7](https://github.com/user-attachments/assets/fd50c7ec-320c-4943-8a5a-e42f85954f85)
## MQ-8 NewCurve & MQ-8 OldCurve
![MQ-8](https://github.com/user-attachments/assets/40128658-09b9-4751-8661-0a959e16daa5)
## MQ-9 NewCurve & MQ-9 OldCurve
![MQ-9](https://github.com/user-attachments/assets/d7e483b4-eaaa-4431-9e15-78c40079cfee)
## MQ131 NewCurve & MQ131 OldCurve
![MQ-131](https://github.com/user-attachments/assets/0d968d23-30fb-4ec0-b107-4f81480914ec)
## MQ-136 NewCurve & MQ-136 OldCurve
![MQ-136](https://github.com/user-attachments/assets/43db850d-532c-467f-ab45-a4477dc1dd5e)
## MQ-137 NewCurve & MQ-137 OldCurve
![MQ-137](https://github.com/user-attachments/assets/1289e710-62b9-4788-add0-b8add85f04b8)
## MQ303A NewCurve & MQ303A OldCurve
![MQ-303A](https://github.com/user-attachments/assets/c9133c10-8a0e-4b98-a59e-f1b3ef25f99b)
## MQ307A NewCurve & MQ207A OldCurve
![MQ-307A](https://github.com/user-attachments/assets/f837736c-434e-47d5-be5a-24bf078402c1)
## MQ309A NewCurve & MQ309A OldCurve
![MQ-309A](https://github.com/user-attachments/assets/60e3a49e-5727-4dfd-94f4-38eb20fb30a5)

NOTE: [For detailed explanation, You can also check out the github wiki page]
https://github.com/abcdaaaaaaaaa/MQSpaceData.h/wiki

# MQSpaceData MQ Sensor List
MQ Sensor List: [MQ-2, MQ-3, MQ-4, MQ-5, MQ-6, MQ-7, MQ-8, MQ-9, MQ131, MQ-135, MQ-136, MQ-137, MQ303A, MQ307A, MQ309A]
![MQSensorList](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/bbaf16d0-9646-4751-9307-2ad09320bd4c)

# MQSpaceData Geiger Counter
![GeigerCounter](https://github.com/abcdaaaaaaaaa/MQSpaceData.h/assets/108553778/27061f03-3224-4ccd-91d6-92396889c9fd)
## You can access the library's article <a href="https://www.spacepedia.info/MQDataScience">here
