#include "SerialHandler.h"

// Create a UnbufferedSerial object with a default baud rate.
static UnbufferedSerial serial_port(TARGET_TX_PIN, TARGET_RX_PIN);
static char lastChar;

void on_rx_interrupt()
{
    if (serial_port.read(&lastChar, 1)) {
        serial_port.write(&lastChar, 1);
    }
}

void sh_init()
{
    // Set desired properties (9600-8-N-1).
    serial_port.baud(9600);
    serial_port.format(
        /* bits */ 8,
        /* parity */ SerialBase::None,
        /* stop bit */ 1
    );
    // Register a callback to process a Rx (receive) interrupt.
    serial_port.attach(&on_rx_interrupt, SerialBase::RxIrq);
}

char sh_readChar()
{   
    lastChar = '\n';
    while (lastChar == '\n') {
        ThisThread::sleep_for(150ms);
    }
    return lastChar;
}

void sh_write(string s) {
    const char * c = s.c_str();
    serial_port.write(&c, sizeof(c));
}