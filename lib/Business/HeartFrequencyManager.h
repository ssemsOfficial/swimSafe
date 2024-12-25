#ifndef HEARTFREQUENCYMANAGER_H
#define HEARTFREQUENCYMANAGER_H

//import entities
#include"../Domaine/Entities/Human.h"
//import drivers
#include"../Infrastructure/drivers\HeartFrequencyDriver.h"

class HeartFrequencyManager
{
private:
   //entity
    Human &_human;
    //drivers
    HeartFrequencyDriver &_heartFrequencyDriver;

public:
    HeartFrequencyManager(Human &human, HeartFrequencyDriver &heartFrequencyDriver):
        _human(human), _heartFrequencyDriver(heartFrequencyDriver)
    {
        
    }
    ~HeartFrequencyManager(){
        
    }

    void updateEvent();
    void updateFSM();
    void updateAction();
};

void HeartFrequencyManager::updateEvent(){

    if(_heartFrequencyDriver.getHeartRate() > MAX_NORMAL_VAL){
        _human.events.onHeartRate.state = _human.events.onHeartRate.States::ON_UPPER;          
    }             
    else if(_heartFrequencyDriver.getHeartRate() < MIN_NORMAL_VAL){
        _human.events.onHeartRate.state = _human.events.onHeartRate.States::ON_LOWER;
    }
    else {
        _human.events.onHeartRate.state = _human.events.onHeartRate.States::ON_NORMAL;
    }
        
}

void HeartFrequencyManager::updateFSM(){
    switch (_human.states.heartRateState)
    {
        //system is in initial state / initially turned on (unknown state)
        case _human.states.HeartRateSates::INIT : 
            if (_human.events.onHeartRate.state == _human.events.onHeartRate.States::ON_NORMAL)
            {
                _human.actions.solenoidValve.heartRateCondition = false;
                _human.states.preHeartRateState = _human.states.HeartRateSates::INIT;
                _human.states.heartRateState    = _human.states.HeartRateSates::HEART_RATE_IS_NORMAL;
            }
            else if (_human.events.onHeartRate.state == _human.events.onHeartRate.States::ON_UPPER)
            {
                _human.actions.solenoidValve.heartRateCondition = true;
                _human.states.preHeartRateState = _human.states.HeartRateSates::INIT;
                _human.states.heartRateState    = _human.states.HeartRateSates::HEART_RATE_IS_MORE_THAN_NORMAL;
                break;
            }
            else if (_human.events.onHeartRate.state == _human.events.onHeartRate.States::ON_LOWER)
            {
                _human.actions.solenoidValve.heartRateCondition = true;
                _human.states.preHeartRateState = _human.states.HeartRateSates::INIT;
                _human.states.heartRateState    = _human.states.HeartRateSates::HEART_RATE_IS_LESS_THAN_NORMAL;
                break;
            }
        break;

        case _human.states.HeartRateSates::HEART_RATE_IS_NORMAL : 
            if (_human.events.onHeartRate.state == _human.events.onHeartRate.States::ON_UPPER)
            {
                _human.actions.solenoidValve.heartRateCondition = true;
                _human.states.preHeartRateState = _human.states.HeartRateSates::HEART_RATE_IS_NORMAL;
                _human.states.heartRateState    = _human.states.HeartRateSates::HEART_RATE_IS_MORE_THAN_NORMAL;
                break;
            }
            else if (_human.events.onHeartRate.state == _human.events.onHeartRate.States::ON_LOWER)
            {
                _human.actions.solenoidValve.heartRateCondition = true;
                _human.states.preHeartRateState = _human.states.HeartRateSates::HEART_RATE_IS_NORMAL;
                _human.states.heartRateState    = _human.states.HeartRateSates::HEART_RATE_IS_LESS_THAN_NORMAL;
                break;
            }
        break;
        
        case _human.states.HeartRateSates::HEART_RATE_IS_MORE_THAN_NORMAL :
            if (_human.events.onHeartRate.state == _human.events.onHeartRate.States::ON_NORMAL)
            {
                _human.actions.solenoidValve.heartRateCondition = false;
                _human.states.preHeartRateState = _human.states.HeartRateSates::HEART_RATE_IS_MORE_THAN_NORMAL;
                _human.states.heartRateState    = _human.states.HeartRateSates::HEART_RATE_IS_NORMAL;
            }
        break;
        
        case _human.states.HeartRateSates::HEART_RATE_IS_LESS_THAN_NORMAL  :
            if (_human.events.onHeartRate.state == _human.events.onHeartRate.States::ON_NORMAL)
            {
                _human.actions.solenoidValve.heartRateCondition = false;
                _human.states.preHeartRateState = _human.states.HeartRateSates::HEART_RATE_IS_LESS_THAN_NORMAL;
                _human.states.heartRateState    = _human.states.HeartRateSates::HEART_RATE_IS_NORMAL;
            }
        break;
}

void HeartFrequencyManager::updateAction(){
    
}


#endif