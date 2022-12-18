#include "ConsoleApp.h"

void dummy_function() {
    AuxFunctions::aux_println("Game #1");
}

void ConsoleApp::start() {

    // game ButtonClicker
    CliMenu gameButtonClicker("Button Clicker");
    gameButtonClicker.addItem(new MenuActionItem("Start Game", &ButtonClicker::startGame));

    // game submenu
    CliMenu game_menu("Browse Games");
    game_menu.addItem(&gameButtonClicker);
    game_menu.addItem(new MenuActionItem("Game 1", &dummy_function));
    game_menu.addItem(new MenuSimpleItem("Game 2"));

    // settings submenu
    CliMenu settings_menu("Settings");
    settings_menu.addItem(new MenuActionItem("Print time", &AuxFunctions::printTime));
    settings_menu.addItem(new MenuActionItem("Set time", &AuxFunctions::setTime));

    // main menu
    this->main_menu.addItem(&game_menu);
    this->main_menu.addItem(&settings_menu);
    
    // start
    this->main_menu.apply();
}