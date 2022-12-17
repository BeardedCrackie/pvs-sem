#pragma once
#include "mbed.h"

enum ControlState { stop, info, warning, blinking, running, prepare };

class LedController
{
    private:
        static LedController *instance;
        LedController() {
                this->cs = stop;
            };
        ControlState cs;
        
    public:
        static LedController *getInstance() {
            if (!instance)
                instance = new LedController;
            return instance;
        };
        void run();
        void setState(ControlState cs) {
            this->cs = cs;
        };
        void testLed();
};

