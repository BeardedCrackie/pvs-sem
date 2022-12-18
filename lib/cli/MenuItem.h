#pragma once
#include <iostream>
#include <string>
#include "LedController.h"

using namespace std;
typedef void (*callback_function)(void); // type for conciseness

/*
 * abstract class used as template for menu items
 */
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

/*
 * class used for simple menu items with only name provided
 */
class MenuSimpleItem : public MenuItem {
    public:
        MenuSimpleItem(string name) : MenuItem(name) {};
        virtual void apply() override{
            lc_setState(prepare);
            ThisThread::sleep_for(2s);
            printf("\n\n=== %s ===\n\n", this->getName().c_str());
            lc_setState(running);
            ThisThread::sleep_for(5s);
        }; 
};

/*
 * class used for menu items that points to function
 */
class MenuActionItem : public MenuItem {
    private:
        callback_function action_function;
        callback_function prepare_function;
    public:
        MenuActionItem(string name, callback_function action_function) : MenuItem(name) {
            this->action_function = action_function;
            this->prepare_function = nullptr;
        };
        MenuActionItem(string name, callback_function action_function, callback_function prepare_function) : MenuItem(name) {
            this->action_function = action_function;
            this->prepare_function = prepare_function;
        };
        virtual void apply() override{
            lc_setState(prepare);
            if (prepare_function != nullptr) {
                prepare_function();
            }

            lc_setState(running);
            action_function();
        }; 
};