import numpy as np


y  = 0.75  #define final reference point of the graph
y0 = 2.6   #define first reference point of the graph
x  = 10000 #define max ppm concentrate
x0 = 200   #define min ppm concentrate

def resultA():
  return np.log(y/y0) / np.log(x/x0);

def resultB():
  return np.log(y) - resultA()*np.log(x)

print("ValueA:")
print(resultA())
print("ValueB:")
print(resultB())
