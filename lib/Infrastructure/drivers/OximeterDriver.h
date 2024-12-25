#ifndef OXIMETERDRIVER_H
#define OXIMETERDRIVER_H

#include<Arduino.h>

#include"../components/oxigen_and_heart_frequency_sensors/Max30105PluseOxiAndHRSensor.h"


class OximeterDriver
{
private:

    int _mesurement;
public:
    OximeterDriver()
    {}
    ~OximeterDriver();


    int getOxigenRate(){
        return _mesurement;
    }
    
};




#endif // MACRO
