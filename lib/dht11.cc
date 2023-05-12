#include <stdio.h>

#include "dht11.hh"

void DHT11::get_temp_humidity()
{
    int dat[5] = { 0, 0, 0, 0, 0 };
    int j;

    // Setup the DHT11 to gather a new sample
    mode(OUTPUT);
    write(LOW);
    delay(18);
    write(HIGH);
    delayMicroseconds(40);
    mode(INPUT);

    const int maxtimings = 85;

    int i, counter, laststate;
    while (laststate = read()) {
	printf(".");
        for (i = 0; i < maxtimings; i++) {

            counter = 0;
            delayMicroseconds(1);
            if (counter == 255) {
                break;
            }
        }

        laststate = read();
        if (counter == 255) {
            break;
        }

        if ( (i >= 4) && (i % 2 == 0) ) {
            dat[j / 8] <<= 1;
            if ( counter > 16 )
                dat[j / 8] |= 1;
            j++;
        }
    }
    
    if ( (j >= 40) &&
         (dat[4] == ( (dat[0] + dat[1] + dat[2] + dat[3]) & 0xFF) ) ) {
        float f = dat[2] * 9. / 5. + 32;
        printf( "Humidity = %d.%d %% Temperature = %d.%d C (%.1f F)\n",
                dat[0], dat[1], dat[2], dat[3], f );
    } else {
        printf( "Data not good, skip\n" );
    }
}
