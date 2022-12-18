#include "mbed.h"
#include "ConsoleApp.h"
#include "SerialHandler.h"
#include "LedController.h"

void main_end() {
    lc_setState(prepare);
    ThisThread::sleep_for(2s);
    lc_setState(warning);
    ThisThread::sleep_for(2s);
    lc_stop();
}

int main(void)
{
    lc_setState(prepare);
    lc_run();
    ThisThread::sleep_for(2s);
    SerialHandler::sh_init();
    ConsoleApp *ca = new ConsoleApp();
    ca->start();
    main_end();
}