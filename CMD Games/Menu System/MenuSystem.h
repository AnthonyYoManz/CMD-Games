//Class Name: App
//Author: Anthony Arian
//Role: Contain and control the application's systems

#ifndef ANT_MENU_SYSTEM
#define ANT_MENU_SYSTEM

#include <vector>
#include <string>
#include "Menu.h"

class MenuFactory;
class Printer;
class Input;
class Messenger;

class MenuSystem
{
private:
	bool running;
	std::string initialMenuName;
	//The menu stack
	std::vector<Menu*> menus;
	MenuFactory* factory;
	Printer* printer;
	Input* input;
	Messenger* messenger;
public:
	MenuSystem();
	
	~MenuSystem();

	void initialise(MenuFactory* _factory, Printer* _printer, Input* _input,
		Messenger* _messenger, std::string _initialMenuName);
	
	/*Returns true if the application is running*/
	bool isRunning();

	/*Adds menu to the end of the menu stack*/
	void pushMenu(Menu* _newMenu);

	/*Removes the menu at the top of the menu stack*/
	void popMenu();

	/*Updates the MenuSystem*/
	void update();
};

#endif