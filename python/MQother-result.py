from math import log10

y  = 3.6        #define final reference point of the graph
y0 = 4.2        #define first reference point of the graph
x  = 10000      #define max ppm concentrate
x0 = 200        #define min ppm concentrate
AverageY = 0.9  #define your y value at medium ppm concentration

def resultA():
  return log10(y/y0) / log10(x/x0);

def resultB():
  return log10(AverageY) - resultA()*log10(x/2)

print("valuea():")
print(resultA())
print("valueb():")
print(resultB())

