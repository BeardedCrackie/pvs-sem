#pragma once
#include "mbed.h"
#include <string>

using namespace std;
// Maximum number of element the application buffer can contain
//#define MAXIMUM_BUFFER_SIZE        32
#define TARGET_TX_PIN           USBTX
#define TARGET_RX_PIN           USBRX

//static char cli_input;
class SerialHandler {
    public:
        static char sh_readChar();
        static string sh_readString();
        static int sh_readInt();
        static void sh_init();
        static void sh_write(string s);
};
