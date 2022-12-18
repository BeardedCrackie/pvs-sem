#include "SerialHandler.h"

// Create a UnbufferedSerial object with a default baud rate.
static UnbufferedSerial serial_port(TARGET_TX_PIN, TARGET_RX_PIN);
static char lastChar;
static bool handledChar;

void on_rx_interrupt()
{
    if (serial_port.read(&lastChar, 1)) {
        handledChar = false;
        serial_port.write(&lastChar, 1);
    }
}

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

char SerialHandler::sh_readChar()
{   
    lastChar = '\n';
    while (lastChar == '\n') {
        ThisThread::sleep_for(10ms);
    }
    return lastChar;
}

string SerialHandler::sh_readString()
{   
    string s = "";
    lastChar = '\n';
    while (lastChar == '\n') {
        ThisThread::sleep_for(10ms);
    }
    while (lastChar != '\x0D') {
        ThisThread::sleep_for(50ms);
        if (handledChar == false) {
            s.push_back(lastChar);
            handledChar = true;
        }
    }
    return s;
}

int SerialHandler::sh_readInt()
{   
    return stoi(sh_readString());
}

void SerialHandler::sh_write(string s) {
    const char * c = s.c_str();
    serial_port.write(c, s.length());
}