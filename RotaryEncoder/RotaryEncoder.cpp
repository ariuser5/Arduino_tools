/*
  RotaryEncoder.cpp - Library for reading RotaryEncoder signal.
  Created by Darius E. Ciuverca, November 21, 2020.
  Released into the public domain.
*/

#include "Arduino.h"
#include "RotaryEncoder.h"

RotaryEncoder::RotaryEncoder()
{
    this->setOutputPins(-1, -1);
    this->_lastState = LOW;
    this->_tState = 2;
}

RotaryEncoder::RotaryEncoder(int outputA, int outputB) :
    RotaryEncoder()
{
    this->setOutputPins(outputA, outputB);
    this->_lastState = digitalRead(outputA);
}

void RotaryEncoder::setOutputPins(int outputA, int outputB)
{
    this->setAPin(outputA);
    this->setBPin(outputB);
}

void RotaryEncoder::setAPin(int pinNumber)
{
    this->_outputA = pinNumber;
    pinMode(pinNumber, INPUT);
}

void RotaryEncoder::setBPin(int pinNumber)
{
    this->_outputB = pinNumber;
    pinMode(pinNumber, INPUT);  
}

int8_t RotaryEncoder::readSignal()
{
    int aState = digitalRead(this->_outputA);
    int bState = digitalRead(this->_outputB);

    if(aState != bState){
        if(this->_tState == 2){

            if(aState != this->_lastState){
                this->_tState = aState;
                return 1;
            } else if(bState != this->_lastState){
                this->_tState = bState;
                return -1;
            }

        }
    } else if(aState == this->_tState && 
              bState == this->_tState) 
    {
        this->_lastState = this->_tState;
        this->_tState = 2;
    }

    return 0;
}