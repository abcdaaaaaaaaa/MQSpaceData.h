#include "MQSpaceData.h"
#include "Arduino.h"

MQSpaceData::MQSpaceData(int bitadc, byte pin)
{
  _bitadc = pow(2,bitadc)-1;
  _pin = pin;
}

void MQSpaceData::begin()
{
 pinMode(_pin,INPUT);
}

void MQSpaceData::setRL(float Rload)
{
 _Rload = Rload;
}

void MQSpaceData::solderedRL()
{
 _Rload = 1;
}

void MQSpaceData::valuea(float data1)
{
 _va = data1;
}

void MQSpaceData::valueb(float data2)
{
 _vb = data2;
}

void MQSpaceData::logm(float data1)
{
 _mlog = data1;
}

void MQSpaceData::logb(float data2)
{
 _blog = data2;
}

void MQSpaceData::RSRoMQAir(float RSRo)
{
 _RSRo = RSRo;
}

void MQSpaceData::dangerousPer(float per)
{
 _percentile = per;
}

void MQSpaceData::setVoltage(float voltage)
{
 _voltage = voltage;
}

void MQSpaceData::setRange(int range)
{
 _range = range;
}

int MQSpaceData::read()
{
 return analogRead(_pin);
}

float MQSpaceData::readVoltage()
{
 float sensorValue = 0;
 for(int x = 0; x < _range; x++)(sensorValue = sensorValue + read());
 sensorValue = sensorValue / _range;
 _setvoltage = sensorValue*(_voltage/_bitadc);
 return _setvoltage;
}

float MQSpaceData::calculateRo()
{
 _RS = _voltage * _Rload / readVoltage() - _Rload;
 _Ro = _RS / _RSRo;
 return _Ro;
}

float MQSpaceData::readValue()
{
 _ratio = (_Rload*_bitadc/read()-_Rload)/(_Rload*100/_percentile-_Rload)*_RSRo;
 return pow(_ratio,_vb)*_va;
}

float MQSpaceData::logValue()
{
 _ratio = (_Rload*_bitadc/read()-_Rload)/(_Rload*100/_percentile-_Rload)*_RSRo;
 return pow(10,((log10(_ratio)-_blog)/_mlog));
}

//**************************************ppm Values**************************************

int MQSpaceData::MQData100(){return map(read(),0,(_bitadc),0,100);}
int MQSpaceData::MQ2DataAir(){return map(read(),1,(_bitadc),200,10000);}
int MQSpaceData::MQ3DataAir(){return map(read(),1,(_bitadc),25,500);}
int MQSpaceData::MQ4DataAir(){return map(read(),1,(_bitadc),200,10000);}
int MQSpaceData::MQ5DataAir(){return map(read(),1,(_bitadc),200,10000);}
int MQSpaceData::MQ6DataAir(){return map(read(),1,(_bitadc),300,10000);}
int MQSpaceData::MQ7DataAir(){return map(read(),1,(_bitadc),50,4000);}
int MQSpaceData::MQ8DataAir(){return map(read(),1,(_bitadc),200,10000);}
int MQSpaceData::MQ9DataAir(){return map(read(),1,(_bitadc),200,10000);}
int MQSpaceData::MQ131DataAir(){return map(read(),1,(_bitadc),5,100);}
int MQSpaceData::MQ135DataAir(){return map(read(),1,(_bitadc),10,200);}
int MQSpaceData::MQ136DataAir(){return map(read(),1,(_bitadc),10,200);}
int MQSpaceData::MQ137DataAir(){return map(read(),1,(_bitadc),10,200);}
float MQSpaceData::MQ303ADataAir()
{
_MQ303AAir = map(read(),1,(_bitadc),120,345);
return _MQ303AAir/100;
}
// https://wokwi.com/projects/394502355682092033 (MQ303A Details)
int MQSpaceData::MQ309ADataAir(){return map(read(),1,(_bitadc),160,260);}

//**************************************Limit Values**************************************

float MQSpaceData::limitValue10000(float Sensorvalue){if(Sensorvalue>10000)(Sensorvalue=10000);return Sensorvalue;}
float MQSpaceData::limitValue7000(float Sensorvalue){if(Sensorvalue>7000)(Sensorvalue=7000);return Sensorvalue;}
float MQSpaceData::limitValue4000(float Sensorvalue){if(Sensorvalue>4000)(Sensorvalue=4000);return Sensorvalue;}
float MQSpaceData::limitValue3000(float Sensorvalue){if(Sensorvalue>3000)(Sensorvalue=3000);return Sensorvalue;}
float MQSpaceData::limitValue1000(float Sensorvalue){if(Sensorvalue>1000)(Sensorvalue=1000);return Sensorvalue;}
float MQSpaceData::limitValue500(float Sensorvalue){if(Sensorvalue>500)(Sensorvalue=500);return Sensorvalue;}
float MQSpaceData::limitValue200(float Sensorvalue){if(Sensorvalue>200)(Sensorvalue=200);return Sensorvalue;}
float MQSpaceData::limitValue100(float Sensorvalue){if(Sensorvalue>100)(Sensorvalue=100);return Sensorvalue;}

//**************************************MQ-2**************************************

float MQSpaceData::MQ2DataLPG(){_va = 17.6135;_vb =  -0.4539; return limitValue10000(readValue());}
float MQSpaceData::MQ2DataPropane(){_va = 19.5575;_vb = -0.461;return limitValue10000(readValue());}
float MQSpaceData::MQ2DataH2(){_va = 25.7473;_vb = -0.4731;return limitValue10000(readValue());}
float MQSpaceData::MQ2DataAlcohol(){_va = 19.2641;_vb = -0.3604;return limitValue10000(readValue());}
float MQSpaceData::MQ2DataCH4(){_va = 20.7074;_vb = -0.36;return limitValue10000(readValue());}
float MQSpaceData::MQ2Datasmoke(){_va = 26.4698;_vb = -0.3876;return limitValue10000(readValue());}
float MQSpaceData::MQ2DataCO(){_va = 28.024;_vb = -0.3182;return limitValue10000(readValue());}

/*
Gas    | a       | b
LPG    | 17.6135 | -0.4539
propane| 19.5575 | -0.461 
H2     | 25.7473 | -0.4731
alcohol| 19.2641 | -0.3604
CH4    | 20.7074 | -0.36  
smoke  | 26.4698 | -0.3876
CO     | 28.024  | -0.3182
 */

//**************************************MQ-3**************************************

float MQSpaceData::MQ3DataAlcohol(){_va = 0.5565;_vb = -0.6333;return limitValue500(readValue());}
float MQSpaceData::MQ3DataBenzene(){_va = 1.7957;_vb = -0.369;return limitValue500(readValue());}
float MQSpaceData::MQ3DataHexane(){_va = 22.9337;_vb = -0.358;return limitValue500(readValue());}
float MQSpaceData::MQ3DataLPG(){_va = 27.8286;_vb = -0.2847;return limitValue500(readValue());}
float MQSpaceData::MQ3DataCO(){_va = 31.9559;_vb = -0.2325;return limitValue500(readValue());}
float MQSpaceData::MQ3DataCH4(){_va = 44.8389;_vb = -0.0476;return limitValue500(readValue());}

/*
Gas    | a       | b
Alcohol| 0.5565  | -0.6333
Benzene| 1.7957  | -0.369 
Hexane | 22.9337 | -0.358 
LPG    | 27.8286 | -0.2847
CO     | 31.9559 | -0.2325
CH4    | 44.8389 | -0.0476
 */

//**************************************MQ-4**************************************

float MQSpaceData::MQ4DataCH4(){_va = 11.6605;_vb = -0.3558;return limitValue10000(readValue());}
float MQSpaceData::MQ4DataLPG(){_va = 13.9134;_vb = -0.3186;return limitValue10000(readValue());}
float MQSpaceData::MQ4DataH2(){_va = 9.6559;_vb = -0.1765;return limitValue10000(readValue());}
float MQSpaceData::MQ4DataSmoke(){_va = 7.05;_vb = -0.1065;return limitValue10000(readValue());}
float MQSpaceData::MQ4DataAlcohol(){_va = 5.7994;_vb = -0.0696;return limitValue10000(readValue());}
float MQSpaceData::MQ4DataCO(){_va = 5.4783;_vb = -0.0492;return limitValue10000(readValue());}

/*
Gas    | a       | b
CH4    | 11.6605 | -0.3558
LPG    | 13.9134 | -0.3186
H2     | 9.6559  | -0.1765
smoke  | 7.05    | -0.1065
alcohol| 5.7994  | -0.0696
CO     | 5.4783  | -0.0492
 */

//**************************************MQ-5**************************************

float MQSpaceData::MQ5DataLPG(){_va = 6.1067;_vb = -0.4102;return limitValue10000(readValue());}
float MQSpaceData::MQ5DataCH4(){_va = 6.987; _vb = -0.3777;return limitValue10000(readValue());}
float MQSpaceData::MQ5DataH2(){_va = 7.4265;_vb = -0.2847;return limitValue10000(readValue());}
float MQSpaceData::MQ5DataAlcohol(){_va = 10.8274;_vb = -0.2104;return limitValue10000(readValue());}
float MQSpaceData::MQ5DataCO(){_va = 8.2236;_vb = -0.1492;return limitValue10000(readValue());}

/*
Gas    | a       | b
LPG    | 6.1067  | -0.4102
CH4    | 6.987   | -0.3777
H2     | 7.4265  | -0.2847
alcohol| 10.8274 | -0.2104
CO     | 8.2236  | -0.1492
 */

//**************************************MQ-6**************************************

float MQSpaceData::MQ6DataLPG(){_va = 20.3079;_vb = -0.4349;return limitValue10000(readValue());}
float MQSpaceData::MQ6DataCH4(){_va = 22.011;_vb =  -0.4029; return limitValue10000(readValue());}
float MQSpaceData::MQ6DataH2(){_va = 26.9497;_vb = -0.2956;return limitValue10000(readValue());}
float MQSpaceData::MQ6DataAlcohol(){_va = 19.3261; _vb = -0.1655;return limitValue10000(readValue());}
float MQSpaceData::MQ6DataCO(){_va = 13.4917;_vb = -0.0777;return limitValue10000(readValue());}

/*
Gas    | a       | b
LPG    | 20.3079 | -0.4349
CH4    | 22.011  | -0.4029
H2     | 26.9497 | -0.2956
Alcohol| 19.3261 | -0.1655
CO     | 13.4917 | -0.0777
 */

//**************************************MQ-7**************************************

float MQSpaceData::MQ7DataH2(){_va = 21.1794;_vb = -0.7174;return limitValue4000(readValue());}
float MQSpaceData::MQ7DataCO(){_va = 20.89;_vb = -0.6568;return limitValue4000(readValue());}
float MQSpaceData::MQ7DataLPG(){_va = 14.9745;_vb = -0.1329;return limitValue4000(readValue());}
float MQSpaceData::MQ7DataCH4(){_va = 19.8094;_vb = -0.09;return limitValue4000(readValue());}
float MQSpaceData::MQ7DataAlcohol(){_va = 20.2524;_vb = -0.0655;return limitValue4000(readValue());}

/*
Gas    | a       | b
H2     | 21.1794 | -0.7174
CO     | 20.89   | -0.6568
LPG    | 14.9745 | -0.1329
CH4    | 19.8094 | -0.09  
Alcohol| 20.2524 | -0.0655
 */

//**************************************MQ-8**************************************

float MQSpaceData::MQ8DataH2(){_va = 18391.5667;_vb = -1.4494;return limitValue10000(readValue());}
float MQSpaceData::MQ8DataAlcohol(){_va = 468.8045;_vb = -0.5574;return limitValue10000(readValue());}
float MQSpaceData::MQ8DataLPG(){_va = 152.1255;_vb = -0.2922;return limitValue10000(readValue());}
float MQSpaceData::MQ8DataCH4(){_va = 117.9639;_vb = -0.1448;return limitValue10000(readValue());}
float MQSpaceData::MQ8DataCO(){_va = 126.605; _vb = -0.1173;return limitValue10000(readValue());}

/*
Gas    | a       | b
H2     | 18391.5667| -1.4494
alcohol| 468.8045| -0.5574
LPG    | 152.1255| -0.2922
CH4    | 117.9639| -0.1448
CO     | 126.605 | -0.1173
 */

//**************************************MQ-9**************************************

float MQSpaceData::MQ9DataCO(){_va = 17.3985;_vb = -0.4504;return limitValue1000(readValue());}
float MQSpaceData::MQ9DataLPG(){_va = 24.918;_vb = -0.4695;return limitValue10000(readValue());}
float MQSpaceData::MQ9DataCH4(){_va = 21.8247;_vb = -0.3663;return limitValue10000(readValue());}

/*
Gas    | a       | b
CO     | 17.3985 | -0.4504
LPG    | 24.918  | -0.4695
CH4    | 21.8247 | -0.3663
 */

//**************************************MQ-131**************************************

float MQSpaceData::MQ131DataO3(){_va = 16.0871;_vb = -0.8603;return limitValue100(readValue());}
float MQSpaceData::MQ131DataCL2(){_va = 18.9693;_vb = -0.7132;return limitValue100(readValue());}
float MQSpaceData::MQ131DataNOx(){_va = 16.7059;_vb = -0.4684;return limitValue100(readValue());}

/*
Gas    | a       | b
O3     | 16.0871 | -0.8603
CL2    | 18.9693 | -0.7132
NOx    | 16.7059 | -0.4684
 */

//**************************************MQ-135**************************************

float MQSpaceData::MQ135DataAceton(){_va = 2.824;_vb = -0.2955;return limitValue200(readValue());}
float MQSpaceData::MQ135DataToluen(){_va = 2.9897;_vb = -0.2909;return limitValue200(readValue());}
float MQSpaceData::MQ135DataAlcohol(){_va = 3.8776;_vb = -0.3144;return limitValue200(readValue());}
float MQSpaceData::MQ135DataCO2(){_va = 5.2146;_vb = -0.3574;return limitValue200(readValue());}
float MQSpaceData::MQ135DataNH4(){_va = 6.4416;_vb = -0.3994;return limitValue200(readValue());}
float MQSpaceData::MQ135DataCO(){_va = 5.0533;_vb = -0.2541;return limitValue200(readValue());}

/*
Gas    | a       | b
Aceton | 2.824   | -0.2955
Toluen | 2.9897  | -0.2909
Alcohol| 3.8776  | -0.3144
CO2    | 5.2146  | -0.3574
NH4    | 6.4416  | -0.3994
CO     | 5.0533  | -0.2541
 */

//**************************************MQ-136**************************************

float MQSpaceData::MQ136DataH2S(){_va = 2.7684;_vb = -0.2832;return limitValue200(readValue());}
float MQSpaceData::MQ136DataNH4(){_va = 6.4463;_vb = -0.4028;return limitValue200(readValue());}
float MQSpaceData::MQ136DataCO(){_va = 5.277;_vb = -0.2622;return limitValue200(readValue());}

/*
Gas    | a       | b
H2S    | 2.7684  | -0.2832
NH4    | 6.4463  | -0.4028
CO     | 5.277   | -0.2622
 */

//**************************************MQ-137**************************************

float MQSpaceData::MQ137DataCO(){_va = 5.277;_vb = -0.2622;return limitValue200(readValue());}
float MQSpaceData::MQ137DataEthanol(){_va = 6.4463;_vb = -0.4028;return limitValue200(readValue());}
float MQSpaceData::MQ137DataNH3(){_va = 2.7684;_vb = -0.2832;return limitValue200(readValue());}

/*
Gas    | a       | b
CO     | 5.277   | -0.2622
Ethanol| 6.4463  | -0.4028
NH3    | 2.7684  | -0.2832
 */

//**************************************MQ-303A**************************************

float MQSpaceData::MQ303ADataHyd(){_va = 1.7955;_vb = -0.3767;return limitValue10000(readValue());}
float MQSpaceData::MQ303ADataEthanol(){_va = 1.5196;_vb = -0.367;return limitValue10000(readValue());}
float MQSpaceData::MQ303ADataIso(){_va = 1.9209;_vb = -0.3443;return limitValue10000(readValue());}

/*
Gas    | a       | b
Hydrogen| 1.7955  | -0.3767
Ethanol| 1.5196  | -0.367 
IsoButane| 1.9209  | -0.3443
 */

//**************************************MQ-309A**************************************

float MQSpaceData::MQ309ADataH2(){_va = 44.3713;_vb = -0.5136;return limitValue7000(readValue());}
float MQSpaceData::MQ309ADataCH4(){_va = 65.5612;_vb = -0.6033;return limitValue7000(readValue());}
float MQSpaceData::MQ309ADataAlcohol(){_va = 34.1956;_vb = -0.2666;return limitValue7000(readValue());}
float MQSpaceData::MQ309ADataCO(){_va = 30.3019;_vb = -0.2336;return limitValue7000(readValue());}

/*
Gas    | a       | b
H2     | 44.3713 | -0.5136
CH4    | 65.5612 | -0.6033
alcohol| 34.1956 | -0.2666
CO     | 30.3019 | -0.2336
 */

//**************************************MQ-307A & MQ-309A-Low-Sensitivity-FOR-CO**************************************

float MQSpaceData::MQ307ACO(){_va = 2336.2698;_vb = -1.7255;return limitValue1000(readValue());}
float MQSpaceData::MQ307AH2(){_va = 25051.8177;_vb = -0.8318;return limitValue3000(readValue());}

// for old curve: float MQSpaceData::MQ309ADataSecondH2(){_va = 25051.8177;_vb = -0.8318;return limitValue3000(readValue());}
// for new curve: float MQSpaceData::MQ309ADataSecondH2(){_va = 24759.2442;_vb = -0.8301;return limitValue3000(readValue());}

/*
Gas    | a         | b
CO     | 2336.2698 | -1.7255
H2     | 24759.2442| -0.8301
 */

GeigerCounterPin::GeigerCounterPin(bool uSvhr, bool Avg1, bool CPM_Count, int LOG_PERIOD1, byte pin2)
{
  _pin2=pin2;
  _usvhrbool=uSvhr;
  _Avgbool=Avg1;
  _cpmcountbool=CPM_Count;
  _LOG_PERIOD=LOG_PERIOD1;
}
 
unsigned long _counts;

void _impulse() {
   _counts++;
}

float outputSieverts(float x) {
    float y = x * 0.0057;
    return y;
}

void GeigerCounterPin::begin()
{
    _counts = 0;
    _currentCPM = 0;
    _averageCPM = 0;
    _sdCPM = 0;
    _calcCPM = 0;
    pinMode(_pin2, INPUT);
    attachInterrupt(digitalPinToInterrupt(_pin2), _impulse, FALLING);
}

void GeigerCounterPin::radyoactivite()
{
    if (_cpmcountbool == true)(count = _counts);
    if (_cpmcountbool == false)(count = 0);

    unsigned long currentMillis = millis();
  if (currentMillis - previousMillis > _LOG_PERIOD) {
    previousMillis = currentMillis;
    _CPMArray[_currentCPM] = _counts * 2;

    if (_usvhrbool == true) (usvhr = outputSieverts(_CPMArray[_currentCPM]));
    if (_usvhrbool == false) (usvhr = 0);

    _counts = 0;
    _averageCPM = 0;
    _sdCPM = 0;
  
    //calc avg and sd
    for (int x=0;x<_currentCPM+1;x++)  {
      _averageCPM = _averageCPM + _CPMArray[x];
    }
    _averageCPM = _averageCPM / (_currentCPM + 1);
    for (int x=0;x<_currentCPM+1;x++)  {
      _sdCPM = _sdCPM + sq(_CPMArray[x] - _averageCPM);
    }
    _sdCPM = sqrt(_sdCPM / _currentCPM) / sqrt(_currentCPM+1);

    if (_Avgbool == true) (Avg = outputSieverts(_averageCPM));
    if (_Avgbool == false) (Avg = 0);
    if (_sdCPMbool == true) (sdCPM = outputSieverts(_sdCPM));
    if (_sdCPMbool == false) (sdCPM = 0);
    _currentCPM = _currentCPM + 1;
}
}
