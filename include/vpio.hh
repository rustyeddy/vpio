// Copyright 2023 Rusty Eddy

#include <wiringPi.h>

static bool isWiringPiSetup = false;

class Pin {
protected:
    int _pin = -1;
    int _dir = OUTPUT;

public:
    Pin(int p, int d);
    
    void mode(int dir);
    void write(int val);
    int  read();
};

