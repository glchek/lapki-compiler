#ifndef RFID_H
#define RFID_H
#include <MFRC522.h>

class RFID {
    MFRC522 sensor;

   public:
    String content = "";
    RFID(uint8_t ss_pin, uint8_t rst_pin);
    void init();
    bool isReady();
    void updateContent();
};

#endif