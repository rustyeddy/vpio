// Copyright Rusty Eddy 2023

// #include <wiringPi.h>
#include "vpio.hh"

Pin::Pin(int p, int d)
{
    if (!isWiringPiSetup) {
        wiringPiSetup();
        isWiringPiSetup = true;
    }

    _pin = p;
    _dir = d;
    pinMode(_pin, _dir);
}

void Pin::mode(int dir)
{
    _dir = dir;
    pinMode(_pin, _dir);
}

void Pin::write(int val)
{
    digitalWrite(_pin, val);
}

int Pin::read()
{
    return digitalRead(_pin);
}
