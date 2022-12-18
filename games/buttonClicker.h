#pragma once
#include "mbed.h"
#include "auxFunctions.h"
#include "LedController.h"

#define INTERRUPT_PIN PC_13
#define DELAY 1500ms
#define CONTEST_TIME 10s

/*
 * class represents game ButtonClicker
 */
class ButtonClicker {
    public:
        static void startGame();
};
