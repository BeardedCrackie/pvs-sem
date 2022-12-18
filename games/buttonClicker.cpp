#include "buttonClicker.h"

InterruptIn button(PC_13);
int pushed_count = 0;

void buttonPushed() {
    pushed_count++;
}

void ButtonClicker::startGame() {
    lc_setState(prepare);
    pushed_count = 0;
    AuxFunctions::aux_println("\n=== Welcome in game of clicking, welcome in ButtonClicker ===\n");
    ThisThread::sleep_for(DELAY);
    AuxFunctions::aux_println("The rules are simple: Make the most click count with user button by specified time");
    ThisThread::sleep_for(DELAY);
    AuxFunctions::aux_println("The game starts with first click on the user button, keep clicking till screen print TIME OVER");
    ThisThread::sleep_for(DELAY);
    AuxFunctions::aux_println("Redy yourself and click the button\n");
    button.rise(&buttonPushed);  // attach the address of the flip function to the rising edge
    while(pushed_count == 0) {
        ThisThread::sleep_for(10ms);
    }
    lc_setState(running);
    ThisThread::sleep_for(CONTEST_TIME);
    lc_setState(info);
    AuxFunctions::aux_println("\nTIME OVER");
    ThisThread::sleep_for(DELAY);
    AuxFunctions::aux_print("You made: ");
    AuxFunctions::aux_print(to_string(pushed_count));
    AuxFunctions::aux_print(" clicks\n");
}



