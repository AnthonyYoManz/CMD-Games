#include "MenuFactory.h"
#include "MainMenu.h"

MenuFactory::~MenuFactory()
{
	freeAll();
}

Menu* MenuFactory::loadMenu(std::string _menuName)
{
	Creators& element = creatorMap[_menuName];
	if (element.funcPtr)
	{
		return element.funcPtr();
	}
	return nullptr;
}

bool MenuFactory::freeMenu(std::string _menuName)
{
	if (menuMap.count(_menuName))
	{
		delete menuMap[_menuName];
		menuMap.erase(_menuName);
		return true;
	}
	return false;
}

bool MenuFactory::freeMenu(Menu* _menuPtr)
{
	//Check whether or not a creator function with the given name actually exists
	for (auto& i : menuMap)
	{
		if (i.second == _menuPtr)
		{
			//If so then delete it and erase its entry on the map
			delete i.second;
			menuMap.erase(i.first);
			return true;
		}
	}
	return false;
}

void MenuFactory::freeAll()
{
	for (auto& i : menuMap)
	{
		delete i.second;
	}
	menuMap.clear();
}

bool MenuFactory::registerMenuType(std::string _name, Menu* (*_func)())
{
	if (creatorMap.count(_name))
	{
		return false;
	}
	creatorMap[_name].funcPtr = _func;
	return true;
}