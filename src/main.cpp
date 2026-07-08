#include <Arduino.h>

#include "project.h"
#include "Logger.h"

void setup()
{
    pinMode(PIN_LED, OUTPUT);

    Logger::begin(SERIAL_BAUDRATE);

    Logger::info("Application started");
}

void loop()
{
    digitalWrite(PIN_LED, HIGH);
    delay(500);

    digitalWrite(PIN_LED, LOW);
    delay(500);
}