#include <MQSpaceData.h>

/*
Range       Sensor RVID
5kΩ-47kΩ    MQ-2   20kΩ
100kΩ-470kΩ MQ-3   200kΩ
10kΩ-47kΩ   MQ-4   20kΩ
10kΩ-47kΩ   MQ-5   20kΩ
10kΩ-47kΩ   MQ-6   20kΩ
5kΩ-47kΩ    MQ-7   10kΩ
5kΩ-33kΩ    MQ-8   10kΩ
10kΩ-47kΩ   MQ-9   20kΩ
50kΩ-200kΩ  MQ131  100kΩ
10kΩ-47kΩ   MQ-135 20kΩ
10kΩ-47kΩ   MQ-136 20kΩ
10kΩ-100kΩ  MQ-137 47kΩ
(Variable>47kΩ) MQ303A 47kΩ
(not available) MQ309A 50kΩ (?? %5)

// SENSITVITY ADJUSTMENT
// Recommended values ​​in datasheet: RVID
*/

// MQ.setRL(???);  RVID or Range ?? kΩ
// MQ.solderedRL(); for soldered 1kΩ
// Warning:
// If you are using a soldered gas sensor model, we recommend that you change the 1kΩ resistor to get more accurate results.
// If you do not have the opportunity to change the resistance of the soldered gas sensor model with the recommended resistor, 
// use the solderedRL() command instead of setRL(?? resistor (kΩ) ??), but keep in mind that the accuracy rate will decrease.
