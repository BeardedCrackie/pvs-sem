#pragma once
#include "mbed.h"
#include <iostream>
#include "SerialHandler.h"
#include <vector>
#include "MenuItem.h"
#include <string>

/*
 * class represents menu item in console application
 */
class CliMenu: public MenuItem {
    private:
        vector<MenuItem*> menu_list;
    public:
        CliMenu(string menu_name) : MenuItem(menu_name) {
            this->menu_list = vector<MenuItem*>();
        };
        void PrintMenu();
        void AddItem(MenuItem* item);
        void SelectItem();
        void apply() override {
            this->SelectItem();
        }; 
}; 