#include "LedController.h"
#include <string>

ControlState lc_controlState;
Thread lc_thread;
bool lc_enabled;

/*
 * function for led renderring according to ControlState
 */
void lc_blink()
{

    //definitions
    lc_enabled = true;
    DigitalOut red(LED_RED);
    DigitalOut green(LED_GREEN);
    DigitalOut blue(LED_BLUE);
    
    //led render loop
    while (lc_enabled) {

        //reset all led
        red = 0;
        blue = 0;
        green = 0;


        switch(lc_controlState) {

            
            case info:
                // 3 times fast blink blue led, than some time off
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

/*
 * start led rendering in second thread
 */
void lc_run() {
    lc_thread.start(lc_blink);
}

/*
 * stop led rendering, end thread
 */
void lc_stop(){
    lc_setState(disabled);
    lc_enabled = false;
    lc_thread.join();
}

/*
 * change ControlState of led
 */
void lc_setState(ControlState cs) {
    lc_controlState = cs;
}

/*
 * run test sequence of led with debuf print
 */
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
