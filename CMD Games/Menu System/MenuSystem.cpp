//Author: Anthony Arian

#include "MenuSystem.h"
#include "MenuFactory.h"
#include "Printer.h"
#include "Input.h"
#include "Messenger.h"

MenuSystem::MenuSystem()
{

}

MenuSystem::~MenuSystem()
{
	//Deletes leftover menus
	while (menus.size() != 0)
	{
		popMenu();
	}
}

void MenuSystem::initialise(MenuFactory* _factory, Printer* _printer, Input* _input,
							Messenger* _messenger, std::string _initialMenuName)
{
	factory = _factory;
	printer = _printer;
	input = _input;
	messenger = _messenger;

	Menu* initialMenu = factory->loadMenu(_initialMenuName);
	if (initialMenu)
	{
		running = true;
		pushMenu(initialMenu);
		initialMenuName = _initialMenuName;
	}
	else
	{
		running = false;
	}
}

bool MenuSystem::isRunning()
{
	return running;
}

void MenuSystem::popMenu()
{
	//Cleans up and deletes menu at the top of the menu stack
	if (menus.size() > 0)
	{
		menus.back()->cleanup();
		//If not deletable by the factory
		if (!factory->freeMenu(menus.back()))
		{
			//Just do it
			delete menus.back();
		}
		menus.pop_back();
		printer->clearConsole();
	}
	//If some menus still exist, draw them in order
	for (auto& i : menus)
	{
		i->draw(printer);
	}
	return;
}

void MenuSystem::pushMenu(Menu* menu)
{
	menu->initialise();
	menu->draw(printer);
	menus.push_back(menu);
	return;
}

void MenuSystem::update()
{
	input->update();
	if (input->checkInput(Key::ESCAPE))
	{
		popMenu();
	}
	else
	{
		std::string newMenuType = menus.back()->update(input, printer, messenger);
		if (newMenuType != "NULL")
		{
			if (newMenuType == "POP")
			{
				popMenu();
			}
			else if (newMenuType == "RESET")
			{
				while (menus.size() != 0)
				{
					popMenu();
				}
				Menu* initialMenu = factory->loadMenu(initialMenuName);
				if (initialMenu)
				{
					pushMenu(initialMenu);
				}
				else
				{
					running = false;
				}
			}
			else{
				Menu* newMenu = factory->loadMenu(newMenuType);
				if (newMenu)
				{
					pushMenu(newMenu);
				}
			}
		}
	}
	if (menus.size() == 0)
	{
		running = false;
	}
	else
	{
		printer->clearConsole();
		for (auto& i : menus)
		{
			i->draw(printer);
		}
		printer->display();
	}
	return;
}