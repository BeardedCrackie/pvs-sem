#include "CliMenu.h"
#include "SerialHandler.h"
#include <cstdio>
#include <iostream>
#include <format>
#include "LedController.h"

using namespace std;

void CliMenu::printMenu() {
    printf("\n\n=== %s ===\n", this->getName().c_str());
    for (int i = 0; i < this->menu_list.size(); i++) {
        printf("∟ %d: %s\n", i + 1, this->menu_list[i]->getName().c_str());
    }
    printf("∟ %s: %s\n", "e", "exit");
    printf("\n");
}

void CliMenu::addItem(MenuItem* item) {
    this->menu_list.push_back(item);
}

void CliMenu::selectItem() {
    bool selected = false;
    char choice;
    while (!selected) {
        lc_setState(info);
        this->printMenu();
        string s = "\n\nselect item from menu: ";
        printf("%s", s.c_str());
        choice = sh_readChar();
        printf("%s","\n\n");
        int c = (int)choice - (int)'0' - 1;
        if (c >= 0 && c < (int)this->menu_list.size()) {
            this->menu_list[c]->apply();
        } else if (choice == 'e') {
            return;
        } else {
          printf("\nWrong choice\n")  ;
        }
        ThisThread::sleep_for(500ms);
    }
}