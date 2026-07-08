#include <Arduino.h>

#include "Application.h"
#include "Board.h"

Application app;

void setup()
{
    Board::init();
    app.begin();
}

void loop()
{
    app.run();
}