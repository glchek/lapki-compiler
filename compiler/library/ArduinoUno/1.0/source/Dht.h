#ifndef DHT_Wrapper_H
#define DHT_Wrapper_H
#include <DHT.h>

class Dht {
    DHT sensor;

   public:
    Dht(uint8_t pin, uint8_t type, uint8_t count = 6)
        : sensor(pin, type, count) {}
    float temperature, humidity;
    
    void init();
    void update();
};

#endif