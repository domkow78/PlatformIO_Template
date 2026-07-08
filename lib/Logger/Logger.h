#pragma once

#include <Arduino.h>

class Logger
{
public:
    static void begin(unsigned long baudrate);

    static void info(const char *message);
};