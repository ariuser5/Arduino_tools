/*
  RotaryEncoder.h - Library for reading RotaryEncoder signal.
  Created by Darius E. Ciuverca, November 21, 2020.
  Released into the public domain.
*/

#ifndef _RotaryEncoder_h
#define _RotaryEncoder_h

#include <stdint.h>
#include "Arduino.h"

const int ROTENC_DEFAULT_DEBOUNCE_DELLAY = 10;

class RotaryEncoder
{
    public:
        RotaryEncoder();
        RotaryEncoder(int outputA, int outputB);
        void setOutputPins(int outputA, int outputB);
        void setAPin(int pinNumber);
        void setBPin(int pinNumber);
        int8_t readSignal();
    private:
        uint16_t _outputA;
        uint16_t _outputB;
        int8_t _lastState;
        int8_t _tState;
};

#endif