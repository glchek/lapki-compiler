// #include "sketch.cpp"
#include "Button.h"
#include "LapkiLed.h"
#include "Serial.h"
#include "initFunctions.hpp"
#include "UniString.h"
#include "Counter.h"
#include "Timer.h"


int main() {
    initAll();
    Led led1(5);
    Led led2(6);
    SystemLed sled = SystemLed();
    Button btn(Gpio3);
    // led2.blink(1000, 4000);
    // led2.on();
    sled.blink(500, 1000);
    sys_LED.Off();
    Counter counter;
    counter.set(0);
    counter.add(1);
    // UniString ustr = std::string("12");
    // int b = ustr;
    bool flag = 1;
    Timer tmr;
    tmr.start(15000);
    while (1) {
        if(led1.isReady() && flag){
            counter.add(1);
            led1.fadeIn(3000);
            led2.fadeOut(3000);
            flag = 0;
        }
        if(led1.isReady() && !flag){
            led1.fadeOut(2000);
            led2.fadeIn(2000);
            flag = 1;
        }
        // if (btn.isPressed())
        //     led.off();
        // else
        //     led.on();
        if (Serial::isUpdated()) {
            Serial::print(Serial::message);
            Serial::printVal("string", 1234567891012.0l);
            led2.stop();
        }
        Serial::printVal("counter: ", counter.value);
        Serial::printVal("Timer: ", tmr.difference);
        Serial::printVal("Reg: ", SYS_TIM->CNT);
        Serial::printVal("Time: ", Sys::GetSysTime());
        tmr.updateDifference();
        
        // Serial::Printf("br %d cv: %d bdif: %d del: %d step: %d\n\r",
        //                led2.ls->brightness, led2.ls->cv,
        //                led2.ls->brightness_diff, led2.ls->delay,
        //                led2.ls->step);
        watcher();
    }
}