#ifndef BUTTON_H
#define BUTTON_H

#include<Arduino.h>

#define BUTTON_RELEASED 0
#define BUTTON_CLICKED 1


class Button
{
private:
    int _pin;
    bool _state = BUTTON_RELEASED;
public:
    Button(int pin)
    : _pin(pin)
    {}
    ~Button();

    void init(){
        pinMode(_pin, INPUT);
        _state = BUTTON_RELEASED;
    }
    bool isClicked(){
        _state =  digitalRead(_pin);
        return _state;
    }
};

#endif