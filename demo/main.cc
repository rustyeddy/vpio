#include <iostream>
#include <wiringPi.h>

#include "dht11.hh"

using namespace std;

int main(int argc, char **argv, char **envp)
{
    DHT11 dht11(17);
    while (true) {
        // cout << dht11.read() << endl;
	dht11.get_temp_humidity();
        delay(1000);
    }

}
