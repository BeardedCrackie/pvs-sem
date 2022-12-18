#pragma once
#include "mbed.h"
#include <iostream>

# define LED_GREEN LED1
# define LED_RED LED3
# define LED_BLUE LED2

# define TEST_DELAY 5s

enum ControlState { info, warning, blinking, running, prepare, disabled };
      
void lc_blink();
void lc_run();
void lc_stop();
void lc_setState(ControlState cs);
void lc_testLed();
