//Class Name: MenuEntry
//Author: Anthony Arian
//Role: Contains data used to draw and interact with menus

#ifndef ANT_MENU_ENTRY
#define ANT_MENU_ENTRY

#include <string> //std::string

class Menu;

class MenuEntry
{
private:
	//Name is printed to the screen
	std::string name;
	/*Link refers to which menu it should link to
	Exceptions are "NULL", "POP" and "RESET". 
	"NULL" causes nothing to happen when this object is activated
	"POP" tells the application to pop the menu stack, thereby exiting the current menu
	"RESET" tells the application to clear the menu stack and restart the initial menu*/
	std::string link;
public:
	MenuEntry(std::string _name, std::string _link = "NULL");
	
	/*Returns name*/
	std::string getName();
	
	/*Returns the link string*/
	virtual std::string activate();
};

#endif