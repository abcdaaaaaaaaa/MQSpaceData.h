WARNING: To run the code, import the MQInfo.cpython-311.pyc file into the C:\Users\user\AppData\Local\Programs\Python\Python311\Lib\__pycache__\MQInfo.cpython-311.pyc path.

NOTE: This code is suitable for gas sensors measuring different model gases.

Sensor modes measuring different "Model Gases": MQ131_LOW, MQ303A, MQ303B, MQ307A, MQ309A

This code aims to predict future data based on past data. 
Please update the xlsx excel file to the sensor mode you are using and the past results you have obtained.
The data you need to measure for this code: Gas Sensor Percentage.

-- WARNING --
If you are using MQ131, make sure it measures with low sensitivity.
To understand the sensitivity of MQ131, look at its concentration range (if ppb --> low ModelSlope.py) (if ppm --> high 4DSlope.py).

If the sensor you are working with is not listed, please check the list of "Standart Gases".
