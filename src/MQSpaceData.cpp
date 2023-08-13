
#include "MQSpaceData.h"
#include "Arduino.h"

MQSpaceData::MQSpaceData(int bitadc, float Rload, byte pin)
{
  _pin=pin;
  _Rload=Rload;
  _bitadc=bitadc;
}

void MQSpaceData::begin()
{
  pinMode(_pin,INPUT);
}

void MQSpaceData::calibrateR0(float calibration)
{
 _R0 = calibration; 
}

//**************************************Ready Calibration**************************************\\

void MQSpaceData::MQ2calibrate(){_R0 = 2.74;}
void MQSpaceData::MQ3calibrate(){_R0 = 0.45;}
void MQSpaceData::MQ4calibrate(){_R0 = 6.14;}
void MQSpaceData::MQ5calibrate(){_R0 = 4.16;}
void MQSpaceData::MQ6calibrate(){_R0 = 2.71;}
void MQSpaceData::MQ7calibrate(){_R0 = 0.98;}
void MQSpaceData::MQ8calibrate(){_R0 = 0.386;}
void MQSpaceData::MQ9calibrate(){_R0 = 2.816;}
void MQSpaceData::MQ131calibrate(){_R0 = 0.67;}
void MQSpaceData::MQ135calibrate(){_R0 = 8.2809;}
void MQSpaceData::MQ136calibrate(){_R0 = 7.5;}
void MQSpaceData::MQ303Acalibrate(){_R0 = 27;}
void MQSpaceData::MQ309Acalibrate(){_R0 = 2.458;}

void MQSpaceData::valuea(float data1)
{
 _va = data1;
}

void MQSpaceData::valueb(float data2)
{
 _vb = data2;
}

float MQSpaceData::readValue()
{
  if(_Rload <= 0) _Rload == 10;
  if(( _Rload - _Rload) != 0) _Rload == 10;
  if(_Rload >= 47) _Rload == 47;
  _RS = ((_Rload/(analogRead(_pin)*(1/(pow(2,_bitadc)-1))))-(_Rload));
  _ratio = ( _RS / _R0);
 return pow(_ratio,_vb)*_va;
}

//**************************************ppm Value**************************************\\

float MQSpaceData::MQData100(){return map(analogRead(_pin),0,(_bitadc-1),0,100);}
float MQSpaceData::MQ2DataAir(){return map(analogRead(_pin),1,(_bitadc-1),300,10000);}
float MQSpaceData::MQ3DataAir(){return map(analogRead(_pin),1,(_bitadc-1),25,500);}
float MQSpaceData::MQ4DataAir(){return map(analogRead(_pin),1,(_bitadc-1),300,10000);}
float MQSpaceData::MQ5DataAir(){return map(analogRead(_pin),1,(_bitadc-1),200,10000);}
float MQSpaceData::MQ6DataAir(){return map(analogRead(_pin),1,(_bitadc-1),300,10000);}
float MQSpaceData::MQ7DataAir(){return map(analogRead(_pin),1,(_bitadc-1),10,10000);}
float MQSpaceData::MQ8DataAir(){return map(analogRead(_pin),1,(_bitadc-1),10,10000);}
float MQSpaceData::MQ9DataAir(){return map(analogRead(_pin),1,(_bitadc-1),10,10000);}
float MQSpaceData::MQ131DataAir(){return map(analogRead(_pin),1,(_bitadc-1),5,100);}
float MQSpaceData::MQ135DataAir(){return map(analogRead(_pin),1,(_bitadc-1),10,1000);}
float MQSpaceData::MQ136DataAir(){return map(analogRead(_pin),1,(_bitadc-1),10,200);}
float MQSpaceData::MQ303ADataAir(){return map(analogRead(_pin),1,(_bitadc-1),10,10000);}
float MQSpaceData::MQ309ADataAir(){return map(analogRead(_pin),1,(_bitadc-1),30,3000);}

//**************************************MQ-2**************************************\\

float MQSpaceData::MQ2DataH2(){_va = 987.99;_vb = -2.162;return readValue();}
float MQSpaceData::MQ2DataLPG(){_va = 574.25;_vb = -2.222; return readValue();}
float MQSpaceData::MQ2DataCO(){_va = 36974;_vb = -3.109;return readValue();}
float MQSpaceData::MQ2DataAlcohol(){_va = 3616.1;_vb = -2.675;return readValue();}
float MQSpaceData::MQ2DataPropane(){_va = 658.71;_vb = -2.168;return readValue();}

//**************************************MQ-3**************************************\\

float MQSpaceData::MQ3DataLPG(){_va = 44771;_vb = -3.245;return readValue();}
float MQSpaceData::MQ3DataCH4(){_va = 2*10^31;_vb = 19.01;return readValue();}
float MQSpaceData::MQ3DataCO(){_va = 521853;_vb = -3.821;return readValue();}
float MQSpaceData::MQ3DataAlcohol(){_va = 0.3934;_vb = -1.504;return readValue();}
float MQSpaceData::MQ3DataBenzene(){_va = 4.8387;_vb = -2.68;return readValue();}
float MQSpaceData::MQ3DataHexane(){_va = 7585.3;_vb = -2.849;return readValue();}

//**************************************MQ-4**************************************\\

float MQSpaceData::MQ4DataLPG(){_va = 3811.9;_vb = -3.113;return readValue();}
float MQSpaceData::MQ4DataCH4(){_va = 1012.7;_vb = -2.786;return readValue();}
float MQSpaceData::MQ4DataCO(){_va = 200000000000000;_vb = -19.05;return readValue();}
float MQSpaceData::MQ4DataAlcohol(){_va = 60000000000;_vb = -14.01;return readValue();}
float MQSpaceData::MQ4DataSmoke(){_va = 30000000;_vb = -8.308;return readValue();}

//**************************************MQ-5**************************************\\

float MQSpaceData::MQ5DataH2(){_va = 1163.8;_vb = -3.874;return readValue();}
float MQSpaceData::MQ5DataLPG(){_va = 80.897; _vb = -2.431;return readValue();}
float MQSpaceData::MQ5DataCH4(){_va = 177.65;_vb = -2.56;return readValue();}
float MQSpaceData::MQ5DataCO(){_va = 491204; _vb = -5.826; return readValue();}
float MQSpaceData::MQ5DataAlcohol(){_va = 97124;_vb = -4.918;return readValue();}

//**************************************MQ-6**************************************\\

float MQSpaceData::MQ6DataH2(){_va = 88158;_vb =  -3.597;return readValue();}
float MQSpaceData::MQ6DataLPG(){_va = 1009.2;_vb =  -2.35; return readValue();}
float MQSpaceData::MQ6DataCH4(){_va = 2127.2;  _vb = -2.526;return readValue();}
float MQSpaceData::MQ6DataCO(){_va = 1000000000000000; _vb = -13.5;return readValue();}
float MQSpaceData::MQ6DataAlcohol(){_va = 50000000;_vb = -6.017;return readValue();}

//**************************************MQ-7**************************************\\

float MQSpaceData::MQ7DataH2(){_va = 69.014;_vb = -1.374; return readValue();}
float MQSpaceData::MQ7DataLPG(){_va = 700000000;_vb = -7.703;return readValue();}
float MQSpaceData::MQ7DataCH4(){_va = 60000000000000;_vb = -10.54;return readValue();}
float MQSpaceData::MQ7DataCO(){_va = 99.042;_vb = -1.518;return readValue();}
float MQSpaceData::MQ7DataAlcohol(){_va = 40000000000000000;_vb = -12.35;return readValue();}

//**************************************MQ-8**************************************\\

float MQSpaceData::MQ8DataH2(){_va = 976.97;_vb = -0.688;return readValue();}
float MQSpaceData::MQ8DataLPG(){_va = 10000000;_vb = -3.12;return readValue();}
float MQSpaceData::MQ8DataCH4(){_va = 80000000000000;_vb = -6.666;return readValue();}
float MQSpaceData::MQ8DataCO(){_va = 2000000000000000000;_vb = -8.074;return readValue();}
float MQSpaceData::MQ8DataAlcohol(){_va = 76101; _vb = -1.86;return readValue();}

//**************************************MQ-9**************************************\\

float MQSpaceData::MQ9DataLPG(){_va = 1000.5;_vb = -2.186;return readValue();}
float MQSpaceData::MQ9DataCH4(){_va = 4269.6;_vb = -2.648;return readValue();}
float MQSpaceData::MQ9DataCO(){_va = 599.65;_vb = -2.244;return readValue();}

//**************************************MQ-131**************************************\\

float MQSpaceData::MQ131DataNOx(){_va = -462.43;_vb = -2.204;return readValue();}
float MQSpaceData::MQ131DataCL2(){_va = 47.209;_vb = -1.186;return readValue();}
float MQSpaceData::MQ131DataO3(){_va = 23.943;_vb = -1.11;return readValue();}

//**************************************MQ-135**************************************\\

float MQSpaceData::MQ135DataCO(){_va = 605.18;_vb = -3.937;return readValue();}
float MQSpaceData::MQ135DataAlcohol(){_va = 77.255;_vb = -3.18;return readValue();}
float MQSpaceData::MQ135DataCO2(){_va = 110.47;_vb = -2.862; return readValue();}
float MQSpaceData::MQ135DataToluen(){_va = 44.947;_vb = -3.445;return readValue();}
float MQSpaceData::MQ135DataNH4(){_va = 102.2;_vb = -2.473;return readValue();}
float MQSpaceData::MQ135DataAceton(){_va = 34.668;_vb = -3.369; return readValue();}

//**************************************MQ-136**************************************\\

float MQSpaceData::MQ136DataH2S(){_va = 36.737;_vb = -3.536;return readValue();}
float MQSpaceData::MQ136DataNH4(){_va = 98.551;_vb = -2.475;return readValue();}
float MQSpaceData::MQ136DataCO(){_va = 503.34;_vb = -3.774;return readValue();}

//**************************************MQ-303A**************************************\\

float MQSpaceData::MQ303ADataIso(){_va = 6.2144;_vb = -2.894;return readValue();}
float MQSpaceData::MQ303ADataHyd(){_va = 4.1487;_vb = -2.716;return readValue();}
float MQSpaceData::MQ303ADataEthanol(){_va = 3.4916;_vb = -2.432;return readValue();}

//**************************************MQ-309A**************************************\\

float MQSpaceData::MQ309ADataH2(){_va = 1532.9;_vb = -1.951;return readValue();}
float MQSpaceData::MQ309ADataCH4(){_va = 980.24;_vb = -1.68;return readValue();}
float MQSpaceData::MQ309ADataCO(){_va = 1000000;_vb = -4.01;return readValue();}
float MQSpaceData::MQ309ADataAlcohol(){_va = 473622;_vb = -3.647;return readValue();}

calibrateR0::calibrateR0(float RSR0, float Rload, float voltage, float bitadc, byte pin)
{
_RSR0=RSR0;
_Rload = Rload;
_voltage=voltage;
_bitadc = bitadc;
_pin = pin;
};

void calibrateR0::begin()
{
    pinMode(_pin, INPUT);
}

float calibrateR0::readVoltage()
{
    float _sensorValue = 0;
    for (int x = 0; x < 500; x++)
    {
        _sensorValue = _sensorValue + analogRead(_pin);
    }
    _sensorValue = _sensorValue / 500.0;
    return _sensorValue * (_voltage / (pow(2, _bitadc) - 1));
}

float calibrateR0::calculateR0()
{
    _RS = ((_voltage * _Rload) / readVoltage()) - (_Rload);
    _R0 = (_RS / _RSR0);
    return _R0;
}

calibrateR0VeryEasy::calibrateR0VeryEasy(float RSR0, float Rleasy)
{
  _RSR0=RSR0;
  _Rload=Rleasy;
}

float calibrateR0VeryEasy::calculateR0VeryEasy(float percentile)
{
    _RS = (100 * _Rload / percentile) - (_Rload);
    _R0 = (_RS / _RSR0);
    return _R0;
}

result::result(float y, float y0, float x, float x0)
{
  _y=y;
  _y0=y0;
  _x=x;
  _x0=x0;
}

float result::resultA(){
return log(_y/_y0) / log(_x/_x0);    
}

float result::resultB(){
return log(_y) - resultA()*log(_x);
}

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
    if (_usvhrbool == false) (usvhr = outputSieverts(_CPMArray[_currentCPM]));

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
