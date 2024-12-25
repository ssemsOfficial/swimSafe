#ifndef HUMAN_H
#define HUMAN_H

#include<Arduino.h>

#define BUTTON_RELEASED 0
#define BUTTON_CLICKED 1


class Human
{
private:
    
    
public:
    int heartRateValue;

     //events
    struct systemEvents 
    {
        struct OnHeartRate
        {
            enum States{ ON_UNKOWN, ON_NORMAL, ON_UPPER, ON_LOWER };
            States state    = ON_UNKOWN;
            States preValue = ON_UNKOWN;
        };
        OnHeartRate onHeartRate;
        
    };
    systemEvents events;
    
    //system states
    struct SystemStates
    {
        enum HeartRateSates
        {
            INIT,
            HEART_RATE_IS_MORE_THAN_NORMAL,
            HEART_RATE_IS_NORMAL,
            HEART_RATE_IS_LESS_THAN_NORMAL 
        };
        HeartRateSates heartRateState     = INIT;
        HeartRateSates preHeartRateState  = INIT;

        //enum OxigenRateStates
        //{
        //    INIT
        //};
        //OxigenRateStates oxigenRateState     = INIT;
        //OxigenRateStates preOxigenRateState  = INIT;


    };
    SystemStates states;
    

    //actions
    struct systemActions
    {
        struct SolenoidValve
        {
            bool state              = false;
            bool preState           = false;
            bool heartRateCondition = false;
            
        };
        SolenoidValve solenoidValve;
    };
    systemActions actions;


    Human()
    {}
    ~Human();
    
};

#endif