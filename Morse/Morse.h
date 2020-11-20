

/*
  Morse.h - Library for flashing Morse code.
  Created by David A. Mellis, November 2, 2007.
  Reproduced by Darius Emanuel Ciuverca, November 21, 2020(during COVID-19 pandemic).
*/

#ifndef _Morse_h
#define _Morse_h

#include "Arduino.h"

class Morse
{
    public:
        Morse(int pin);
        void dot();
        void dash();
    
    private:
        int _pin;
};

#endif