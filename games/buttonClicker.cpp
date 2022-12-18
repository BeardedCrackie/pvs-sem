#include "buttonClicker.h"

//init
InterruptIn button(PC_13);
int pushed_count = 0;

/*
 * function handled by interrupt
 */
void buttonPushed() {
    pushed_count++;
}

/*
 * start the game with guidance
 */
void ButtonClicker::startGame() {

    // init
    lc_setState(prepare);
    pushed_count = 0;

    // game introduction and manual
    AuxFunctions::aux_println("\n=== Welcome in game of clicking, welcome in ButtonClicker ===\n");
    ThisThread::sleep_for(DELAY);
    AuxFunctions::aux_println("The rules are simple: Make the most click count with user button by specified time");
    ThisThread::sleep_for(DELAY);
    AuxFunctions::aux_println("The game starts with first click on the user button, keep clicking till screen print TIME OVER");
    ThisThread::sleep_for(DELAY);
    AuxFunctions::aux_println("Redy yourself and click the button\n");

    // game started
    button.rise(&buttonPushed); // attach function on button interupt
    while(pushed_count == 0) {  // wait till actually button is pushed
        ThisThread::sleep_for(10ms);
    }
    lc_setState(running);
    ThisThread::sleep_for(CONTEST_TIME);
    lc_setState(info);

    // game conclusion
    AuxFunctions::aux_println("\nTIME OVER");
    ThisThread::sleep_for(DELAY);
    AuxFunctions::aux_print("You made: ");
    AuxFunctions::aux_print(to_string(pushed_count));
    AuxFunctions::aux_print(" clicks\n");
}



