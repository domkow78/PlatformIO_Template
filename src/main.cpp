#include <Arduino.h>

#include "Board.h"

void setup()
{
    Board::init();
}

void loop()
{
    digitalWrite(PIN_LED, HIGH);
    delay(500);

    digitalWrite(PIN_LED, LOW);
    delay(500);
}