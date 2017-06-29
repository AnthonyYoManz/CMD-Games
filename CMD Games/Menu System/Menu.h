//Class Name: Menu
//Author: Anthony Arian
//Role: Base menu class to be inherited from. Cannot be initialised

#ifndef ANT_MENU
#define ANT_MENU

#include <vector>	//std::vector
#include "MenuEntry.h"	//MenuObject

class MenuSystem;
class Printer;
class Input;
class Messenger;

class Menu
{
protected:
	//Collection of menu objects
	std::vector<MenuEntry*> objects;
	int selection;
	int width, height;
	int x, y;
public:
	virtual ~Menu() = default;

	/*Initialises the Menu. Called whenever a menu is added to the menu stack 
	in MenuSystem*/
	virtual void initialise() = 0;
	
	/*Cleans up the Menu. Called whenever a menu is removed from the menu stack 
	in MenuSystem*/
	virtual void cleanup();

	/*Draws the menu. */
	virtual void draw(Printer* _printer);
	
	/*Returns whatever it receives from MenuObject::activate(). Otherwise returns
	"NULL"*/
	virtual std::string update(Input* _input, Printer* _printer, Messenger* _messenger);

	/*Returns a Menu pointer to a new object of the provided type.*/
	template <typename t_Type> static Menu* createMenu()
	{
		return dynamic_cast<Menu*>(new t_Type);
	}
};

#endif