//Class Name: MainMenu
//Author: Anthony Arian
//Role: Inherits from Menu. First menu that is displayed to the user featuring 
//		main navigation features and a quit option.

#ifndef ANT_MAIN_MENU
#define ANT_MAIN_MENU

#include <string>	//std::string
#include "Menu.h"	//Menu


class MainMenu : public Menu
{
public:
	~MainMenu() = default;

	/*Initialises the Menu*/
	void initialise();

	/*Draws the menu*/
	void draw(Printer* _printer);

	/*Updates the menu*/
	std::string update(Input* _input, Printer* _printer, Messenger* _messenger);
};

#endif