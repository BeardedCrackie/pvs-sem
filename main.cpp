#include "mbed.h"
#include "LedController.h"

Thread thread;


void ledControllerThread()
{
    LedController* lc = lc->getInstance();
    lc->run();
}

int main()
{
    thread.start(ledControllerThread);
    LedController* lc = lc->getInstance();
    lc->testLed();
}