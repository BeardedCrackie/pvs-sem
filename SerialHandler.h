#pragma once
#include "mbed.h"
#include <string>

using namespace std;

// Maximum number of element the application buffer can contain
//#define MAXIMUM_BUFFER_SIZE        32
#define TARGET_TX_PIN           USBTX
#define TARGET_RX_PIN           USBRX

static char cli_input;

char sh_readChar();
void on_rx_interrupt();
void sh_init();