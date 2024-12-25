#ifndef MAX30100PLUSEOXIANDHRSENOR_H
#define MAX30100PLUSEOXIANDHRSENOR_H

#include<Arduino.h>


class Max30100PluseOxiAndHRSensor
{
private:
    int _pinSignal;
    int _mesurement;
public:
    Max30100PluseOxiAndHRSensor(int pinSignal)
    :  _pinSignal(pinSignal)
    {}
    ~Max30100PluseOxiAndHRSensor();

    void init(){
        pinMode(_pinSignal, INPUT);
        _mesurement = 0;
    }

    int getSignalVal(){
        _mesurement = digitalRead(_pinSignal);
        return _mesurement;
    }
    
    int getMesurement(){
        return _mesurement;
    }
};




#endif // MACRO
