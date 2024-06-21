/*
1) ppm = a*ratio^b: valuea() valueb()
2) ppm = 10^[(log10(ratio)-b)/m]: logm() logb()
Warning: Both formulas will give the same result. 
Since the first formula is more comprehensive(***) and easier to calculate, 
we prefer you to use the formula with a and b.

***: When calculating the first formula, the slope is created according to all points, 
while the second formula is created only according to the first and last points.

// The second formula is determined for the first and last points, 
// while the first formula is determined for all points. Since the slopes will
// change exactly proportionally in the 100% graph, the result of both is the same.

// We mathematically equalized each other by taking the logarithm of the result of a v b 
// coefficients evaluated according to all points, in order to give the same result in both cases.
// Always: logm = valueb, logb = log10(valuea)

Under normal circumstances, only when both graphs were read with 100% accuracy, 
the result would be the same. In graphs below 100%, the result would be different 
because the second formulla would behave as if it were 100% at 100%. To prevent this situation, 
we first calculated the coefficients a and b and then took the logarithm of these results.

Why is there a second formula?
because calculating the slope and general increase amount for 
fully proportional graphs will not change the result and maybe easier

However, since most calculations are made by the machine and the results obtained 
will be passed with logm = valueb, logb = log10(valuea) in any case, 
we recommend that you use the 1st formula for unsupported gas sensors.
 */
 
//**************************************MQ-2**************************************

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

/*
Gas    | m       | b
LPG    | -0.4539 | 1.2458 
propane| -0.461  | 1.2913 
H2     | -0.4731 | 1.4107 
alcohol| -0.3604 | 1.2847 
CH4    | -0.36   | 1.3161 
smoke  | -0.3876 | 1.4228 
CO     | -0.3182 | 1.4475 
 */
 
//**************************************MQ-3**************************************

/*
Gas    | a       | b
Alcohol| 0.5565  | -0.6333
Benzene| 1.7957  | -0.369 
Hexane | 22.9337 | -0.358 
LPG    | 27.8286 | -0.2847
CO     | 31.9559 | -0.2325
CH4    | 44.8389 | -0.0476
 */

/*
Gas    | m       | b
Alcohol| -0.6333 | -0.2545
Benzene| -0.369  | 0.2542 
Hexane | -0.358  | 1.3605 
LPG    | -0.2847 | 1.4445 
CO     | -0.2325 | 1.5046 
CH4    | -0.0476 | 1.6517 
 */

//**************************************MQ-4**************************************

/*
Gas    | a       | b
CH4    | 11.6605 | -0.3558
LPG    | 13.9134 | -0.3186
H2     | 9.6559  | -0.1765
smoke  | 7.05    | -0.1065
alcohol| 5.7994  | -0.0696
CO     | 5.4783  | -0.0492
 */

/*
Gas    | m       | b
CH4    | -0.3558 | 1.0667 
LPG    | -0.3186 | 1.1434 
H2     | -0.1765 | 0.9848 
smoke  | -0.1065 | 0.8482 
alcohol| -0.0696 | 0.7634 
CO     | -0.0492 | 0.7386 
 */

//**************************************MQ-5**************************************

/*
Gas    | a       | b
LPG    | 6.1067  | -0.4102
CH4    | 6.987   | -0.3777
H2     | 7.4265  | -0.2847
alcohol| 10.8274 | -0.2104
CO     | 8.2236  | -0.1492
 */

/*
Gas    | m       | b
LPG    | -0.4102 | 0.7858 
CH4    | -0.3777 | 0.8443 
H2     | -0.2847 | 0.8708 
alcohol| -0.2104 | 1.0345 
CO     | -0.1492 | 0.9151 
 */

//**************************************MQ-6**************************************

/*
Gas    | a       | b
LPG    | 20.3079 | -0.4349
CH4    | 22.011  | -0.4029
H2     | 26.9497 | -0.2956
Alcohol| 19.3261 | -0.1655
CO     | 13.4917 | -0.0777
 */

/*
Gas    | m       | b
LPG    | -0.4349 | 1.3077 
CH4    | -0.4029 | 1.3426 
H2     | -0.2956 | 1.4306 
Alcohol| -0.1655 | 1.2861 
CO     | -0.0777 | 1.1301 
 */
 
//**************************************MQ-7**************************************

/*
Gas    | a       | b
H2     | 21.1794 | -0.7174
CO     | 20.89   | -0.6568
LPG    | 14.9745 | -0.1329
CH4    | 19.8094 | -0.09  
Alcohol| 20.2524 | -0.0655
 */

/*
Gas    | m       | b
H2     | -0.7174 | 1.3259 
CO     | -0.6568 | 1.3199 
LPG    | -0.1329 | 1.1754 
CH4    | -0.09   | 1.2969 
Alcohol| -0.0655 | 1.3065
 */

//**************************************MQ-8**************************************

/*
Gas    | a       | b
H2     | 18391.5667| -1.4494
alcohol| 468.8045| -0.5574
LPG    | 152.1255| -0.2922
CH4    | 117.9639| -0.1448
CO     | 126.605 | -0.1173
 */

/*
Gas    | m       | b
H2     | -1.4494 | 4.2646 
alcohol| -0.5574 | 2.671  
LPG    | -0.2922 | 2.1822 
CH4    | -0.1448 | 2.0717 
CO     | -0.1173 | 2.1025 
 */

//**************************************MQ-9**************************************

/*
Gas    | a       | b
CO     | 17.3985 | -0.4504
LPG    | 24.918  | -0.4695
CH4    | 21.8247 | -0.3663
 */

/*
Gas    | m       | b
CO     | -0.4504 | 1.2405 
LPG    | -0.4695 | 1.3965 
CH4    | -0.3663 | 1.3389 
 */

//**************************************MQ-131**************************************

/*
Gas    | a       | b
O3     | 16.0871 | -0.8603
CL2    | 18.9693 | -0.7132
NOx    | 16.7059 | -0.4684
 */

/*
Gas    | m       | b
O3     | -0.8603 | 1.2065 
CL2    | -0.7132 | 1.2781 
NOx    | -0.4684 | 1.2229 
 */

//**************************************MQ-135**************************************

/*
Gas    | a       | b
Aceton | 2.824   | -0.2955
Toluen | 2.9897  | -0.2909
Alcohol| 3.8776  | -0.3144
CO2    | 5.2146  | -0.3574
NH4    | 6.4416  | -0.3994
CO     | 5.0533  | -0.2541
 */

/*
Gas    | m       | b
Aceton | -0.2955 | 0.4509 
Toluen | -0.2909 | 0.4756 
Alcohol| -0.3144 | 0.5886 
CO2    | -0.3574 | 0.7172 
NH4    | -0.3994 | 0.809  
CO     | -0.2541 | 0.7036 
 */

//**************************************MQ-136**************************************

/*
Gas    | a       | b
H2S    | 2.7684  | -0.2832
NH4    | 6.4463  | -0.4028
CO     | 5.277   | -0.2622
 */

/*
Gas    | m       | b
H2S    | -0.2832 | 0.4422 
NH4    | -0.4028 | 0.8093 
CO     | -0.2622 | 0.7224 
 */

//**************************************MQ-137**************************************

/*
Gas    | a       | b
CO     | 5.277   | -0.2622
Ethanol| 6.4463  | -0.4028
NH3    | 2.7684  | -0.2832
 */

/*
Gas    | m       | b
CO     | -0.2622 | 0.7224
Ethanol| -0.4028 | 0.8093
NH3    | -0.2832 | 0.4422
 */
 
//**************************************MQ-303A**************************************

/*
Gas    | a       | b
Hydrogen| 1.7955  | -0.3767
Ethanol| 1.5196  | -0.367 
IsoButane| 1.9209  | -0.3443
 */

/*
Gas    | m       | b
Hydrogen| -0.3767 | 0.2542 
Ethanol| -0.367  | 0.1817 
IsoButane| -0.3443 | 0.2835 
 */

//**************************************MQ-307A**************************************

// Exceptional: OldCurve.py [MQ307A = MQ309A (Low sensitivity for CO) SECOND GRAPH]

/*
Gas    | a       | b
CO     | 2336.2698| -1.7255
H2     | 25051.8177| -0.8318
 */

/*
Gas    | m       | b
CO     | -1.7255 | 3.3685 
H2     | -0.8318 | 4.3988 
 */


//**************************************MQ-309A**************************************

/*
Gas    | a       | b
H2     | 44.3713 | -0.5136
CH4    | 65.5612 | -0.6033
alcohol| 34.1956 | -0.2666
CO     | 30.3019 | -0.2336
 */

/*
Gas    | m       | b
H2     | -0.5136 | 1.6471 
CH4    | -0.6033 | 1.8166 
alcohol| -0.2666 | 1.534  
CO     | -0.2336 | 1.4815  
 */
