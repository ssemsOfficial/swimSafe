#ifndef MAX30105PLUSEOXIANDHRSENOR_H
#define MAX30105PLUSEOXIANDHRSENOR_H

#include<Arduino.h>



#include<MAX3010x.h>

#include "../../../BSP.h"

class Max30105PluseOxiAndHRSensor
{
private:
    MAX30105 sensor;

public:
    Max30105PluseOxiAndHRSensor()
    {}
    ~Max30105PluseOxiAndHRSensor();

    void init(){
        if (!sensor.begin() && sensor.setSamplingRate(sensor.SAMPLING_RATE_400SPS)) {
            Serial.println("Sensor not found");
            while (1);
        }
    }

    int getHeartRate(){
        //logic to calculate heart frequency 
        return 1;
    }

};




#endif // MACRO
