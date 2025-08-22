#include "Dht.h"

void Dht::update() {
    float tmp_var;
    tmp_var = sensor.readTemperature();
    if (!isnan(tmp_var)) temperature = tmp_var;
    tmp_var = sensor.readHumidity();
    if (!isnan(tmp_var)) humidity = tmp_var;
}

void Dht::init(){
    sensor.begin();
}