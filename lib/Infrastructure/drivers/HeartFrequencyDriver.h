#ifndef HEARTFREQUENCYDRIVER_H
#define HEARTFREQUENCYDRIVER_H

#include<Arduino.h>

#include"../components/oxigen_and_heart_frequency_sensors/Max30105PluseOxiAndHRSensor.h"

class HeartFrequencyDriver
{
private:
    Max30105PluseOxiAndHRSensor &_sensor;
    int _mesurement;
public:
    HeartFrequencyDriver(Max30105PluseOxiAndHRSensor &sensor)
    : _sensor(sensor)
    {}
    ~HeartFrequencyDriver();
    
    int getHeartRate(){
        /// here logic to calculate HeartRate
        return _mesurement;
    }

};




#endif // MACRO
