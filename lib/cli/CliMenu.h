#pragma once
#include "mbed.h"
#include <iostream>
#include "SerialHandler.h"
#include <vector>
#include "MenuItem.h"
#include <string>


using namespace std::chrono;

class CliMenu: public MenuItem {
        vector<MenuItem*> menu_list;
    public:
        CliMenu(string menu_name) : MenuItem(menu_name) {
            this->menu_list = vector<MenuItem*>();
        };
        void printMenu();
        void addItem(MenuItem* item);
        void selectItem();
        void apply() override {
            //this->printMenu();
            this->selectItem();
        }; 
}; 