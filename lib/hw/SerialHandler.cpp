#include "SerialHandler.h"

//initialization of UnbufferedSerial port on defined pins
static UnbufferedSerial serial_port(TARGET_TX_PIN, TARGET_RX_PIN);

//variables used for serial read handling
static char lastChar;
static bool handledChar;

/*
 * callback function handled by interupt
 */
void on_rx_interrupt()
{
    if (serial_port.read(&lastChar, 1)) {
        handledChar = false;
        serial_port.write(&lastChar, 1);
    }
}

/*
 * inititialization of serial line and rx interrupt
 */
void SerialHandler::sh_init()
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

/*
 * return first char what entry serial
 */
char SerialHandler::sh_readChar()
{   
    lastChar = '\n';

    // wait for input
    while (lastChar == '\n') {
        ThisThread::sleep_for(10ms);
    }
    return lastChar;
}

/*
 * return first line of serial input
 */
string SerialHandler::sh_readString()
{   
    string s = "";
    lastChar = '\n';

    // wait for input
    while (lastChar == '\n') {
        ThisThread::sleep_for(10ms);
    }

    // till enter key was pressed
    while (lastChar != '\x0D') {
        ThisThread::sleep_for(50ms);
        if (handledChar == false) {
            s.push_back(lastChar);
            handledChar = true;
        }
    }
    return s;
}

/*
 * return int from serial input
 */
int SerialHandler::sh_readInt()
{   
    return stoi(sh_readString());
}

/*
 * write string to serial
 */
void SerialHandler::sh_write(string s) {
    const char * c = s.c_str();
    serial_port.write(c, s.length());
}