//Program Name: Console Lightbot
//Author: Anthony Arian
//Role: Contains App object (see App.h)

#include "ConsoleApp.h"
#include "MainMenu.h"
#include "DifficultyMenu.h"

int main(int argc, char** argv)
{
	//Creates the menu factory and registers menu creation functions
	ConsoleApp app;
	app.getFactory().registerMenuType("MainMenu", Menu::createMenu<MainMenu>);
	app.getFactory().registerMenuType("DifficultyMenu", Menu::createMenu<DifficultyMenu>);

	//Loads in the initial menu
	app.initialise("MainMenu");
	while (app.isRunning())
	{
		app.update();
	}
	return 0;
}