#include "LedController.h"

LedController::LedController() {
    cs = stop;
}

void run()
{
    DigitalOut red(LED1);
    DigitalOut green(LED2);
    DigitalOut blur(LED3);
    while (true) {
        switch(cs) {
            case : 
                std::cout << "red\n";   break;
            case green: std::cout << "green\n"; break;
            case blue : std::cout << "blue\n";  break;
        }
        led2 = !led2;
        ThisThread::sleep_for(250ms);

        led1 = !led1;
        ThisThread::sleep_for(600ms);

    }
}

void LedController::start_blink() {
    


    void blink() {
        while (true) {
            led1 = !led1;
            ThisThread::sleep_for(600ms);
        }
    }
    thread.start(this.blink());

DigitalOut led(LED1);
    

    while (true) {
        led1 = !led1;
        ThisThread::sleep_for(2s);
        led2 = !led2;
        led3 = !led3;
    }
};


// main() runs in its own thread in the OS
int main()
{
    while (true) {
        led1 = !led1;
        ThisThread::sleep_for(2s);
        led2 = !led2;
        led3 = !led3;
    }
}
