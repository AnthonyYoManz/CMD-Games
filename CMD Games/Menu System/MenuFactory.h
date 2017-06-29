//Class Name: MenuFactory
//Author: Anthony Arian
//Role: Centralised place to generate new menus

#ifndef ANT_MENU_FACTORY
#define ANT_MENU_FACTORY

#include <vector>	//std::vector
#include <map>		//std::map
#include <string>	//std::string
#include "Menu.h"	//Menu

class MenuFactory
{
private:
	/*Struct to make sure all function pointers are intialised to nullptr*/
	struct Creators
	{
		Menu*(*funcPtr)();
		Creators()
		{
			funcPtr = nullptr;
		}
	};

	/*Map with strings for keys and pointers to functions that return pointers to
	newly created Menus. Said Menu*s get stored in menuMap to be cleaned up when
	they expire. Everything in this map is kept until MenuFactory is destroyed*/
	//whose idea even was this
	std::map<std::string, Creators> creatorMap;
	
	/*Stores pointers to all created Menus*/
	std::map<std::string, Menu*> menuMap;
public:
	MenuFactory() = default;
	
	 ~MenuFactory();
	
	/*Returns a pointer to new menu, returns nullptr on error*/
	Menu* loadMenu(std::string _menuName);

	/*Frees the menu with the provided name from memory. Returns false if the name
	is not in use. Returns true on success*/
	bool freeMenu(std::string _menuName);

	/*Same as above but checks via memory address rather than name*/
	bool freeMenu(Menu* _menuPtr);

	/*Frees all menus within the Menu map*/
	void freeAll();

	/*Adds the creator function for the provided menu type under the provided name.
	Returns true on success and false if the name is already in use*/
	bool registerMenuType(std::string _menuName, Menu* (*_func)());
};

#endif