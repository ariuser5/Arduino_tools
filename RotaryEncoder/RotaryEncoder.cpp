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
    this->_debounceDelay = ROTENC_DEFAULT_DEBOUNCE_DELLAY;
    this->_lastDebounceTime = 0;
    this->_aLastState = LOW;
}

RotaryEncoder::RotaryEncoder(int outputA, int outputB) :
    RotaryEncoder()
{
    this->setOutputPins(outputA, outputB);
    this->_aLastState = digitalRead(outputA);
}

void RotaryEncoder::setOutputPins(int outputA, int outputB)
{
    this->setAPin(outputA);
    this->setBPin(outputB);
}

void RotaryEncoder::setAPin(int pinNumber)
{
    this->_outputA = pinNumber;
}

void RotaryEncoder::setBPin(int pinNumber)
{
    this->_outputB = pinNumber;
}

void RotaryEncoder::setDebounceDelay(unsigned int value)
{
    this->_debounceDelay = value;
}

int8_t RotaryEncoder::readRawSignal()
{
    int aState = digitalRead(this->_outputA);
    int retVal = 0;

    if(aState != this->_aLastState){
        int bState = digitalRead(this->_outputB);

        retVal = (aState != bState) ? 1 : -1;
    }

    this->_aLastState = aState;
    return retVal;
}

int8_t RotaryEncoder::readSignal(unsigned long millis)
{
    if( (millis - this->_lastDebounceTime) > 
        this->_debounceDelay) 
    {
        this->_lastDebounceTime = millis;
        return this->readRawSignal(); 
    }

    return 0;
}