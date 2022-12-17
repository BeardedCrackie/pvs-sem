#include "mbed.h"

enum ControlState { stop, info, warning, blinking };

class LedController
{
    private:
        ControlState cs;
    public:
        LedController();
        void run();
        void setState(ControlState cs);
};