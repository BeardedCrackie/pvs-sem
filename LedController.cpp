#include "LedController.h"
#include <string>

ControlState lc_controlState;
Thread lc_thread;
bool lc_enabled;

void lc_blink()
{
    lc_enabled = true;
    DigitalOut red(LED_RED);
    DigitalOut green(LED_GREEN);
    DigitalOut blue(LED_BLUE);
    while (lc_enabled) {
        red = 0;
        blue = 0;
        green = 0;
        switch(lc_controlState) {
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
            case disabled: 
            default:
            // all off
                red = 0;
                blue = 0;
                green = 0;
        }
        ThisThread::sleep_for(250ms);
    }
};

void lc_run() {
    lc_thread.start(lc_blink);
}

void lc_stop(){
    lc_setState(disabled);
    lc_enabled = false;
    lc_thread.join();
}

void lc_setState(ControlState cs) {
    lc_controlState = cs;
}

void lc_testLed() {
    lc_run();
    cout << "test running" << endl;
    //iterate over each state
    for (int state = info; state != disabled; state++) {
        ControlState cs = static_cast<ControlState>(state);
        lc_setState(cs);
        cout << "state changed to: " << to_string(cs) << endl;
        ThisThread::sleep_for(TEST_DELAY);
    }
    cout << "end of test" << endl;
}
