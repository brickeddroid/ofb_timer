#include <Arduino.h>

#include <OFB_Timer.h>

Timer16 t16;
const uint16_t interval_ms = 1000;

void setup(){
    Serial.begin(115200);
    Serial.println("Simple interval with OFB_Timer");

    t16.start();
}

unsigned long curr_millis = 0, prev_millis = 0;

void loop(){
    if(t16.hasExpired(interval_ms)){
        t16.start();
        curr_millis = millis();

        Serial.print("Timer triggered after ");
        Serial.print(curr_millis - prev_millis);
        Serial.println("ms");

        prev_millis = curr_millis;
    }
}
