#include "ConsoleApp.h"
#include "LedController.h"
#include "auxFunctions.h"

void ConsoleApp::start() {

    CliMenu game_menu("Browse Games");
    game_menu.addItem(new MenuActionItem("Print time", &aux_print));
    game_menu.addItem(new MenuSimpleItem("Game 2"));
    game_menu.addItem(new MenuSimpleItem("Game 3"));
    game_menu.addItem(new MenuSimpleItem("Game 4"));

    CliMenu settings_menu("Settings");

    this->main_menu.addItem(&game_menu);
    this->main_menu.addItem(&settings_menu);
    
    this->main_menu.apply();

}