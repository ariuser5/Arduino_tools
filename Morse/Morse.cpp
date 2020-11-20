/*
  Morse.cpp - Library for flashing Morse code.
  Created by David A. Mellis, November 2, 2007.
  Reproduced by Darius Emanuel Ciuverca, November 21, 2020(during COVID-19 pandemic).
*/

#include "Arduino.h"
#include "Morse.h"

Morse::Morse(int pin)
{
    pinMode(pin, OUTPUT);
    _pin = pin;
}

void Morse::dot()
{
    digitalWrite(_pin, HIGH); 
    delay(150);
    digitalWrite(_pin, LOW);
    delay(150);
}

void Morse::dash()
{
    digitalWrite(_pin, HIGH); 
    delay(300);
    digitalWrite(_pin, LOW);
    delay(150);
}
