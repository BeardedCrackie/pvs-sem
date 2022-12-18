#include "ConsoleApp.h"

/*
 * function to use as exemplary item
 */
void dummy_function() {
    AuxFunctions::aux_println("Game #1");
}

/*
 * init main menu and items, then start cli application
 */
void ConsoleApp::Start() {

    // game ButtonClicker
    CliMenu gameButtonClicker("Button Clicker");
    gameButtonClicker.AddItem(new MenuActionItem("Start Game", &ButtonClicker::startGame));

    // game submenu
    CliMenu game_menu("Browse Games");
    game_menu.AddItem(&gameButtonClicker);
    game_menu.AddItem(new MenuActionItem("Game 1", &dummy_function));
    game_menu.AddItem(new MenuSimpleItem("Game 2"));

    // settings submenu
    CliMenu settings_menu("Settings");
    settings_menu.AddItem(new MenuActionItem("Print time", &AuxFunctions::printTime));
    settings_menu.AddItem(new MenuActionItem("Set time", &AuxFunctions::setTime));
    settings_menu.AddItem(new MenuActionItem("LED test", &lc_testLed));

    // main menu
    this->main_menu.AddItem(&game_menu);
    this->main_menu.AddItem(&settings_menu);
    
    // start
    this->main_menu.apply();
}