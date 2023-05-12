#pragma once

#include <vpio.hh>

class DHT11: public Pin
{
public:
    DHT11(int p): Pin(p, INPUT) { }

    void get_temp_humidity();
    float vals[2], temp, humidity;
};
