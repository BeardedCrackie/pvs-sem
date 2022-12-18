#pragma once
#include <iostream>
#include <string>
#include "LedController.h"

using namespace std;
typedef void (*callback_function)(void); // type for conciseness

class MenuItem {
    protected:
        string name;
    public: 
        MenuItem(string name) {
            this->name = name;
        };
        virtual void apply() = 0;
        string getName() {
            return this->name;
        }; 
};

class MenuSimpleItem : public MenuItem {
    public:
        MenuSimpleItem(string name) : MenuItem(name) {};
        virtual void apply() override{
            lc_setState(prepare);
            printf("\n\n=== %s ===\n\n", this->getName().c_str());
            ThisThread::sleep_for(2s);
            lc_setState(running);
            ThisThread::sleep_for(5s);
        }; 
};

class MenuActionItem : public MenuItem {
    private:
        callback_function action_function;
    public:
        MenuActionItem(string name, callback_function action_function) : MenuItem(name) {
            this->action_function = action_function;
        };
        virtual void apply() override{
            action_function();
        }; 
};