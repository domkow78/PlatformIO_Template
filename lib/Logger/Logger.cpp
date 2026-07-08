#include "Logger.h"

void Logger::begin(unsigned long baudrate)
{
    Serial.begin(baudrate);
}

void Logger::info(const char *message)
{
    Serial.println(message);
}