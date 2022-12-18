#pragma once
#include <iostream>
#include <string>
#include "SerialHandler.h"
#include "LedController.h"

using namespace std;

/*
 * class represents auxiliary library for different purposes
 */
class AuxFunctions {
    public:
        static void printInputError(string s, int i);
        static void aux_print() {
            SerialHandler::sh_write("Welcome to the town of Honeywood");
        };
        static void aux_print(string s) {
            SerialHandler::sh_write(s);
        };
        static void aux_println(string s) {
            SerialHandler::sh_write(s);
            SerialHandler::sh_write("\n");
        };
        static void printTime() {
            time_t seconds = time(NULL);
            printf("\n Current Time is: %s", ctime(&seconds));
        };
        static void setTime();

};