#pragma once
#include "mbed.h"
#include "CliMenu.h"
#include "SerialHandler.h"
#include "auxFunctions.h"
#include "LedController.h"
#include "buttonClicker.h"

/*
 * class represents console application
 */
class ConsoleApp {
    private:
        CliMenu main_menu;
    public:
        ConsoleApp() : main_menu("Main menu") {};
        void Start(); 
};

