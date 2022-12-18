#pragma once
#include "mbed.h"
#include "CliMenu.h"


class ConsoleApp {
    private:
        CliMenu main_menu;
    public:
        ConsoleApp() : main_menu("Main menu") {};
        void start();
        
};