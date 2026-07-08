#include <Arduino.h>

#include "Board.h"
#include "project.h"
#include "Logger.h"

void Board::init()
{
    pinMode(PIN_LED, OUTPUT);

    Logger::begin(SERIAL_BAUDRATE);
    Logger::info("Board initialized");
}