#include "LedController.h"

# define LED_GREEN LED1
# define LED_RED LED3
# define LED_BLUE LED2

# define TEST_DELAY 5s

LedController *LedController::instance = nullptr;

void LedController::run()
{
    DigitalOut red(LED_RED);
    DigitalOut green(LED_GREEN);
    DigitalOut blue(LED_BLUE);
    while (true) {
        red = 0;
        blue = 0;
        green = 0;
        switch(this->cs) {
            case info:
                for (int i = 0; i < 7; i++) {
                    blue = !blue;
                    ThisThread::sleep_for(125ms);
                }
                ThisThread::sleep_for(2s);
                break;
            case warning : 
            // 3 times fast blink red led, than some time off
                for (int i = 0; i < 7; i++) {
                    red = !red;
                    ThisThread::sleep_for(125ms);
                }
                ThisThread::sleep_for(2s);
                break;
            case running : 
            // 3 times fast blink red led, than some time off
                green = 1;
                break;
            case prepare : 
            // 3 times fast blink red led, than some time off
                red = 1;
                ThisThread::sleep_for(125ms);
                blue = 1;
                ThisThread::sleep_for(125ms);
                green = 1;
                ThisThread::sleep_for(500ms);
                red=0, blue=0, green = 0;
                ThisThread::sleep_for(250ms);
                break;
            case stop: 
            default:
            // all off
                ThisThread::sleep_for(250ms);
        }
    }
}

void LedController::testLed() {
    
    //iterate over each state
    for (int state = stop; state != prepare; state++) {
        ControlState cs = static_cast<ControlState>(state);
        this->setState(cs);
        ThisThread::sleep_for(TEST_DELAY);
    }

    // end of testing
    this->setState(stop);
}