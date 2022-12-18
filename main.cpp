#include "mbed.h"
#include "ConsoleApp.h"
#include "SerialHandler.h"
#include "LedController.h"

/*
 * provide end led sequence and disable led controller
 */
void main_end() {
    lc_setState(prepare);
    ThisThread::sleep_for(2s);
    lc_setState(warning);
    ThisThread::sleep_for(2s);
    lc_stop();
}

/*
 * start console app
 */
int main(void)
{
    lc_setState(prepare);
    lc_run();
    ThisThread::sleep_for(2s);
    SerialHandler::sh_init();
    ConsoleApp *ca = new ConsoleApp();
    ca->Start();
    main_end();
}