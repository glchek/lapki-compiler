#include <SPI.h>

#include "RFID.h"

RFID::RFID(uint8_t ss_pin, uint8_t rst_pin) : sensor(ss_pin, rst_pin) {
    content.reserve(sensor.uid.size * 2 + 1);
}

void RFID::init(){
    SPI.begin();
    sensor.PCD_Init();
}

bool RFID::isReady(){
    return sensor.PICC_IsNewCardPresent(); 
}

void RFID::updateContent() {
    if (!sensor.PICC_ReadCardSerial()) return;
    content = "";
    for (byte i = 0; i < sensor.uid.size; i++) {
        if (sensor.uid.uidByte[i] < 0x10) content += "0";
        content += String(sensor.uid.uidByte[i], HEX);
    }
    content.toUpperCase();
    sensor.PICC_HaltA();
}