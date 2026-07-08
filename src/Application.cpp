#include <Arduino.h>

#include "Application.h"
#include "project.h"

void Application::begin()
{
}

void Application::run()
{
    digitalWrite(PIN_LED, HIGH);
    delay(500);

    digitalWrite(PIN_LED, LOW);
    delay(500);
}